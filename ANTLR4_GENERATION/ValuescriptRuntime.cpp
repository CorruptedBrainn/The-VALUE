#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <fstream>

#include "..\generated\ValuescriptLexer.h"
#include "..\generated\ValuescriptParser.h"
#include "ValuescriptParserBaseVisitor.h"

#pragma warning (disable : 6398)

using namespace valuescriptantlrgeneration;
using namespace antlr4;
using namespace std;

struct VSType {
	string name = "NULL";
	vector<VSType*> children;
	VSType() { name = "NULL"; }
	VSType(string name) {
		this->name = name;
	}
	~VSType() {
		for (VSType* child : children) delete[] child;
	}
	void addChild(VSType child) {
		children.push_back(new VSType(child));
	}
};

// Strict equality check on name
inline bool operator==(const VSType& lhs, const VSType& rhs) {
	if (lhs.name != rhs.name || lhs.children.size() != rhs.children.size()) return false;
	for (int i = 0; i < lhs.children.size(); i++) {
		if (lhs.children[i] != rhs.children[i]) return false;
	}
	return true;
}

// Strict inequality check on name
inline bool operator!=(const VSType& lhs, const VSType& rhs) {
	return !(lhs == rhs);
}

class VSImporter {
private:
	ANTLRInputStream* input;
	ValuescriptLexer* lexer;
	CommonTokenStream* tokens;
	ValuescriptParser* parser;
public:
	tree::ParseTree* tree;
	VSImporter(string file) {
		input = new ANTLRInputStream(file);
		lexer = new ValuescriptLexer(input);
		tokens = new CommonTokenStream(lexer);
		parser = new ValuescriptParser(tokens);
		tree = parser->file();
	}

	~VSImporter() {
		delete[] input;
		delete[] lexer;
		delete[] tokens;
		delete[] parser;
	}
};

struct VSVariable {
	bool isconst = false;
	string name = "NULL";
	VSType type;
	any value = NULL;
};

struct VSFunction {
	set<string> templates = {};
	string name = "NULL";
	vector<VSVariable> parameters = {};
	VSType returntype;
	ValuescriptParser::CodeblockContext* callable = nullptr;
};

struct VSClass {
	set<string> templates = {};
	string name = "NULL";
	ValuescriptParser::CodeblockContext* contents = nullptr;
};

class VSStaticScope {
private:
	unordered_map<string, VSStaticScope*> children = {};
	unordered_map<string, VSVariable> variableStorage = {};
	unordered_map<string, VSVariable> constantStorage = {};
	unordered_map<string, VSFunction> functionStorage = {};
	unordered_map<string, VSClass> classStorage = {};
public:
	string name = "GLOBAL";

	VSStaticScope() { name = "GLOBAL"; }
	VSStaticScope(string name) {
		this->name = name;
		return;
	}

	~VSStaticScope() {
		if (&children == nullptr) return;
		for (pair<string, VSStaticScope*> child : children) {
			if (child.second != nullptr) delete[] child.second;
		}
		return;
	}

	bool contains(string name) {
		return variableStorage.contains(name) || constantStorage.contains(name);
	}

	void addChildScope(string scope) {
		if (children.contains(scope)) return; // ERROR
		children[scope] = new VSStaticScope(scope);
		return;
	}

	VSStaticScope* getChildScope(string name) {
		if (this->name == name) return this;
		auto scope = children.find(name);
		if (scope == children.end()) {
			return nullptr; // ERROR
		}
		return (*scope).second;
	}

	void declareVariable(VSVariable var) {
		if (contains(var.name)) return; // ERROR
		if (var.isconst) constantStorage[var.name] = var;
		else variableStorage[var.name] = var;
		return;
	}

	VSVariable* getVariable(string name) {
		auto var = variableStorage.find(name);
		auto con = constantStorage.find(name);
		if (var != variableStorage.end()) return &(*var).second;
		if (con != constantStorage.end()) return &(*con).second;
		return nullptr; // ERROR
	}

