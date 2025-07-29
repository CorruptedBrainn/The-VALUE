/// Author: Nicolas Martens
/// Name: ValuescriptRuntime.cpp
/// Description: The file that contains the Valuescript source code, and tells the visitor how to behave during execution

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

/// <summary>
/// A structure defining an internal Valuescript Type
/// </summary>
struct VSType {
	string name = "NULL";
	vector<VSType*> children;
	/// <summary>
	/// Create a new VS Type
	/// </summary>
	VSType() { name = "NULL"; }
	/// <summary>
	/// Create a new VS Type with the given name
	/// </summary>
	/// <param name="name">The name of the type</param>
	VSType(string name) {
		this->name = name;
	}
	/// <summary>
	/// Delete the type
	/// </summary>
	~VSType() {
		for (VSType* child : children) delete[] child;
	}
	/// <summary>
	/// Add a child type
	/// </summary>
	/// <param name="child">The child type</param>
	void addChild(VSType child) {
		children.push_back(new VSType(child));
	}
};

/// <summary>
/// An operator overload, allowing me to compare two Valuescript types with strict equality
/// </summary>
/// <param name="lhs">First comparator</param>
/// <param name="rhs">Second comparator</param>
/// <returns>True or False</returns>
inline bool operator==(const VSType& lhs, const VSType& rhs) {
	if (lhs.name != rhs.name || lhs.children.size() != rhs.children.size()) return false;
	for (int i = 0; i < lhs.children.size(); i++) {
		if (lhs.children[i] != rhs.children[i]) return false;
	}
	return true;
}

/// <summary>
/// Operator overloading checking if two VS types are strictly not equal
/// </summary>
/// <param name="lhs">First comparator</param>
/// <param name="rhs">Second comparator</param>
/// <returns>True or False</returns>
inline bool operator!=(const VSType& lhs, const VSType& rhs) {
	return !(lhs == rhs);
}

/// <summary>
/// A class holding an import that loads Valuescript modules
/// </summary>
class VSImporter {
private:
	// The ANTLR4 classes storing the program
	ANTLRInputStream* input;
	ValuescriptLexer* lexer;
	CommonTokenStream* tokens;
	ValuescriptParser* parser;
public:
	/// <summary>
	/// Create the program and takes the program text, turning it into an Abstract Syntax Tree, then visiting it to deal with static data
	/// </summary>
	/// <param name="file">The contents of the Valuescript Program as a string</param>
	tree::ParseTree* tree;
	VSImporter(string file) {
		input = new ANTLRInputStream(file);
		lexer = new ValuescriptLexer(input);
		tokens = new CommonTokenStream(lexer);
		parser = new ValuescriptParser(tokens);
		tree = parser->file();
	}

	/// <summary>
	/// Delete the pointers we have to avoid memory leaks
	/// </summary>
	~VSImporter() {
		delete[] input;
		delete[] lexer;
		delete[] tokens;
		delete[] parser;
	}
};

/// <summary>
/// A struct to internally store a user created variable
/// </summary>
struct VSVariable {
	bool isconst = false;
	string name = "NULL";
	VSType type;
	any value = NULL;
};

/// <summary>
/// A struct to internally store a user created function
/// </summary>
struct VSFunction {
	set<string> templates = {};
	string name = "NULL";
	vector<VSVariable> parameters = {};
	VSType returntype;
	ValuescriptParser::CodeblockContext* callable = nullptr;
};

/// <summary>
/// A struct to internally store a user created class
/// </summary>
struct VSClass {
	set<string> templates = {};
	string name = "NULL";
	ValuescriptParser::CodeblockContext* contents = nullptr;
};

/// <summary>
/// Valuescript scopes that live on the static level, for static variables, and functions / classes
/// </summary>
class VSStaticScope {
private:
	// The storage from within the scope
	unordered_map<string, VSStaticScope*> children = {};
	unordered_map<string, VSVariable> variableStorage = {};
	unordered_map<string, VSVariable> constantStorage = {};
	unordered_map<string, VSFunction> functionStorage = {};
	unordered_map<string, VSClass> classStorage = {};
public:
	// Scope name
	string name = "GLOBAL";

	/// <summary>
	/// Initialise with the default name
	/// </summary>
	VSStaticScope() { name = "GLOBAL"; }
	/// <summary>
	/// Initialise with the given name
	/// </summary>
	/// <param name="name">The name for the scope</param>
	VSStaticScope(string name) {
		this->name = name;
		return;
	}

