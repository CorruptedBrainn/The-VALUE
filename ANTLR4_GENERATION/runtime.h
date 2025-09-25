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

	/// ========== TYPENAME LOOKUP ==========

	std::unordered_map<std::type_index, std::string> TYPE_NAMES;
	
	/// ========== ABSTRACT OBJECT ==========

	class AbstractObject {
	public:
		AbstractObject() {}
		virtual ~AbstractObject() {}

		// am confused
	};

	class AbstractLiteral : public AbstractObject {
	protected:
		std::type_index type;
		std::any value;
	public:
		AbstractLiteral(std::type_index T, std::any V) :
			type{ T },
			value{ V }
		{ }
		virtual ~AbstractLiteral() {}

		virtual const std::string getType() { return TYPE_NAMES.at(type); }
		virtual const std::any getValue() { return value; }

		virtual const std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) = 0;

		virtual const std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) = 0;
		virtual const std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) = 0;
		virtual const std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) = 0;
		virtual const std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) = 0;
		// Get more operators
	};

	/// ========== CONCRETE OBJECTS ==========

	class ConcreteInteger : public AbstractLiteral {
	public:
		ConcreteInteger(long V) :
			AbstractLiteral(std::type_index(typeid(long)), V)
		{
			std::string tyname = "integer";
			TYPE_NAMES[std::type_index(typeid(long))] = tyname;
		}
		~ConcreteInteger() {}

		const std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }

		const std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) override;
	};

	class ConcreteDouble : public AbstractLiteral {
	public:
		ConcreteDouble(double V) :
			AbstractLiteral(std::type_index(typeid(double)), V)
		{
			std::string tyname = "double";
			TYPE_NAMES[std::type_index(typeid(double))] = tyname;
		}
		~ConcreteDouble() {}

		const std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }

		const std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) override;
	};

	class ConcreteString : public AbstractLiteral {
	public:
		ConcreteString(std::string V) :
			AbstractLiteral(std::type_index(typeid(std::string)), V)
		{
			std::string tyname = "string";
			TYPE_NAMES[std::type_index(typeid(std::string))] = tyname;
		}
		~ConcreteString() {}

		const std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) override;

		const std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) override;
		const std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
	};
	
	class ConcreteBoolean : public AbstractLiteral {
	public:
		ConcreteBoolean(bool V) :
			AbstractLiteral(std::type_index(typeid(bool)), V)
		{
			std::string tyname = "boolean";
			TYPE_NAMES[std::type_index(typeid(bool))] = tyname;
		}
		~ConcreteBoolean() {}

		const std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }

		const std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
	};

	class ConcretePair : public AbstractLiteral {
	public:
		ConcretePair(std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> V) :
			AbstractLiteral(std::type_index(typeid(std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>)), V)
		{
			std::string tyname = "pair<" +
				V.first->getType() + ", " +
				V.second->getType() + ">";
			TYPE_NAMES[std::type_index(typeid(std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>))] = tyname;
		}
		~ConcretePair() {}

		const std::shared_ptr<AbstractObject> getFirst() { return std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue()).first; }
		const std::shared_ptr<AbstractObject> getSecond() { return std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue()).second; }

		const std::shared_ptr<AbstractObject> operator[](std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }

		const std::shared_ptr<AbstractObject> operator+(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator-(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator*(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
		const std::shared_ptr<AbstractObject> operator/(std::shared_ptr<AbstractLiteral> rhs) override { return nullptr; }
	};

	// Implement other types

	class ConcreteVariable : public AbstractLiteral {

	};

	// more

	/// ========= BASE CREATOR ==========

	template <typename... Args>
	class BaseCreator {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(Args... args) = 0;
	};

	/// ========== DERIVED CREATORS ==========

	class IntegerCreator : public BaseCreator<long> {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(long arg1) override;
	};

	class DoubleCreator : public BaseCreator<double> {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(double arg1) override;
	};

	class StringCreator : public BaseCreator<std::string> {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(std::string arg1) override;
	};

	class BooleanCreator : public BaseCreator<bool> {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(bool arg1) override;
	};

	class PairCreator : public BaseCreator<std::shared_ptr<AbstractObject>, std::shared_ptr<AbstractObject>> {
	public:
		virtual std::shared_ptr<AbstractObject> createObject(std::shared_ptr<AbstractObject> arg1, std::shared_ptr<AbstractObject> arg2) override;
	};
}