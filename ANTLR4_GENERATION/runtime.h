#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#pragma execution_character_set("utf-8")

#include <string>
#include <unordered_map>
#include <any>
#include <typeindex>
#include <typeinfo>
#include <memory>

namespace Runtime {

	/// ========== FORWARD DECLARATIONS ==========

	class GenericNamespace;
	class GenericScope;

	/// ========== TYPENAME LOOKUP ==========

	std::unordered_map<std::type_index, std::string> TYPE_NAMES;
	
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
	};

	class AbstractLiteral : public AbstractObject {
	public:
		AbstractLiteral(std::type_index T, std::any V) :
			AbstractObject(T, V)
		{ }
		virtual ~AbstractLiteral() {}

		virtual std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const = 0;

		virtual std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const = 0;

		virtual std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const = 0;

		virtual std::shared_ptr<AbstractObject> operator!() const = 0;

		virtual std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const = 0;

		virtual std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const = 0;
		virtual std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const = 0;
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

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator!() const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
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

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator!() const override;

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

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

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator!() const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

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

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator!() const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
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

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator!() const override;

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
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

		std::shared_ptr<AbstractObject> getFirst() const;
		std::shared_ptr<AbstractObject> getSecond() const;

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator!() const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
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

		std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) const override;

		std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator%(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator|(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator^(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator!() const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator&&(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator||(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }

		std::shared_ptr<AbstractObject> operator==(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator!=(std::shared_ptr<AbstractLiteral> rhs) const override;
		std::shared_ptr<AbstractObject> operator<=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>=(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator<(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
		std::shared_ptr<AbstractObject> operator>(std::shared_ptr<AbstractLiteral> rhs) const override { return nullptr; }
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

	class GenericNamespace {
	private:
		std::unordered_map<std::string, std::shared_ptr<ConcreteVariable>> staticVariables;
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>> members;
		std::shared_ptr<GenericNamespace> parentNamespace = nullptr;
	public:
		GenericNamespace(std::shared_ptr<GenericNamespace> parent) :
			parentNamespace{ parent }
		{ }
		~GenericNamespace() {}

		std::unordered_map<std::string, std::shared_ptr<ConcreteVariable>> getStatics() const { return staticVariables; }
		bool hasStatic(std::string var) const { return staticVariables.contains(var); }
		void createStatic(std::shared_ptr<ConcreteVariable> var) { staticVariables.insert({ var->getName(), var }); }
	};

	class GenericScope {
	private:
		std::unordered_map<std::string, std::shared_ptr<ConcreteVariable>> variables;
		std::shared_ptr<GenericNamespace> parentNamespace = nullptr;
		std::shared_ptr<AbstractLiteral> ret = nullptr;
		bool broken = false;
	public:
		GenericScope(std::shared_ptr<GenericNamespace> parent) :
			parentNamespace{ parent }
		{
			for (std::pair<std::string, std::shared_ptr<ConcreteVariable>> var : parent->getStatics()) variables[var.first] = var.second;
		}
		~GenericScope() {}

		void createVar(std::shared_ptr<ConcreteVariable> var);

		std::shared_ptr<AbstractLiteral> getRet() const { return ret; }
		std::shared_ptr<AbstractLiteral> setRet(std::shared_ptr<AbstractLiteral> val) { return ret = val; }

		bool getBroken() const { return broken; }
		bool setBroken(bool val) { return broken = val; }
	};
}