	/// <summary>
	/// Delete the scope and children
	/// </summary>
	~VSStaticScope() {
		if (&children == nullptr) return;
		for (pair<string, VSStaticScope*> child : children) {
			if (child.second != nullptr) delete[] child.second;
		}
		return;
	}

	/// <summary>
	/// Check if there is already a variable with the given name
	/// </summary>
	/// <param name="name">The variable to check for</param>
	/// <returns>A boolean value representing if the variable exists</returns>
	bool contains(string name) {
		return variableStorage.contains(name) || constantStorage.contains(name);
	}

	/// <summary>
	/// Add a child static scope
	/// </summary>
	/// <param name="scope">The name of the child scope to add</param>
	void addChildScope(string scope) {
		if (children.contains(scope)) return; // ERROR
		children[scope] = new VSStaticScope(scope);
		return;
	}

	/// <summary>
	/// Get the child scope with the given name
	/// </summary>
	/// <param name="name">The name of the scope to check for</param>
	/// <returns>A pointer pointing to the child scope</returns>
	VSStaticScope* getChildScope(string name) {
		if (this->name == name) return this;
		auto scope = children.find(name);
		if (scope == children.end()) {
			return nullptr; // ERROR
		}
		return (*scope).second;
	}

	/// <summary>
	/// Declare a new static variable within the current scope
	/// </summary>
	/// <param name="var">The Valuescript Variable to declare</param>
	void declareVariable(VSVariable var) {
		if (contains(var.name)) return; // ERROR
		if (var.isconst) constantStorage[var.name] = var;
		else variableStorage[var.name] = var;
		return;
	}

	/// <summary>
	/// Get the variable within the current scope with the given name
	/// </summary>
	/// <param name="name">The name of the variable to check for</param>
	/// <returns>A pointer pointing to the variable</returns>
	VSVariable* getVariable(string name) {
		auto var = variableStorage.find(name);
		auto con = constantStorage.find(name);
		if (var != variableStorage.end()) return &(*var).second;
		if (con != constantStorage.end()) return &(*con).second;
		return nullptr; // ERROR
	}

	/// <summary>
	/// Declare a new function within the current scope
	/// </summary>
	/// <param name="func">The Valuescript Function to declare</param>
	void declareFunction(VSFunction func) {
		if (functionStorage.contains(func.name)) return; // ERROR
		functionStorage[func.name] = func;
		return;
	}

	/// <summary>
	/// Get the function within the current scope with the given name
	/// </summary>
	/// <param name="name">The name of the function to check for</param>
	/// <returns>A pointer pointing to the function</returns>
	VSFunction* getFunction(string name) {
		auto func = functionStorage.find(name);
		if (func == functionStorage.end()) return nullptr; // ERROR
		return &(*func).second;
	}

	/// <summary>
	/// Declare a new class within the current scope
	/// </summary>
	/// <param name="cls">The Valuescript Class to declare</param>
	void declareClass(VSClass cls) {
		if (classStorage.contains(cls.name)) return; // ERROR
		classStorage[cls.name] = cls;
		return;
	}

	/// <summary>
	/// Get the class within the current scope with the given name
	/// </summary>
	/// <param name="name">The name of the class to check for</param>
	/// <returns>A pointer pointing to the class</returns>
	VSClass* getClass(string name) {
		auto cls = classStorage.find(name);
		if (cls == classStorage.end()) return nullptr; // ERROR
		return &(*cls).second;
	}
};

/// <summary>
/// The class storing regular scopes for function execution
/// </summary>
class VSLocalScope {
private:
	// Storages for parent, static scopes and for variables
	unordered_map<string, VSVariable> variableStorage = {};
	unordered_map<string, VSVariable> constantStorage = {};
	VSStaticScope* staticScope = nullptr;
	VSLocalScope* parentScope = nullptr;

	/// <summary>
	/// Check if there is already a variable with the given name
	/// </summary>
	/// <param name="name">The variable to check for</param>
	/// <returns>A boolean value representing if the variable exists</returns>
	bool contains(string name) {
		return variableStorage.contains(name) || constantStorage.contains(name);
	}