	void declareFunction(VSFunction func) {
		if (functionStorage.contains(func.name)) return; // ERROR
		functionStorage[func.name] = func;
		return;
	}

	VSFunction* getFunction(string name) {
		auto func = functionStorage.find(name);
		if (func == functionStorage.end()) return nullptr; // ERROR
		return &(*func).second;
	}

	void declareClass(VSClass cls) {
		if (classStorage.contains(cls.name)) return; // ERROR
		classStorage[cls.name] = cls;
		return;
	}

	VSClass* getClass(string name) {
		auto cls = classStorage.find(name);
		if (cls == classStorage.end()) return nullptr; // ERROR
		return &(*cls).second;
	}
};

class VSLocalScope {
private:
	unordered_map<string, VSVariable> variableStorage = {};
	unordered_map<string, VSVariable> constantStorage = {};
	VSStaticScope* staticScope = nullptr;
	VSLocalScope* parentScope = nullptr;

	bool contains(string name) {
		return variableStorage.contains(name) || constantStorage.contains(name);
	}

	VSLocalScope* search(string name) {
		if (contains(name) || staticScope->contains(name)) return this;
		if (parentScope == nullptr) return nullptr; // ERROR
		return parentScope->search(name);
	}
public:
	VSLocalScope(VSLocalScope* parent = nullptr, VSStaticScope* inherit = nullptr) {
		parentScope = parent;
		staticScope = inherit;
		return;
	}

	void declareVariable(VSVariable var) {
		if (contains(var.name)) return; // ERROR
		if (var.isconst) constantStorage[var.name] = var;
		else variableStorage[var.name] = var;
		return;
	}

	VSVariable* getVariable(string name) {
		VSLocalScope* env = search(name);
		if (env == nullptr) return nullptr;
		auto var = env->variableStorage.find(name);
		auto con = env->constantStorage.find(name);
		if (var != env->variableStorage.end()) return &(*var).second;
		if (con != env->constantStorage.end()) return &(*con).second;
		return env->staticScope->getVariable(name);
	}

	VSFunction* getFunction(string name) {
		VSFunction* ret = staticScope->getFunction(name);
		if (ret != nullptr) return ret;
		if (parentScope == nullptr) return nullptr; // ERROR
		return parentScope->getFunction(name);
	}

	VSClass* getClass(string name) {
		VSClass* ret = staticScope->getClass(name);
		if (ret != nullptr) return ret;
		if (parentScope == nullptr) return nullptr; // ERROR
		return parentScope->getClass(name);
	}
};

/// <summary>
///	Code in this object is executed when the parse tree is constructed
/// For example, imports are loaded and classes / functions are initialised
/// </summary>
class ValuescriptPreVisitor : public ValuescriptParserBaseVisitor {
public:
	stack<VSStaticScope*> scoping;
	vector<pair<string, VSImporter*>> imports;
	VSStaticScope globalScope;
	ValuescriptPreVisitor() {};

	any visitFile(ValuescriptParser::FileContext* ctx) override {
		scoping.push(&globalScope);
		for (auto import : ctx->extra()) imports.push_back(any_cast<pair<string, VSImporter*>>(visit(import)));
		for (auto statement : ctx->statement()) visit(statement);
		scoping.pop();
		return defaultResult();
	}

	any visitExtra(ValuescriptParser::ExtraContext* ctx) override {
		string import = ctx->IDENTIFIER()->getText();
		string script = "", tempstorage;
		string name = "../ValuescriptImports/" + import + ".vssf";
		ifstream file(name);
		while (getline(file, tempstorage)) {
			script += tempstorage;
		}
		file.close();
		VSImporter* library = new VSImporter(script);
		visit(library->tree);
		return pair<string, VSImporter*>(import, library);
	}

