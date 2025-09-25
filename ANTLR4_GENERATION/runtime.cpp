#include "runtime.h"

namespace Runtime {

	/// ========== CONCRETE INTEGER ==========

	const std::shared_ptr<AbstractObject> ConcreteInteger::operator+(std::shared_ptr<AbstractLiteral> rhs)
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getValue()));
		BaseCreator<long>* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(llhs + lrhs));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteInteger::operator-(std::shared_ptr<AbstractLiteral> rhs)
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getValue()));
		BaseCreator<long>* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(llhs - lrhs));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteInteger::operator*(std::shared_ptr<AbstractLiteral> rhs)
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getValue()));
		BaseCreator<long>* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(llhs * lrhs));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteInteger::operator/(std::shared_ptr<AbstractLiteral> rhs)
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getValue()));
		BaseCreator<long>* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(llhs / lrhs));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE DOUBLE ==========

	const std::shared_ptr<AbstractObject> ConcreteDouble::operator+(std::shared_ptr<AbstractLiteral> rhs)
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getValue()));
		BaseCreator<double>* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(dlhs + drhs));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteDouble::operator-(std::shared_ptr<AbstractLiteral> rhs)
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getValue()));
		BaseCreator<double>* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(dlhs - drhs));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteDouble::operator*(std::shared_ptr<AbstractLiteral> rhs)
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getValue()));
		BaseCreator<double>* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(dlhs * drhs));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteDouble::operator/(std::shared_ptr<AbstractLiteral> rhs)
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getValue()));
		BaseCreator<double>* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(dlhs / drhs));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE STRING ==========

	const std::shared_ptr<AbstractObject> ConcreteString::operator[](std::shared_ptr<AbstractLiteral> rhs)
	{
		std::string slhs(std::any_cast<std::string> (this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getValue()));
		BaseCreator <std::string>* factory(new StringCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs[lrhs] }));
		delete factory;
		return ret;
	}

	const std::shared_ptr<AbstractObject> ConcreteString::operator+(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getValue()));
		BaseCreator<std::string>* factory(new StringCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject(slhs + srhs));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE FACTORIES ==========

	std::shared_ptr<AbstractObject> IntegerCreator::createObject(long arg1)
	{
		return std::make_shared<ConcreteInteger>(arg1);
	}

	std::shared_ptr<AbstractObject> DoubleCreator::createObject(double arg1)
	{
		return std::make_shared<ConcreteDouble>(arg1);
	}

	std::shared_ptr<AbstractObject> StringCreator::createObject(std::string arg1)
	{
		return std::make_shared<ConcreteString>(arg1);
	}

	std::shared_ptr<AbstractObject> BooleanCreator::createObject(bool arg1)
	{
		return std::make_shared<ConcreteBoolean>(arg1);
	}

	std::shared_ptr<AbstractObject> PairCreator::createObject(std::shared_ptr<AbstractObject> arg1, std::shared_ptr<AbstractObject> arg2)
	{
		std::shared_ptr<AbstractLiteral> lhs(static_cast<AbstractLiteral*>(arg1.get()));
		std::shared_ptr<AbstractLiteral> rhs(static_cast<AbstractLiteral*>(arg1.get()));
		return std::make_shared<ConcretePair>(std::pair{lhs, rhs});
	}

}