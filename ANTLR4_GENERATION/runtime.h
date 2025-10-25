#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#pragma execution_character_set("utf-8")

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <any>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <functional>

namespace Runtime {

	/// ========== FORWARD DECLARATIONS ==========

	class AbstractObject;
	class AbstractLiteral;
	class GenericScope;
	std::ostream& operator<<(std::ostream& os, const AbstractObject& obj);

	/// ========== TYPE INFORMATION ==========

	struct TypeInformation {
		std::string name;
		std::vector<TypeInformation> children;
	};
	
	/// ========== ABSTRACT OBJECT ==========

	class AbstractObject {
	protected:
		TypeInformation type;
		std::any value;
	public:
		AbstractObject(TypeInformation T, std::any V) :
			type{ T },
			value{ V }
		{ }
		virtual ~AbstractObject() {}

		virtual TypeInformation& getType() { return type; }
		virtual std::any getValue() const { return value; }
		virtual std::any getUnderlying() const { return value; }
		virtual std::any& getReference() { return value; }
		virtual void print(std::ostream& os) const = 0;
		virtual std::shared_ptr<AbstractObject> copy() const = 0;

		virtual operator bool() const { return false; }
	};

	class AbstractLiteral : public AbstractObject {
	protected:
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>> members;
	public:
		AbstractLiteral(TypeInformation T, std::any V) :
			AbstractObject(T, V)
		{ }
		virtual ~AbstractLiteral() {}

		virtual std::unordered_map<std::string, std::shared_ptr<AbstractObject>>& getMembers() { return members; }
		std::shared_ptr<AbstractObject> copy() const override = 0;

		virtual std::any setValue(std::shared_ptr<AbstractObject> val);

		virtual std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }

		virtual std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }

		virtual std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }

		virtual std::shared_ptr<AbstractObject> operator!() const { return nullptr; }

		virtual std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }

		virtual std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
		virtual std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const { return nullptr; }
	};

	class AbstractContainer : public AbstractLiteral {
	public:
		AbstractContainer(TypeInformation T, std::any V) :
			AbstractLiteral(T, V)
		{ }
		~AbstractContainer() {}

		void print(std::ostream& os) const override;
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<AbstractContainer>(type, value); }
	};

	/// ========== COMPARISON OBJECTS ==========

	struct ObjectComp
	{
		bool operator()(const std::shared_ptr<AbstractLiteral>& lhs, const std::shared_ptr<AbstractLiteral>& rhs) const
		{
			return *((*lhs.get()) < rhs).get();
		}
	};

	/// ========== CONCRETE OBJECTS ==========

	class ConcreteVoid : public AbstractLiteral {
	public:
		ConcreteVoid() :
			AbstractLiteral(TypeInformation({"Void", {}}), nullptr)
		{ }
		~ConcreteVoid() {}

		void print(std::ostream& os) const override { os << "void"; }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteVoid>(); }
	};

	class ConcreteInteger : public AbstractLiteral {
	private:
		long _V;
	public:
		ConcreteInteger(long V) :
			AbstractLiteral(TypeInformation({ "Integer", {} }), V),
			_V{ V }
		{ }
		~ConcreteInteger() {}

		void print(std::ostream& os) const override { os << std::any_cast<long>(this->getValue()); }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteInteger>(std::any_cast<long>(value)); }

		std::any setValue(std::shared_ptr<AbstractObject> val) override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator!() const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override;
	};

	class ConcreteDouble : public AbstractLiteral {
	private:
		double _V;
	public:
		ConcreteDouble(double V) :
			AbstractLiteral(TypeInformation({ "Double", {} }), V),
			_V{ V }
		{ }
		~ConcreteDouble() {}

		void print(std::ostream& os) const override { os << std::any_cast<double>(this->getValue()); }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteDouble>(std::any_cast<double>(value)); }

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override;
	};

	class ConcreteString : public AbstractLiteral {
	private:
		std::string _V;
	public:
		ConcreteString(std::string V) :
			AbstractLiteral(TypeInformation({ "String", {} }), V),
			_V{ V }
		{ }
		~ConcreteString() {}

		void print(std::ostream& os) const override { os << "\"" << std::any_cast<std::string>(this->getValue()) << "\""; }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteString>(std::any_cast<std::string>(value)); }

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override;
	};
	
	class ConcreteBoolean : public AbstractLiteral {
	private:
		bool _V;
	public:
		ConcreteBoolean(bool V) :
			AbstractLiteral(TypeInformation({ "Boolean", {} }), V),
			_V{ V }
		{ }
		~ConcreteBoolean() {}

		void print(std::ostream& os) const override { os << std::any_cast<bool>(this->getValue()) ? true : false; }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteBoolean>(std::any_cast<bool>(value)); }

		operator bool() const override { return std::any_cast<bool>(this->getValue()); }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator!() const override;

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
	};

	class ConcretePair : public AbstractLiteral {
	private:
		inline static std::unordered_map<std::string, std::shared_ptr<AbstractObject>> registration;
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> _V;
	public:
		ConcretePair(std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> V, TypeInformation T) :
			AbstractLiteral(T, V),
			_V{ V }
		{
			members = registration;
		}
		~ConcretePair() {}

		void print(std::ostream& os) const override { os << *this->getFirst().get() << ", " << *this->getSecond().get(); }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcretePair>(std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(value), type); }
		static void addRegistration(std::string name, std::shared_ptr<AbstractObject> val) { registration.insert({ name, val }); }

		std::shared_ptr<AbstractObject> getFirst() const;
		std::shared_ptr<AbstractObject> getSecond() const;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> pair_get_first();
		std::shared_ptr<AbstractObject> pair_get_second();
	};

	class ConcreteArray : public AbstractLiteral {
	private:
		inline static std::unordered_map<std::string, std::shared_ptr<AbstractObject>> registration;
		std::vector<std::shared_ptr<AbstractLiteral>> _V;
	public:
		ConcreteArray(std::vector<std::shared_ptr<AbstractLiteral>> V, TypeInformation T) :
			AbstractLiteral(T, V),
			_V{ V }
		{
			members = registration;
		}
		~ConcreteArray() {}

		void print(std::ostream& os) const override;
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteArray>(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(value), type); }
		static void addRegistration(std::string name, std::shared_ptr<AbstractObject> val) { registration.insert({ name, val }); }

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;

		void array_append_single(std::shared_ptr<AbstractLiteral> rhs);
		void array_insert_single(std::shared_ptr<AbstractLiteral> rhs, long pos);
		void array_pop_single();
		void array_remove_single(long pos);
		void array_clear_elements();
		std::shared_ptr<AbstractObject> array_check_empty();
		std::shared_ptr<AbstractObject> array_check_size();
	};

	class ConcreteSet : public AbstractLiteral {
	private:
		inline static std::unordered_map<std::string, std::shared_ptr<AbstractObject>> registration;
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> _V;
	public:
		ConcreteSet(std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> V, TypeInformation T) :
			AbstractLiteral(T, V),
			_V{ V }
		{ 
			members = registration;
		}
		~ConcreteSet() {}

		void print(std::ostream& os) const override;
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteSet>(std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>>(value), type); }
		static void addRegistration(std::string name, std::shared_ptr<AbstractObject> val) { registration.insert({ name, val }); }

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;

		void ordered_list_insert_single(std::shared_ptr<AbstractLiteral> rhs);
		void ordered_list_remove_single(std::shared_ptr<AbstractLiteral> rhs);
		void ordered_list_clear_elements();
		std::shared_ptr<AbstractObject> ordered_list_check_empty();
		std::shared_ptr<AbstractObject> ordered_list_check_size();
		std::shared_ptr<AbstractObject> ordered_list_count_single(std::shared_ptr<AbstractLiteral> rhs);
		std::shared_ptr<AbstractObject> ordered_list_contains_single(std::shared_ptr<AbstractLiteral> rhs);
		std::shared_ptr<AbstractObject> ordered_list_find_element(std::shared_ptr<AbstractLiteral> rhs);
		std::shared_ptr<AbstractObject> ordered_list_lower_bound(std::shared_ptr<AbstractLiteral> rhs);
		std::shared_ptr<AbstractObject> ordered_list_upper_bound(std::shared_ptr<AbstractLiteral> rhs);
	};

	class ConcreteVariable : public AbstractLiteral {
	private:
		std::shared_ptr<AbstractLiteral> _V;
	protected:
		std::string name;
		bool isConst = false;
		bool isStatic = false;
	public:
		ConcreteVariable(std::shared_ptr<AbstractLiteral> V, TypeInformation T, std::string N, bool C, bool S) :
			AbstractLiteral(T, V),
			name{ N },
			isConst{ C },
			isStatic{ S },
			_V{ V }
		{ }
		~ConcreteVariable() {}

		std::unordered_map<std::string, std::shared_ptr<AbstractObject>>& getMembers() override { return std::any_cast<std::shared_ptr<AbstractLiteral>>(value)->getMembers(); }
		void print(std::ostream& os) const override { os << *std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()).get(); }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteVariable>(std::static_pointer_cast<AbstractLiteral>(std::any_cast<std::shared_ptr<AbstractLiteral>>(value)->copy()), type, name, isConst, isStatic); }

		std::any setValue(std::shared_ptr<AbstractObject> val) override;
		std::any getUnderlying() const override { return std::any_cast<std::shared_ptr<AbstractLiteral>>(value)->getValue(); }
		std::string getName() const { return name; }
		bool getConst() const { return isConst; }
		bool getStatic() const { return isStatic; }

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator!() const override;

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override;
	};

	class ConcreteFunction : public AbstractObject {
	protected:
		std::string name;
		std::unordered_set<std::string> templates;
		std::vector<std::shared_ptr<ConcreteVariable>> parameters;
		std::shared_ptr<GenericScope> scope;
	public:
		ConcreteFunction(std::any V, TypeInformation R, std::string N, std::unordered_set<std::string> T, std::vector<std::shared_ptr<ConcreteVariable>> P, std::shared_ptr<GenericScope> S) :
			AbstractObject(R, V),
			name{ N },
			templates{ T },
			parameters{ P },
			scope{ S }
		{ }
		~ConcreteFunction() {}

		void print(std::ostream& os) const override { os << "Function"; }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteFunction>(value, type, name, templates, parameters, scope); }

		std::any setParam(std::shared_ptr<AbstractLiteral> val, int pos) { return parameters[pos]->setValue(val); }
		std::vector<std::shared_ptr<ConcreteVariable>>& getParam() { return parameters; }
		std::shared_ptr<GenericScope> getScope() const { return scope; }
	};

	class ConcreteClass : public AbstractObject {
	protected:
		std::string name;
		std::unordered_set<std::string> templates;
		std::shared_ptr<GenericScope> scope;
	public:
		ConcreteClass(std::any V, TypeInformation R, std::string N, std::unordered_set<std::string> T, std::shared_ptr<GenericScope> S) :
			AbstractObject(R, V),
			name{ N },
			templates{ T },
			scope{ S }
		{ }
		~ConcreteClass() {}

		void print(std::ostream& os) const override { os << "Class"; }
		std::shared_ptr<AbstractObject> copy() const override { return std::make_shared<ConcreteClass>(value, type, name, templates, scope); }

		std::shared_ptr<GenericScope> getScope() const { return scope; }
	};

	// more

	/// ========= BASE CREATOR ==========
	
	class BaseCreator {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args = {}) = 0;
	};

	/// ========== DERIVED CREATORS ==========

	class VoidCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class IntegerCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class DoubleCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class StringCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class BooleanCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class ContainerCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class PairCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class ArrayCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class SetCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class VariableCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class FunctionCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class ClassCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	/// ========== RUNTIME INFORMATION ==========

	class GenericScope {
	private:
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>> members = {};
		std::shared_ptr<GenericScope> parent;
		std::shared_ptr<AbstractLiteral> ret = nullptr;
		std::string name;
	public:
		GenericScope(std::string N, std::shared_ptr<GenericScope> P = nullptr, bool C = false) :
			parent{ P },
			name{ N }
		{ }
		~GenericScope() {}

		void addMember(std::string& name, std::shared_ptr<AbstractObject> val) { members.insert({ name, val }); }
		std::shared_ptr<AbstractObject> findMember(std::string& name) const;
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>>& getMembers() { return members; }
		bool contains(std::string& name) const { return members.contains(name); }
		std::shared_ptr<GenericScope> getParent() const { return parent; }
		void setRet(std::shared_ptr<AbstractLiteral> val) { ret = val; }
		std::shared_ptr<AbstractLiteral> getRet() const { return ret; }
	};

	class BlockScope {
	private:
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>> variables = {};
		std::shared_ptr<BlockScope> parent;
		std::shared_ptr<GenericScope> generic;
		bool broken = false;
		std::string name;
	public:
		BlockScope(std::string N, std::shared_ptr<BlockScope> P = nullptr, std::shared_ptr<GenericScope> G = nullptr) :
			parent{ P },
			generic{ G },
			name{ N }
		{ }
		~BlockScope() {}

		void addVariable(std::string& name, std::shared_ptr<AbstractObject> val) { variables.insert({ name, val }); }
		std::shared_ptr<AbstractObject> findMember(std::string& name) const;
		bool contains(std::string& name) const { return variables.contains(name); }
		std::shared_ptr<AbstractObject> getFirstVar() const { return variables.begin()->second; }
		std::shared_ptr<BlockScope> getParent() const { return parent; }
		std::shared_ptr<GenericScope> getGeneric() const { return generic; }
		void setBroken(bool val) { broken = val; }
		bool getBroken() const { return broken; }
	};

}