	any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext* ctx) override {
		if (ctx->STATIC().size() == 0) return defaultResult();
		VSVariable var;
		var.isconst = ctx->CONSTANT().size();
		var.name = ctx->IDENTIFIER()->getText();
		var.type = any_cast<VSType>(visit(ctx->typenameexpression()));
		var.value = defaultResult();
		scoping.top()->declareVariable(var);
		return defaultResult();
	}
	
	any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext* ctx) override {
		string name = ctx->IDENTIFIER()->getText();
		scoping.top()->addChildScope(name);
		scoping.push(scoping.top()->getChildScope(name));
		visit(ctx->codeblock());
		scoping.pop();
		VSFunction func;
		if (ctx->templatedeclaration() != nullptr) {
			func.templates = any_cast<set<string>>(visit(ctx->templatedeclaration()));
		}
		func.name = name;
		func.parameters = any_cast<vector<VSVariable>>(visit(ctx->functionparameters()));
		func.returntype = any_cast<VSType>(visit(ctx->typenameexpression()));
		func.callable = ctx->codeblock();
		scoping.top()->declareFunction(func);
		return defaultResult();
	}

	any visitFunctionparameters(ValuescriptParser::FunctionparametersContext* ctx) override {
		vector<VSVariable> ret;
		for (auto param : ctx->variabledeclaration()) {
			VSVariable var;
			var.name = param->IDENTIFIER()->getText();
			var.type = any_cast<VSType>(visit(param->typenameexpression()));
			ret.push_back(var);
		}
		return ret;
	}

	any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx) override {
		string name = ctx->IDENTIFIER()->getText();
		scoping.top()->addChildScope(name);
		scoping.push(scoping.top()->getChildScope(name));
		visit(ctx->codeblock());
		scoping.pop();
		VSClass cls;
		cls.templates = any_cast<set<string>>(visit(ctx->templatedeclaration()));
		cls.name = name;
		cls.contents = ctx->codeblock();
		scoping.top()->declareClass(cls);
		return defaultResult();
	}

	any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx) override {
		unordered_set<string> ret;
		for (auto type : ctx->IDENTIFIER()) ret.insert(type->getText());
		return ret;
	}

	any visitTyinteger(ValuescriptParser::TyintegerContext* ctx) override {
		return VSType("int");
	}

	any visitTydouble(ValuescriptParser::TydoubleContext* ctx) override {
		return VSType("double");
	}

	any visitTystring(ValuescriptParser::TystringContext* ctx) override {
		return VSType("str");
	}

	any visitTyboolean(ValuescriptParser::TybooleanContext* ctx) override {
		return VSType("bool");
	}

	any visitTyident(ValuescriptParser::TyidentContext* ctx) override {
		return VSType(ctx->IDENTIFIER()->getText());
	}

	any visitTynested(ValuescriptParser::TynestedContext* ctx) override {
		VSType ty(ctx->IDENTIFIER()->getText());
		for (auto expr : ctx->typenameexpression()) ty.addChild(any_cast<VSType>(visit(expr)));
		return ty;
	}
};

/// <summary>
/// Code in this object is executed within each execution cycle
/// For example, printing would occur here
/// </summary>
class ValuescriptVisitor : public ValuescriptParserBaseVisitor {
private:
	ValuescriptPreVisitor* storage = nullptr; // TODO: IMPORTS
	stack<string> staticName = {};
	int task = 0;
public:
	stack<VSLocalScope*> scoping = {};
	ValuescriptVisitor(ValuescriptPreVisitor* storage) {
		this->storage = storage;
	}

	any visitFile(ValuescriptParser::FileContext* ctx) override { /// statement EOF
		staticName.push("GLOBAL");
		scoping.push(new VSLocalScope(nullptr, &storage->globalScope));
		vector<ValuescriptParser::StatementContext*> tovisit = ctx->statement();
		any ret = defaultResult();
		for (auto curr : tovisit) {
			any temp = visit(curr);
			if (task == 1) {
				task = 0;
				ret = temp;
				break;
			}
		}
		scoping.pop();
		staticName.pop();
		return ret; // Child Type
	}

