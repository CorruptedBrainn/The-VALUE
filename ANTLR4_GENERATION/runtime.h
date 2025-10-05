#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#pragma execution_character_set("utf-8")

#include <string>
#include <unordered_map>
#include <any>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <iostream>

namespace Runtime {

	/// ========== FORWARD DECLARATIONS ==========

	class AbstractObject;
	class GenericScope;
	std::ostream& operator<<(std::ostream& os, const AbstractObject& obj);

	/// ========== TYPENAME LOOKUP ==========

	static std::unordered_map<std::type_index, std::string> TYPE_NAMES;
	
	/// ========== ABSTRACT OBJECT ==========

	class AbstractObject {
	protected:
		std::type_index type;
		std::any value;
	public:
		AbstractObject(std::type_index T, std::any V) :
			type{ T },
			value{ V }
		{ }
		virtual ~AbstractObject() {}

		virtual std::string getType() const { return TYPE_NAMES.at(type); }
		virtual std::any getValue() const { return value; }
		virtual void print(std::ostream& os) const = 0;
	};

	class AbstractLiteral : public AbstractObject {
	public:
		AbstractLiteral(std::type_index T, std::any V) :
			AbstractObject(T, V)
		{ }
		virtual ~AbstractLiteral() {}

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

	/// ========== CONCRETE OBJECTS ==========

	class ConcreteVoid : public AbstractLiteral {
	public:
		ConcreteVoid() :
			AbstractLiteral(std::type_index(typeid(void)), nullptr)
		{
			std::string tyname = "void";
			TYPE_NAMES[std::type_index(typeid(void))] = tyname;
		}
		~ConcreteVoid() {}

		void print(std::ostream& os) const override { os << "void"; }
	};

	class ConcreteInteger : public AbstractLiteral {
	public:
		ConcreteInteger(long V) :
			AbstractLiteral(std::type_index(typeid(V)), V)
		{
			std::string tyname = "integer";
			TYPE_NAMES[std::type_index(typeid(V))] = tyname;
		}
		~ConcreteInteger() {}

		void print(std::ostream& os) const override { os << std::any_cast<long>(this->getValue()); }

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
	public:
		ConcreteDouble(double V) :
			AbstractLiteral(std::type_index(typeid(V)), V)
		{
			std::string tyname = "double";
			TYPE_NAMES[std::type_index(typeid(V))] = tyname;
		}
		~ConcreteDouble() {}

		void print(std::ostream& os) const override { os << std::any_cast<double>(this->getValue()); }

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
	public:
		ConcreteString(std::string V) :
			AbstractLiteral(std::type_index(typeid(V)), V)
		{
			std::string tyname = "string";
			TYPE_NAMES[std::type_index(typeid(V))] = tyname;
		}
		~ConcreteString() {}

		void print(std::ostream& os) const override { os << std::any_cast<std::string>(this->getValue()); }

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
	};
	
	class ConcreteBoolean : public AbstractLiteral {
	public:
		ConcreteBoolean(bool V) :
			AbstractLiteral(std::type_index(typeid(V)), V)
		{
			std::string tyname = "boolean";
			TYPE_NAMES[std::type_index(typeid(V))] = tyname;
		}
		~ConcreteBoolean() {}

		void print(std::ostream& os) const override { os << std::any_cast<bool>(this->getValue()); }

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
	public:
		ConcretePair(std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> V) :
			AbstractLiteral(std::type_index(typeid(V)), V)
		{
			std::string tyname = "pair";
			TYPE_NAMES[std::type_index(typeid(V))] = tyname;
		}
		~ConcretePair() {}

		void print(std::ostream& os) const override { os << *this->getFirst().get() << ", " << *this->getSecond().get(); }

		std::shared_ptr<AbstractObject> getFirst() const;
		std::shared_ptr<AbstractObject> getSecond() const;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
	};

	class ConcreteArray : public AbstractLiteral {
	public:
		ConcreteArray(std::vector<std::shared_ptr<AbstractLiteral>> V) :
			AbstractLiteral(std::type_index(typeid(V)), V)
		{
			std::string tyname = "array";
			TYPE_NAMES[std::type_index(typeid(V))] = tyname;
		}
		~ConcreteArray() {}

		void print(std::ostream& os) const override { os << "PLACEHOLDER FOR ARRAY"; }

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
	};

	class ConcreteVariable : public AbstractLiteral {
	protected:
		std::string name;
		bool isConst = false;
		bool isStatic = false;
	public:
		ConcreteVariable(std::shared_ptr<AbstractLiteral> V, std::string N, bool C, bool S) :
			AbstractLiteral(std::type_index(typeid(V)), V),
			name{ N },
			isConst{ C },
			isStatic{ S }
		{ }
		~ConcreteVariable() {}

		void print(std::ostream& os) const override { os << *std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()).get(); }

		std::any setValue(std::any val) { return value = val; }
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

	};

	class ConcreteClass : public AbstractObject {

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

	class PairCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class ArrayCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	class VariableCreator : public BaseCreator {
	public:
		std::shared_ptr<AbstractObject> createObject(std::vector<std::any> args) override;
	};

	/// ========== RUNTIME INFORMATION ==========

	class GenericScope {
	private:
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>> members;
		std::shared_ptr<GenericScope> parent;
		std::shared_ptr<AbstractLiteral> ret = nullptr;
	public:
		GenericScope(std::shared_ptr<GenericScope> P = nullptr) :
			parent{ P }
		{ }
		~GenericScope() {}

		void addMember(std::string name, std::shared_ptr<AbstractObject> val) { members.insert({ name, val }); }
		std::shared_ptr<AbstractObject> findMember(std::string name) const;
		bool contains(std::string name) const { return members.contains(name); }
		std::shared_ptr<GenericScope> getParent() const { return parent; }
		void setRet(std::shared_ptr<AbstractLiteral> val) { ret = val; }
		std::shared_ptr<AbstractLiteral> getRet() const { return ret; }
	};

	class BlockScope {
	private:
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>> variables;
		std::shared_ptr<BlockScope> parent;
		std::shared_ptr<GenericScope> generic;
		bool broken = false;
	public:
		BlockScope(std::shared_ptr<BlockScope> P = nullptr, std::shared_ptr<GenericScope> G = nullptr) :
			parent{ P },
			generic{ G }
		{ }
		~BlockScope() {}

		void addVariable(std::string name, std::shared_ptr<AbstractObject> val) { variables.insert({ name, val }); }
		std::shared_ptr<AbstractObject> findMember(std::string name) const;
		bool contains(std::string name) const { return variables.contains(name); }
		std::shared_ptr<BlockScope> getParent() const { return parent; }
		std::shared_ptr<GenericScope> getGeneric() const { return generic; }
		void setBroken(bool val) { broken = val; }
		bool getBroken() const { return broken; }
	};

}