	/// <summary>
	/// Search for a variable with the given name across current and parent scopes
	/// </summary>
	/// <param name="name">The variable to check for</param>
	/// <returns>A pointer pointing to the scope where the variable lives</returns>
	VSLocalScope* search(string name) {
		if (contains(name) || staticScope->contains(name)) return this;
		if (parentScope == nullptr) return nullptr; // ERROR
		return parentScope->search(name);
	}
public:
	/// <summary>
	/// Initialise a new scope
	/// </summary>
	/// <param name="parent">The parent scope to initialise with</param>
	/// <param name="inherit">The static counterpart scope to initialise with</param>
	VSLocalScope(VSLocalScope* parent = nullptr, VSStaticScope* inherit = nullptr) {
		parentScope = parent;
		staticScope = inherit;
		return;
	}

	/// <summary>
	/// Declaring a new variable at runtime
	/// </summary>
	/// <param name="var">The Variable to declare</param>
	void declareVariable(VSVariable var) {
		if (contains(var.name)) return; // ERROR
		if (var.isconst) constantStorage[var.name] = var;
		else variableStorage[var.name] = var;
		return;
	}

	/// <summary>
	/// Getting a variable at runtime
	/// </summary>
	/// <param name="name">The name of the variable</param>
	/// <returns>A pointer pointing to the variable</returns>
	VSVariable* getVariable(string name) {
		VSLocalScope* env = search(name);
		if (env == nullptr) return nullptr;
		auto var = env->variableStorage.find(name);
		auto con = env->constantStorage.find(name);
		if (var != env->variableStorage.end()) return &(*var).second;
		if (con != env->constantStorage.end()) return &(*con).second;
		return env->staticScope->getVariable(name);
	}

	/// <summary>
	/// Getting a function at runtime
	/// </summary>
	/// <param name="name">The name of the function</param>
	/// <returns>A pointer pointing to the function</returns>
	VSFunction* getFunction(string name) {
		VSFunction* ret = staticScope->getFunction(name);
		if (ret != nullptr) return ret;
		if (parentScope == nullptr) return nullptr; // ERROR
		return parentScope->getFunction(name);
	}

	/// <summary>
	/// Getting a class at runtime
	/// </summary>
	/// <param name="name">The name of the class</param>
	/// <returns>A pointer pointing to the class</returns>
	VSClass* getClass(string name) {
		VSClass* ret = staticScope->getClass(name);
		if (ret != nullptr) return ret;
		if (parentScope == nullptr) return nullptr; // ERROR
		return parentScope->getClass(name);
	}
};

/// <summary>
///	A wrapper telling the visitor what to do when performing parse-time checks, such as defining functions and classes
/// </summary>
class ValuescriptPreVisitor : public ValuescriptParserBaseVisitor {
public:
	// Global data
	stack<VSStaticScope*> scoping;
	vector<pair<string, VSImporter*>> imports;
	VSStaticScope globalScope;
	ValuescriptPreVisitor() {};

	/// <summary>
	/// The main parse rule for entry and exit, will visit all imports then all statements
	/// </summary>
	/// <param name="ctx">extra* statement+ EOF</param>
	/// <returns>Default Result</returns>
	any visitFile(ValuescriptParser::FileContext* ctx) override {
		scoping.push(&globalScope);
		for (auto import : ctx->extra()) imports.push_back(any_cast<pair<string, VSImporter*>>(visit(import)));
		for (auto statement : ctx->statement()) visit(statement);
		scoping.pop();
		return defaultResult();
	}
	
	/// <summary>
	/// The parse rule used for imports, will load the import then visit the contents inside
	/// </summary>
	/// <param name="ctx">IMPORT IDENTIFIER SEMICOLON?</param>
	/// <returns>A pair storing the import name and contents</returns>
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

	/// <summary>
	/// The parse rule used for variable declarations, will declare and store a static variable without a value
	/// </summary>
	/// <param name="ctx">(STATIC | VARIABLE)* IDENTIFIER ARROW_OPERATOR typenameexpression</param>
	/// <param name="ctx">(STATIC | VARIABLE | CONSTANT)* IDENTIFIER ARROW_OPERATOR typenameexpression ASSIGNMENT_GENERIC expression</param>
	/// <returns>Default Result</returns>
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
	
	/// <summary>
	/// The parse rule used for function declarations, will store information about a function
	/// </summary>
	/// <param name="ctx">templatedeclaration? FUNCTION? IDENTIFIER functionparameters ARROW_OPERATOR typenameexpression codeblock</param>
	/// <returns>Default Result</returns>
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