	any visitStatementprint(ValuescriptParser::StatementprintContext* ctx) override { /// DBGOUT ( expression ) ;
		any expr = visit(ctx->expression());
		try
		{
			int print = any_cast<int>(expr); // THIS IS TEMPORY, ASSUME INTEGER I HATE STD::ANY SO MUCH OMFG
			cout << "int: " << print << endl;
		}
		catch (bad_any_cast ex) {

		}
		try
		{
			VSVariable* print = any_cast<VSVariable*>(expr); // THIS IS TEMPORY, ASSUME INTEGER I HATE STD::ANY SO MUCH OMFG
			cout << "Variable: " << any_cast<int>(print->value) << endl;
		}
		catch (bad_any_cast ex) {

		}
		return expr;
	}

	any visitStatementret(ValuescriptParser::StatementretContext* ctx) override { /// RETURN expression
		any ret = visit(ctx->expression());
		task = 1;
		return ret; // Child Type
	}

	any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext* ctx) override { /// IDENTIFIER -> typenameexpression = expression
		if (ctx->STATIC().size() == 0) {
			VSVariable var;
			var.isconst = ctx->CONSTANT().size();
			var.name = ctx->IDENTIFIER()->getText();
			var.type = any_cast<VSType>(visit(ctx->typenameexpression())); // Assume type VSType
			var.value = visit(ctx->expression());
			scoping.top()->declareVariable(var);
			return var.value; // Child Type
		}
		VSVariable* var = scoping.top()->getVariable(ctx->IDENTIFIER()->getText());
		if (!var->value.has_value()) var->value = visit(ctx->expression());
		return defaultResult();
	}

	any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext* ctx) override {
		return defaultResult();
	}

	any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx) override {
		return defaultResult();
	}

	any visitTemplateexpression(ValuescriptParser::TemplateexpressionContext* ctx) override { /// template -> typenames(s) ;
		vector<VSType> ret;
		vector<ValuescriptParser::TypenameexpressionContext*> tovisit = ctx->typenameexpression();
		for (auto curr : tovisit) ret.push_back(any_cast<VSType>(visit(curr)));
		return ret;
	}

	any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx) override { /// typenames: IDENTIFIER(s)
		vector<string> ret;
		vector<antlr4::tree::TerminalNode*> tovisit = ctx->IDENTIFIER();
		for (auto curr : tovisit) ret.push_back(curr->getText());
		return ret; // Array of Strings
	}

	any visitTyinteger(ValuescriptParser::TyintegerContext* ctx) override {
		return VSType("int"); // Valuescript Type
	}

	any visitTydouble(ValuescriptParser::TydoubleContext* ctx) override {
		return VSType("double"); // Valuescript Type
	}

	any visitTystring(ValuescriptParser::TystringContext* ctx) override {
		return VSType("str"); // Valuescript Type
	}

	any visitTyboolean(ValuescriptParser::TybooleanContext* ctx) override {
		return VSType("bool"); // Valuescript Type
	}

	any visitTyident(ValuescriptParser::TyidentContext* ctx) override {
		return VSType(ctx->IDENTIFIER()->getText()); // Valuescript Type
	}

	any visitTynested(ValuescriptParser::TynestedContext* ctx) override { /// IDENTIFIER < typenameexpression >
		VSType ty(ctx->IDENTIFIER()->getText());
		vector<ValuescriptParser::TypenameexpressionContext*> tovisit = ctx->typenameexpression();
		for (auto curr : tovisit) ty.addChild(any_cast<VSType>(visit(curr))); // Assume type VSType
		return ty; // Valuescript Type
	}

	any visitIfstatement(ValuescriptParser::IfstatementContext* ctx) override { /// if ( expression ) { codeblock }
		if (any_cast<bool>(visit(ctx->expression()))) return visit(ctx->codeblock(0)); // Assume type Boolean
		else if (ctx->ELSE() != nullptr) {
			if (ctx->codeblock().size() > 1) return visit(ctx->codeblock(1));
			else return visit(ctx->ifstatement()); // Child Type
		}
		else return defaultResult(); // Emptiness
	}

	any visitWhilestatement(ValuescriptParser::WhilestatementContext* ctx) override { /// while ( expression ) { codeblock }
		any ret = defaultResult();
		while (any_cast<bool>(visit(ctx->expression()))) { // Assume type Boolean
			ret = visit(ctx->codeblock());
		}
		return ret; // Child Type
	}

	any visitDostatement(ValuescriptParser::DostatementContext* ctx) override { /// do { codeblock } while ( expression )
		any ret = visit(ctx->codeblock());
		while (any_cast<bool>(visit(ctx->expression()))) { // Assume type Boolean
			ret = visit(ctx->codeblock());
		}
		return ret; // Child Type
	}

	any visitRangefor(ValuescriptParser::RangeforContext* ctx) override { /// for ( variabledeclaration ; expression ; expression ) { codeblock }
		scoping.push(new VSLocalScope(scoping.top(), storage->globalScope.getChildScope(staticName.top())));
		any ret = defaultResult();
		vector<ValuescriptParser::VariabledeclarationContext*> tovisit = ctx->variabledeclaration();
		for (auto curr : tovisit) visit(curr);
		vector<ValuescriptParser::ExpressionContext*> expr = ctx->expression();
		auto cond = expr[0];
		while (any_cast<bool>(visit(cond))) { // Assume type Boolean
			ret = visit(ctx->codeblock());
			for (int i = 1; i < expr.size(); i++) visit(expr[i]);
		}
		return ret;
	}

	any visitItemfor(ValuescriptParser::ItemforContext* ctx) override { /// for ( variabledeclaration : expression ) { codeblock }
		// Get name and type of variable
		// Get looping object
		scoping.push(new VSLocalScope(scoping.top(), storage->globalScope.getChildScope(staticName.top())));
		ValuescriptParser::VariabledeclarationContext* decl = ctx->variabledeclaration();
		VSVariable* expr = any_cast<VSVariable*>(visit(ctx->expression())); // Assume type VS Variable
		any ret = defaultResult();
		VSType declty = any_cast<VSType>(visit(decl->typenameexpression())); // Assume type VSType
		VSType exprty = expr->type;
		if (declty != exprty) {
			scoping.pop();
			return ret; // Emptiness
		}
		VSVariable var;
		var.isconst = false;
		var.name = decl->IDENTIFIER()->getText();
		var.type = declty;
		var.value = visit(decl->expression());
		scoping.top()->declareVariable(var);
		// The fuck???
		scoping.pop();
		return ret;
	}

	any visitCodeblock(ValuescriptParser::CodeblockContext* ctx) override { /// { statement }
		scoping.push(new VSLocalScope(scoping.top(), storage->globalScope.getChildScope(staticName.top())));
		vector<ValuescriptParser::StatementContext*> tovisit = ctx->statement();
		any ret = defaultResult();
		for (auto curr : tovisit) {
			any temp = visit(curr);
			if (task == 1) {
				ret = temp;
				break;
			}
		}
		scoping.pop();
		return ret; // Child Type
	}

	any visitNotexpr(ValuescriptParser::NotexprContext* ctx) override { /// ! expression
		any rhs = visit(ctx->expression());
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (bool* test = any_cast<bool>(&rhs)) {
			bool r = *test;
			return !r;
		}
		return defaultResult(); // Error
	}

	any visitMultexpr(ValuescriptParser::MultexprContext* ctx) override { /// expression multiplicativeoperator expression
		string op = ctx->multiplicativeoperator()->getText();
		any lhs = visit(ctx->expression(0));
		any rhs = visit(ctx->expression(1));
		if (lhs.type() == typeid(VSVariable*)) {
			lhs = any_cast<VSVariable*>(lhs)->value;
		}
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (lhs.type() != rhs.type()) return defaultResult(); // Error
		if (int* test = any_cast<int>(&lhs)) {
			int l = *test, r = any_cast<int>(rhs);
			if (op == "*") return l * r;
			if (op == "/") return l / r;
			if (op == "%") return l % r;
			return defaultResult(); // Error
		}
		if (double* test = any_cast<double>(&lhs)) {
			double l = *test, r = any_cast<double>(rhs);
			if (op == "*") return l * r;
			if (op == "/") return l / r;
			return defaultResult(); // Error
		}
		return defaultResult(); // Error
	}

	any visitIncexpr(ValuescriptParser::IncexprContext* ctx) override { /// expression incrementaloperator
		string op = ctx->incrementaloperator()->getText();
		VSVariable* lhs = any_cast<VSVariable*>(visit(ctx->expression())); // Assume VS Variable
		if (lhs->isconst) return lhs->value;
		// Do checks for class types
		if (lhs->type == VSType("int")) {
			int l = any_cast<int>(lhs->value);
			if (op == "++") return lhs->value = ++l;
			if (op == "--") return lhs->value = --l;
			return defaultResult(); // Error
		}
		if (lhs->type == VSType("double")) {
			double l = any_cast<double>(lhs->value);
			if (op == "++") return lhs->value = ++l;
			if (op == "--") return lhs->value = --l;
			return defaultResult(); // Error
		}
		return defaultResult(); // Error
	}

	any visitCompexpr(ValuescriptParser::CompexprContext* ctx) override { /// expression comparisonoperator expression
		string op = ctx->comparisonoperator()->getText();
		any lhs = visit(ctx->expression(0));
		any rhs = visit(ctx->expression(1));
		if (lhs.type() == typeid(VSVariable*)) {
			lhs = any_cast<VSVariable*>(lhs)->value;
		}
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (lhs.type() != rhs.type()) return defaultResult(); // Error
		if (int* test = any_cast<int>(&lhs)) {
			int l = *test, r = any_cast<int>(rhs);
			if (op == "==") return l == r;
			if (op == "<") return l < r;
			if (op == ">") return l > r;
			if (op == "<=") return l <= r;
			if (op == ">=") return l >= r;
			if (op == "!=") return l != r;
			return defaultResult(); // Error
		}
		if (double* test = any_cast<double>(&lhs)) {
			double l = *test, r = any_cast<double>(rhs);
			if (op == "==") return l == r;
			if (op == "<") return l < r;
			if (op == ">") return l > r;
			if (op == "<=") return l <= r;
			if (op == ">=") return l >= r;
			if (op == "!=") return l != r;
			return defaultResult(); // Error
		}
		if (bool* test = any_cast<bool>(&lhs)) {
			bool l = *test, r = any_cast<bool>(rhs);
			if (op == "==") return l == r;
			if (op == "<") return l < r;
			if (op == ">") return l > r;
			if (op == "<=") return l <= r;
			if (op == ">=") return l >= r;
			if (op == "!=") return l != r;
			return defaultResult(); // Error
		}
		if (string* test = any_cast<string>(&lhs)) {
			string l = *test, r = any_cast<string>(rhs);
			if (op == "==") return l == r;
			if (op == "<") return l < r;
			if (op == ">") return l > r;
			if (op == "<=") return l <= r;
			if (op == ">=") return l >= r;
			if (op == "!=") return l != r;
			return defaultResult(); // Error
		}
		return defaultResult(); // Error
	}

	any visitAddexpr(ValuescriptParser::AddexprContext* ctx) override { /// expression additiveoperator expression
		string op = ctx->additiveoperator()->getText();
		any lhs = visit(ctx->expression(0));
		any rhs = visit(ctx->expression(1));
		if (lhs.type() == typeid(VSVariable*)) {
			lhs = any_cast<VSVariable*>(lhs)->value;
		}
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (lhs.type() != rhs.type()) return defaultResult(); // Error
		if (int* test = any_cast<int>(&lhs)) {
			int l = *test, r = any_cast<int>(rhs);
			if (op == "+") return l + r;
			if (op == "-") return l - r;
			return defaultResult(); // Error
		}
		if (double* test = any_cast<double>(&lhs)) {
			double l = *test, r = any_cast<double>(rhs);
			if (op == "+") return l + r;
			if (op == "-") return l - r;
			return defaultResult(); // Error
		}
		if (bool* test = any_cast<bool>(&lhs)) {
			bool l = *test, r = any_cast<bool>(rhs);
			if (op == "+") return l + r;
			if (op == "-") return l - r;
			return defaultResult(); // Error
		}
		if (string* test = any_cast<string>(&lhs)) {
			string l = *test, r = any_cast<string>(rhs);
			if (op == "+") return l + r;
			return defaultResult(); // Error
		}
		return defaultResult(); // Error
	}

	any visitObjexpr(ValuescriptParser::ObjexprContext* ctx) override { /// { expression }
		return visitChildren(ctx); // Child Type
	}

	any visitMembexpr(ValuescriptParser::MembexprContext* ctx) override { /// expression . expression // vs class
		return visitChildren(ctx); // Valuescript Variable / Function / Class
	}

	any visitAssignexpr(ValuescriptParser::AssignexprContext* ctx) override { /// expression assignmentoperator expression
		string op = ctx->assignmentoperator()->getText();
		VSVariable* lhs = any_cast<VSVariable*>(visit(ctx->expression(0))); // Assume VS Variable
		if (lhs->isconst) return lhs->value;
		any val = visit(ctx->expression(1));
		VSVariable var;
		if (val.type() != typeid(VSVariable*)) {
			var.type = VSType(val.type().name());
			var.value = val;
			val = &var;
		}
		// Do checks for class types
		VSVariable* rhs = any_cast<VSVariable*>(val);
		if (lhs->type != rhs->type) return defaultResult(); // Error
		if (op == "=") return lhs->value = rhs->value;
		if (lhs->type == VSType("int")) {
			int l = any_cast<int>(lhs->value), r = any_cast<int>(rhs->value);
			if (op == "+=") return lhs->value = l + r;
			if (op == "-=") return lhs->value = l - r;
			if (op == "*=") return lhs->value = l * r;
			if (op == "/=") return lhs->value = l / r;
			if (op == "%=") return lhs->value = l % r;
			return defaultResult(); // Error
		}
		if (lhs->type == VSType("double")) {
			double l = any_cast<double>(lhs->value), r = any_cast<double>(rhs->value);
			if (op == "+=") return lhs->value = l + r;
			if (op == "-=") return lhs->value = l - r;
			if (op == "*=") return lhs->value = l * r;
			if (op == "/=") return lhs->value = l / r;
			return defaultResult(); // Error
		}
		if (lhs->type == VSType("str")) {
			string l = any_cast<string>(lhs->value), r = any_cast<string>(rhs->value);
			if (op == "+=") return lhs->value = l + r;
			return defaultResult(); // Error
		}
		return defaultResult(); // Error
	}

	any visitBinexpr(ValuescriptParser::BinexprContext* ctx) override { /// expression binaryoperator expression
		string op = ctx->binaryoperator()->getText();
		any lhs = visit(ctx->expression(0));
		any rhs = visit(ctx->expression(1));
		if (lhs.type() == typeid(VSVariable*)) {
			lhs = any_cast<VSVariable*>(lhs)->value;
		}
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (lhs.type() != rhs.type()) return defaultResult(); // Error
		if (int* test = any_cast<int>(&lhs)) {
			int l = *test, r = any_cast<int>(rhs);
			if (op == "&") return l & r;
			if (op == "|") return l | r;
			if (op == "^") return l ^ r;
			return defaultResult(); // Error
		}
		if (bool* test = any_cast<bool>(&lhs)) {
			bool l = *test, r = any_cast<bool>(rhs);
			if (op == "&") return l & r;
			if (op == "|") return l | r;
			if (op == "^") return l ^ r;
			return defaultResult(); // Error
		}
		return defaultResult(); // Error
	}

	any visitBoolexpr(ValuescriptParser::BoolexprContext* ctx) override { /// expression booleanoperator expression
		string op = ctx->booleanoperator()->getText();
		any lhs = visit(ctx->expression(0));
		any rhs = visit(ctx->expression(1));
		if (lhs.type() == typeid(VSVariable*)) {
			lhs = any_cast<VSVariable*>(lhs)->value;
		}
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (lhs.type() != rhs.type() || lhs.type().name() != "bool") return defaultResult(); // Error
		bool l = any_cast<bool>(lhs);
		bool r = any_cast<bool>(rhs);
		if (op == "&&") return l && r; // Boolean
		if (op == "||") return l || r; // Boolean
		return defaultResult(); // Error
	}

	any visitParenexpr(ValuescriptParser::ParenexprContext* ctx) override { /// expression ( expression ) // vs func
		scoping.push(new VSLocalScope(scoping.top(), storage->globalScope.getChildScope(staticName.top())));
		VSFunction* callable = any_cast<VSFunction*>(visit(ctx->expression(0))); // Assume VS Func
		vector<ValuescriptParser::ExpressionContext*> params = ctx->expression();
		staticName.push(callable->name);
		any ret = defaultResult();
		for (int i = 0; i < callable->parameters.size(); i++) {
			VSVariable var = callable->parameters[i];
			var.value = visit(params[i + 1]);
			if (var.value.type() == typeid(VSVariable*)) var.value = any_cast<VSVariable*>(var.value)->value;
			scoping.top()->declareVariable(var);
		}
		ret = visit(callable->callable);
		task = 0;
		staticName.pop();
		scoping.pop();
		return ret; // Child Type
	}

	any visitTyparexpr(ValuescriptParser::TyparexprContext* ctx) override { /// Template expression ( expression ) // vs func
		scoping.push(new VSLocalScope(scoping.top(), storage->globalScope.getChildScope(staticName.top())));
		VSFunction* callable = any_cast<VSFunction*>(visit(ctx->expression(0))); // Assume VS Func
		vector<VSType> templates = any_cast<vector<VSType>>(visit(ctx->templateexpression())); // Assume VS Type
		vector<ValuescriptParser::ExpressionContext*> params = ctx->expression();
		staticName.push(callable->name);
		any ret = defaultResult();
		for (int i = 1; i < params.size(); i++) {
			VSVariable var = callable->parameters[i];
			var.value = visit(params[i]);
			if (var.value.type() == typeid(VSVariable*)) var.value = any_cast<VSVariable*>(var.value)->value;
			auto it = callable->templates.find(var.type.name);
			if (it != callable->templates.end()) {
				var.type = templates[distance(callable->templates.begin(), it)];
			}
			scoping.top()->declareVariable(var);
		}
		ret = visit(callable->callable);
		staticName.pop();
		scoping.pop();
		return ret; // Child Type
	}

	any visitAccessexpr(ValuescriptParser::AccessexprContext* ctx) override { /// expression [ expression ] // vs var
		return visitChildren(ctx); // TODO
	}

	any visitIdent(ValuescriptParser::IdentContext* ctx) override {
		string ident = ctx->IDENTIFIER()->getText();
		VSVariable* var = scoping.top()->getVariable(ident);
		if (var != nullptr) {
			return var; // Valuescript Variable
		}
		VSFunction* func = scoping.top()->getFunction(ident);
		if (func != nullptr) {
			return func; // Valuescript Function
		}
		return scoping.top()->getClass(ident); // Valuescript Class
	}

	any visitDecimal(ValuescriptParser::DecimalContext* ctx) override {
		return stod(ctx->FLOATING_LITERAL()->getText()); // Double
	}

	any visitNumber(ValuescriptParser::NumberContext* ctx) override {
		return stoi(ctx->INTEGER_LITERAL()->getText()); // Integer
	}

	any visitTrue(ValuescriptParser::TrueContext* ctx) override {
		return true; // Boolean
	}

	any visitFalse(ValuescriptParser::FalseContext* ctx) override {
		return false; // Boolean
	}

	any visitString(ValuescriptParser::StringContext* ctx) override {
		string str = ctx->STRING_LITERAL()->getText();
		str.erase(str.begin());
		str.erase(str.end() - 1);
		return str; // String
	}

	any visitOrder(ValuescriptParser::OrderContext* ctx) override {
		return visit(ctx->expression()); // Child Type
	}
};