	/// <summary>
	/// The parse rule used for function parameters, will get the function parameters as a list
	/// </summary>
	/// <param name="ctx">OPEN_PARENTHESES variabledeclaration? (COMMA variabledeclaration)* CLOSED_PARENTHESES</param>
	/// <returns>A vector of Valuescript Variables</returns>
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

	/// <summary>
	/// The parse rule used for class declarations, will declare and store the class contents
	/// </summary>
	/// <param name="ctx">templatedeclaration? CLASS? IDENTIFIER codeblock</param>
	/// <returns>Default Result</returns>
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

	/// <summary>
	/// The parse rule used for template declarations, will get the names of the templates
	/// </summary>
	/// <param name="ctx">TYPENAMES COLON IDENTIFIER (COMMA IDENTIFIER)*</param>
	/// <returns>A vector of strings with the template names</returns>
	any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx) override {
		unordered_set<string> ret;
		for (auto type : ctx->IDENTIFIER()) ret.insert(type->getText());
		return ret;
	}

	/// <summary>
	/// The parse rule used for the int typename
	/// </summary>
	/// <param name="ctx">INTEGER</param>
	/// <returns>A Valuescript Integer type</returns>
	any visitTyinteger(ValuescriptParser::TyintegerContext* ctx) override {
		return VSType("int");
	}

	/// <summary>
	/// The parse rule used for the double typename
	/// </summary>
	/// <param name="ctx">DOUBLE</param>
	/// <returns>A Valuescript Double type</returns>
	any visitTydouble(ValuescriptParser::TydoubleContext* ctx) override {
		return VSType("double");
	}

	/// <summary>
	/// The parse rule used for the string typename
	/// </summary>
	/// <param name="ctx">STRING</param>
	/// <returns>A Valuescript String type</returns>
	any visitTystring(ValuescriptParser::TystringContext* ctx) override {
		return VSType("str");
	}

	/// <summary>
	/// The parse rule used for the boolean typename
	/// </summary>
	/// <param name="ctx">BOOLEAN</param>
	/// <returns>A Valuescript Boolean type</returns>
	any visitTyboolean(ValuescriptParser::TybooleanContext* ctx) override {
		return VSType("bool");
	}

	/// <summary>
	/// The parse rule used for the pair typename
	/// </summary>
	/// <param name="ctx">PAIR OPEN_ANGLE_BRACKET typenameexpression COMMA typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Pair type</returns>
	any visitTypair(ValuescriptParser::TypairContext* ctx) override {
		VSType ty("pair");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(0))));
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(1))));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the array typename
	/// </summary>
	/// <param name="ctx">ARRAY OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Array type</returns>
	any visitTyarray(ValuescriptParser::TyarrayContext* ctx) override {
		VSType ty("array");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the list typename
	/// </summary>
	/// <param name="ctx">ORD_LIST OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript List type</returns>
	any visitTyset(ValuescriptParser::TysetContext* ctx) override {
		VSType ty("list");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the map typename
	/// </summary>
	/// <param name="ctx">ORD_MAP OPEN_ANGLE_BRACKET typenameexpression COMMA typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Map type</returns>
	any visitTymap(ValuescriptParser::TymapContext* ctx) override {
		VSType ty("map");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(0))));
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(1))));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the hash list typename
	/// </summary>
	/// <param name="ctx">HASH_LIST OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Hashlist type</returns>
	any visitTyuset(ValuescriptParser::TyusetContext* ctx) override {
		VSType ty("hashlist");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the hash map typename
	/// </summary>
	/// <param name="ctx">HASH_MAP OPEN_ANGLE_BRACKET typenameexpression COMMA typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Hashmap type</returns>
	any visitTyumap(ValuescriptParser::TyumapContext* ctx) override {
		VSType ty("hashmap");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(0))));
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(1))));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the stack typename
	/// </summary>
	/// <param name="ctx">STACK OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Stack type</returns>
	any visitTystack(ValuescriptParser::TystackContext* ctx) override {
		VSType ty("stack");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the queue typename
	/// </summary>
	/// <param name="ctx">QUEUE OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Queue type</returns>
	any visitTyqueue(ValuescriptParser::TyqueueContext* ctx) override {
		VSType ty("queue");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the deque typename
	/// </summary>
	/// <param name="ctx">DEQUE OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Deque type</returns>
	any visitTydeque(ValuescriptParser::TydequeContext* ctx) override {
		VSType ty("deque");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the priority queue typename
	/// </summary>
	/// <param name="ctx">PRIOR_QUE OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Priority Queue type</returns>
	any visitTyprior(ValuescriptParser::TypriorContext* ctx) override {
		VSType ty("priority_queue");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for custom typenames
	/// </summary>
	/// <param name="ctx">IDENTIFIER</param>
	/// <returns>A Valuescript type</returns>
	any visitTyident(ValuescriptParser::TyidentContext* ctx) override {
		return VSType(ctx->IDENTIFIER()->getText());
	}

	/// <summary>
	/// The parse rule used for custom typenames
	/// </summary>
	/// <param name="ctx">IDENTIFIER OPEN_ANGLE_BRACKET typenameexpression (COMMA typenameexpression)* CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript type</returns>
	any visitTynested(ValuescriptParser::TynestedContext* ctx) override {
		VSType ty(ctx->IDENTIFIER()->getText());
		for (auto expr : ctx->typenameexpression()) ty.addChild(any_cast<VSType>(visit(expr)));
		return ty;
	}
};

/// <summary>
/// A wrapper telling the program how to behave at execution time
/// </summary>
class ValuescriptVisitor : public ValuescriptParserBaseVisitor {
private:
	// Some data from parse-time
	ValuescriptPreVisitor* storage = nullptr;
	stack<string> staticName = {};
	int task = 0;
public:
	// The scopes for coding
	stack<VSLocalScope*> scoping = {};

	/// <summary>
	/// Initialise the class with a pre-visitor as base data
	/// </summary>
	/// <param name="storage">The pointer to the pre-visitor</param>
	ValuescriptVisitor(ValuescriptPreVisitor* storage) {
		this->storage = storage;
	}

	/// <summary>
	/// The parse rule used for the start and end of the program, will ignore all import statements
	/// </summary>
	/// <param name="ctx">extra* statement+ EOF</param>
	/// <returns>The return value, if any, of the program</returns>
	any visitFile(ValuescriptParser::FileContext* ctx) override {
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
		return ret;
	}

	/// <summary>
	/// The parse rule used to print values to the console, will visit the expression but does nothing with invalid type
	/// </summary>
	/// <param name="ctx">DBGOUT OPEN_PARENTHESES expression CLOSED_PARENTHESES SEMICOLON</param>
	/// <returns>The expression visited</returns>
	any visitStatementprint(ValuescriptParser::StatementprintContext* ctx) override {
		any expr = visit(ctx->expression());
		try {
			// Variable
			expr = any_cast<VSVariable*>(expr)->value;
		}
		catch (bad_any_cast ex) {}
		try {
			// Integer
			cout << any_cast<int>(expr);
		}
		catch (bad_any_cast ex) {}
		try {
			// Double
			cout << any_cast<double>(expr);
		}
		catch (bad_any_cast ex) {}
		try {
			// String
			cout << any_cast<string>(expr);
		}
		catch (bad_any_cast ex) {}
		try {
			// Boolean
			cout << any_cast<bool>(expr);
		}
		catch (bad_any_cast ex) {}
		return expr;
	}

	/// <summary>
	/// The parse rule for return statements
	/// </summary>
	/// <param name="ctx">RETURN expression? SEMICOLON</param>
	/// <returns>Returns the expression visited</returns>
	any visitStatementret(ValuescriptParser::StatementretContext* ctx) override {
		any ret = defaultResult();
		if (ctx->expression() != nullptr) {
			ret = visit(ctx->expression());
		}
		task = 1;
		return ret; 
	}

	/// <summary>
	/// The parse rule for variable declarations, will ignore all static variables with a value
	/// </summary>
	/// <param name="ctx">(STATIC | VARIABLE)* IDENTIFIER ARROW_OPERATOR typenameexpression</param>
	/// <param name="ctx">(STATIC | VARIABLE | CONSTANT)* IDENTIFIER ARROW_OPERATOR typenameexpression ASSIGNMENT_GENERIC expression</param>
	/// <returns>The value of the variable, if assigned</returns>
	any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext* ctx) override {
		if (ctx->STATIC().size() == 0) {
			VSVariable var;
			var.isconst = ctx->CONSTANT().size();
			var.name = ctx->IDENTIFIER()->getText();
			var.type = any_cast<VSType>(visit(ctx->typenameexpression()));
			var.value = visit(ctx->expression());
			scoping.top()->declareVariable(var);
			return var.value;
		}
		VSVariable* var = scoping.top()->getVariable(ctx->IDENTIFIER()->getText());
		if (!var->value.has_value()) var->value = visit(ctx->expression());
		return defaultResult();
	}

	/// <summary>
	/// The parse rule for a function declaration, will ignore the body
	/// </summary>
	/// <param name="ctx">templatedeclaration? FUNCTION? IDENTIFIER functionparameters ARROW_OPERATOR typenameexpression codeblock</param>
	/// <returns>Default Result</returns>
	any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext* ctx) override {
		return defaultResult();
	}

	/// <summary>
	/// The parse rule for a class declaration, will ignore the body
	/// </summary>
	/// <param name="ctx">templatedeclaration? CLASS? IDENTIFIER codeblock</param>
	/// <returns>Default Result</returns>
	any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx) override {
		return defaultResult();
	}

	/// <summary>
	/// The parse rule for a variable template, will process recursively
	/// </summary>
	/// <param name="ctx">TEMPLATE ARROW_OPERATOR typenameexpression (COMMA typenameexpression)* SEMICOLON?</param>
	/// <returns>A vector of Valuescript types</returns>
	any visitTemplateexpression(ValuescriptParser::TemplateexpressionContext* ctx) override {
		vector<VSType> ret;
		vector<ValuescriptParser::TypenameexpressionContext*> tovisit = ctx->typenameexpression();
		for (auto curr : tovisit) ret.push_back(any_cast<VSType>(visit(curr)));
		return ret;
	}

	/// <summary>
	/// The parse rule for a template declaration, will get the template list
	/// </summary>
	/// <param name="ctx">TYPENAMES COLON IDENTIFIER (COMMA IDENTIFIER)*</param>
	/// <returns>An array of strings</returns>
	any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx) override {
		vector<string> ret;
		vector<antlr4::tree::TerminalNode*> tovisit = ctx->IDENTIFIER();
		for (auto curr : tovisit) ret.push_back(curr->getText());
		return ret;
	}

	/// <summary>
	/// The parse rule used for the int typename
	/// </summary>
	/// <param name="ctx">INTEGER</param>
	/// <returns>A Valuescript Integer type</returns>
	any visitTyinteger(ValuescriptParser::TyintegerContext* ctx) override {
		return VSType("int");
	}

	/// <summary>
	/// The parse rule used for the double typename
	/// </summary>
	/// <param name="ctx">DOUBLE</param>
	/// <returns>A Valuescript Double type</returns>
	any visitTydouble(ValuescriptParser::TydoubleContext* ctx) override {
		return VSType("double");
	}

	/// <summary>
	/// The parse rule used for the string typename
	/// </summary>
	/// <param name="ctx">STRING</param>
	/// <returns>A Valuescript String type</returns>
	any visitTystring(ValuescriptParser::TystringContext* ctx) override {
		return VSType("str");
	}

	/// <summary>
	/// The parse rule used for the boolean typename
	/// </summary>
	/// <param name="ctx">BOOLEAN</param>
	/// <returns>A Valuescript Boolean type</returns>
	any visitTyboolean(ValuescriptParser::TybooleanContext* ctx) override {
		return VSType("bool");
	}

	/// <summary>
	/// The parse rule used for the pair typename
	/// </summary>
	/// <param name="ctx">PAIR OPEN_ANGLE_BRACKET typenameexpression COMMA typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Pair type</returns>
	any visitTypair(ValuescriptParser::TypairContext* ctx) override {
		VSType ty("pair");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(0))));
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(1))));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the array typename
	/// </summary>
	/// <param name="ctx">ARRAY OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Array type</returns>
	any visitTyarray(ValuescriptParser::TyarrayContext* ctx) override {
		VSType ty("array");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the list typename
	/// </summary>
	/// <param name="ctx">ORD_LIST OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript List type</returns>
	any visitTyset(ValuescriptParser::TysetContext* ctx) override {
		VSType ty("list");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the map typename
	/// </summary>
	/// <param name="ctx">ORD_MAP OPEN_ANGLE_BRACKET typenameexpression COMMA typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Map type</returns>
	any visitTymap(ValuescriptParser::TymapContext* ctx) override {
		VSType ty("map");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(0))));
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(1))));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the hash list typename
	/// </summary>
	/// <param name="ctx">HASH_LIST OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Hashlist type</returns>
	any visitTyuset(ValuescriptParser::TyusetContext* ctx) override {
		VSType ty("hashlist");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the hash map typename
	/// </summary>
	/// <param name="ctx">HASH_MAP OPEN_ANGLE_BRACKET typenameexpression COMMA typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Hashmap type</returns>
	any visitTyumap(ValuescriptParser::TyumapContext* ctx) override {
		VSType ty("hashmap");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(0))));
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression(1))));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the stack typename
	/// </summary>
	/// <param name="ctx">STACK OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Stack type</returns>
	any visitTystack(ValuescriptParser::TystackContext* ctx) override {
		VSType ty("stack");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the queue typename
	/// </summary>
	/// <param name="ctx">QUEUE OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Queue type</returns>
	any visitTyqueue(ValuescriptParser::TyqueueContext* ctx) override {
		VSType ty("queue");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the deque typename
	/// </summary>
	/// <param name="ctx">DEQUE OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Deque type</returns>
	any visitTydeque(ValuescriptParser::TydequeContext* ctx) override {
		VSType ty("deque");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for the priority queue typename
	/// </summary>
	/// <param name="ctx">PRIOR_QUE OPEN_ANGLE_BRACKET typenameexpression CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript Priority Queue type</returns>
	any visitTyprior(ValuescriptParser::TypriorContext* ctx) override {
		VSType ty("priority_queue");
		ty.addChild(any_cast<VSType>(visit(ctx->typenameexpression())));
		return ty;
	}

	/// <summary>
	/// The parse rule used for custom typenames
	/// </summary>
	/// <param name="ctx">IDENTIFIER</param>
	/// <returns>A Valuescript type</returns>
	any visitTyident(ValuescriptParser::TyidentContext* ctx) override {
		return VSType(ctx->IDENTIFIER()->getText());
	}

	/// <summary>
	/// The parse rule used for custom typenames
	/// </summary>
	/// <param name="ctx">IDENTIFIER OPEN_ANGLE_BRACKET typenameexpression (COMMA typenameexpression)* CLOSED_ANGLE_BRACKET</param>
	/// <returns>A Valuescript type</returns>
	any visitTynested(ValuescriptParser::TynestedContext* ctx) override {
		VSType ty(ctx->IDENTIFIER()->getText());
		for (auto expr : ctx->typenameexpression()) ty.addChild(any_cast<VSType>(visit(expr)));
		return ty;
	}

	/// <summary>
	/// The parse rule for an if statement, will execute code blocks based on conditionals
	/// </summary>
	/// <param name="ctx">IF OPEN_PARENTHESES expression CLOSED_PARENTHESES codeblock (ELSE (codeblock | ifstatement))?</param>
	/// <returns>The return value of the executed code block</returns>
	any visitIfstatement(ValuescriptParser::IfstatementContext* ctx) override {
		if (any_cast<bool>(visit(ctx->expression()))) return visit(ctx->codeblock(0));
		else if (ctx->ELSE() != nullptr) {
			if (ctx->codeblock().size() > 1) return visit(ctx->codeblock(1));
			else return visit(ctx->ifstatement());
		}
		else return defaultResult();
	}

	/// <summary>
	/// The parse rule for a while statement, will execute the code block while the conditional is true
	/// </summary>
	/// <param name="ctx">WHILE OPEN_PARENTHESES expression CLOSED_PARENTHESES codeblock</param>
	/// <returns>The return value of the latest execution</returns>
	any visitWhilestatement(ValuescriptParser::WhilestatementContext* ctx) override {
		any ret = defaultResult();
		while (any_cast<bool>(visit(ctx->expression()))) {
			ret = visit(ctx->codeblock());
		}
		return ret;
	}

	/// <summary>
	/// The parse rule for a do statement, will execute the code block then continue while the conditional is true
	/// </summary>
	/// <param name="ctx">DO codeblock WHILE OPEN_PARENTHESES expression CLOSED_PARENTHESES</param>
	/// <returns>The return value of the latest execution</returns>
	any visitDostatement(ValuescriptParser::DostatementContext* ctx) override {
		any ret = visit(ctx->codeblock());
		while (any_cast<bool>(visit(ctx->expression()))) {
			ret = visit(ctx->codeblock());
		}
		return ret;
	}

	/// <summary>
	/// The parse rule for a for loop based on a range
	/// </summary>
	/// <param name="ctx">FOR OPEN_PARENTHESES variabledeclaration (COMMA variabledeclaration)* SEMICOLON expression SEMICOLON expression (COMMA expression)* CLOSED_PARENTHESES codeblock</param>
	/// <returns>The return value of the latest execution</returns>
	any visitRangefor(ValuescriptParser::RangeforContext* ctx) override {
		scoping.push(new VSLocalScope(scoping.top(), storage->globalScope.getChildScope(staticName.top())));
		any ret = defaultResult();
		vector<ValuescriptParser::VariabledeclarationContext*> tovisit = ctx->variabledeclaration();
		for (auto curr : tovisit) visit(curr);
		vector<ValuescriptParser::ExpressionContext*> expr = ctx->expression();
		auto cond = expr[0];
		while (any_cast<bool>(visit(cond))) {
			ret = visit(ctx->codeblock());
			for (int i = 1; i < expr.size(); i++) visit(expr[i]);
		}
		return ret;
	}

	/// NOT FUNCTIONAL
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

	/// <summary>
	/// The parse rule for any code block to be executed
	/// </summary>
	/// <param name="ctx">OPEN_CURLY_BRACE statement+ CLOSED_CURLY_BRACE</param>
	/// <param name="ctx">statement</param>
	/// <returns>The return value of the codeblock as a whole</returns>
	any visitCodeblock(ValuescriptParser::CodeblockContext* ctx) override {
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
		return ret;
	}

	/// <summary>
	/// The parser rule for a not expression, will take a boolean expression and inverse it
	/// </summary>
	/// <param name="ctx">notoperator expression</param>
	/// <returns>The NOT of the initial expression</returns>
	any visitNotexpr(ValuescriptParser::NotexprContext* ctx) override {
		any rhs = visit(ctx->expression());
		if (rhs.type() == typeid(VSVariable*)) {
			rhs = any_cast<VSVariable*>(rhs)->value;
		}
		if (bool* test = any_cast<bool>(&rhs)) {
			bool r = *test;
			return !r;
		}
		return defaultResult();
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

	/// <summary>
	/// The parse rule for any identifier, will find the object associated with the identifier
	/// </summary>
	/// <param name="ctx">IDENTIFIER</param>
	/// <returns>A VS Variable, Function, Class, or nullptr</returns>
	any visitIdent(ValuescriptParser::IdentContext* ctx) override {
		string ident = ctx->IDENTIFIER()->getText();
		VSVariable* var = scoping.top()->getVariable(ident);
		if (var != nullptr) {
			return var;
		}
		VSFunction* func = scoping.top()->getFunction(ident);
		if (func != nullptr) {
			return func;
		}
		return scoping.top()->getClass(ident);
	}

	/// <summary>
	/// The parse rule for a double
	/// </summary>
	/// <param name="ctx">FLOATING_LITERAL</param>
	/// <returns>The floating point literal</returns>
	any visitDecimal(ValuescriptParser::DecimalContext* ctx) override {
		return stod(ctx->FLOATING_LITERAL()->getText());
	}

	/// <summary>
	/// The parse rule for an integer
	/// </summary>
	/// <param name="ctx">INTEGER_LITERAL</param>
	/// <returns>The integer literal</returns>
	any visitNumber(ValuescriptParser::NumberContext* ctx) override {
		return stoi(ctx->INTEGER_LITERAL()->getText());
	}

	/// <summary>
	/// The parse rule for true
	/// </summary>
	/// <param name="ctx">TRUE</param>
	/// <returns>Boolean True</returns>
	any visitTrue(ValuescriptParser::TrueContext* ctx) override {
		return true;
	}

	/// <summary>
	/// The parse rule for false
	/// </summary>
	/// <param name="ctx">FALSE</param>
	/// <returns>Boolean False</returns>
	any visitFalse(ValuescriptParser::FalseContext* ctx) override {
		return false;
	}

	/// <summary>
	/// The parse rule for a string
	/// </summary>
	/// <param name="ctx">STRING_LITERAL</param>
	/// <returns>The string literal</returns>
	any visitString(ValuescriptParser::StringContext* ctx) override {
		string str = ctx->STRING_LITERAL()->getText();
		str.erase(str.begin());
		str.erase(str.end() - 1);
		return str;
	}

	/// <summary>
	/// The parse rule for an expression in brackets, allows for order of operation to be bypassed
	/// </summary>
	/// <param name="ctx">OPEN_PARENTHESES expression CLOSED_PARENTHESES</param>
	/// <returns>The evaluated value of the expression within the brackets</returns>
	any visitOrder(ValuescriptParser::OrderContext* ctx) override {
		return visit(ctx->expression());
	}
};