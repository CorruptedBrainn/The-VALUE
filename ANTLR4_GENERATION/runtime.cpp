#include "runtime.h"

namespace Runtime {

	/// ========== ABSTRACT OBJECT ==========

	std::ostream& operator<<(std::ostream& os, const AbstractObject& obj)
	{
		obj.print(os);
		return os;
	}

	/// ========== ABSTRACT CONTAINER ==========

	std::shared_ptr<AbstractObject> AbstractContainer::operator[](std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		return alhs[lrhs];
	}

	std::shared_ptr<AbstractObject> AbstractContainer::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::vector<std::shared_ptr<AbstractLiteral>> arhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new ContainerCreator());
		alhs.insert(alhs.end(), arhs.begin(), arhs.end());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ alhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> AbstractContainer::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::vector<std::shared_ptr<AbstractLiteral>> arhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ alhs == arhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> AbstractContainer::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::vector<std::shared_ptr<AbstractLiteral>> arhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ alhs != arhs }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE INTEGER ==========

	std::shared_ptr<AbstractObject> ConcreteInteger::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs + lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator-(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs - lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator*(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs * lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator/(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs / lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator%(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs % lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator&(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs & lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator|(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs | lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator^(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs ^ lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator!() const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ ~llhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs == lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs != lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator<=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs <= lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator>=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs >= lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator<(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs < lrhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteInteger::operator>(std::shared_ptr<AbstractLiteral> rhs) const
	{
		long llhs(std::any_cast<long>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ llhs > lrhs }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE DOUBLE ==========

	std::shared_ptr<AbstractObject> ConcreteDouble::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs + drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator-(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs - drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator*(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs * drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator/(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new DoubleCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs / drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs == drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs != drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator<=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs <= drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator>=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs >= drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator<(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs < drhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteDouble::operator>(std::shared_ptr<AbstractLiteral> rhs) const
	{
		double dlhs(std::any_cast<double>(this->getValue()));
		double drhs(std::any_cast<double>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ dlhs > drhs }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE STRING ==========

	std::shared_ptr<AbstractObject> ConcreteString::operator[](std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string> (this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		BaseCreator* factory(new StringCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ std::string{slhs[lrhs]} }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteString::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new StringCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs + srhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteString::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs == srhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteString::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs != srhs }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE BOOLEAN ==========

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator&(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs & brhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator|(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs | brhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator^(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs ^ brhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator!() const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ !blhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator&&(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs && brhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator||(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs || brhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs == brhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteBoolean::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		bool blhs(std::any_cast<bool>(this->getValue()));
		bool brhs(std::any_cast<bool>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ blhs != brhs }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE PAIR ==========

	std::shared_ptr<AbstractObject> ConcretePair::getFirst() const
	{
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> val = std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue());
		return val.first;
	}

	std::shared_ptr<AbstractObject> ConcretePair::getSecond() const
	{
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> val = std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue());
		return val.second;
	}

	std::shared_ptr<AbstractObject> ConcretePair::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> plhs(std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> prhs(std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ plhs == prhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcretePair::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> plhs(std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> prhs(std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ plhs != prhs }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE ARRAY ==========

	std::shared_ptr<AbstractObject> ConcreteArray::operator[](std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get())[rhs];
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) + rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) == rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) != rhs;
	}

	/// ========== CONCRETE VARIABLE ==========

	std::shared_ptr<AbstractObject> ConcreteVariable::operator[](std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get())[rhs];
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) + rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator-(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) - rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator*(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) * rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator/(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) / rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator%(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) % rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator&(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) & rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator|(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) | rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator^(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) ^ rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator!() const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return !(*lhs.get());
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator&&(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) && rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator||(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) || rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) == rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) != rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator<=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) <= rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator>=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) >= rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator<(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) < rhs;
	}

	std::shared_ptr<AbstractObject> ConcreteVariable::operator>(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::shared_ptr<AbstractLiteral> lhs(std::any_cast<std::shared_ptr<AbstractLiteral>>(this->getValue()));
		return (*lhs.get()) > rhs;
	}

	/// ========== CONCRETE FACTORIES ==========

	std::shared_ptr<AbstractObject> ContainerCreator::createObject(std::vector<std::any> args)
	{
		std::vector<std::shared_ptr<AbstractLiteral>> val = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(args[0]);
		return std::make_shared<AbstractContainer>(val);
	}

	std::shared_ptr<AbstractObject> VoidCreator::createObject(std::vector<std::any> args)
	{
		return std::make_shared<ConcreteVoid>();
	}

	std::shared_ptr<AbstractObject> IntegerCreator::createObject(std::vector<std::any> args)
	{
		long val = std::any_cast<long>(args[0]);
		return std::make_shared<ConcreteInteger>(val);
	}

	std::shared_ptr<AbstractObject> DoubleCreator::createObject(std::vector<std::any> args)
	{
		double val = std::any_cast<double>(args[0]);
		return std::make_shared<ConcreteDouble>(val);
	}

	std::shared_ptr<AbstractObject> StringCreator::createObject(std::vector<std::any> args)
	{
		std::string val = std::any_cast<std::string>(args[0]);
		return std::make_shared<ConcreteString>(val);
	}

	std::shared_ptr<AbstractObject> BooleanCreator::createObject(std::vector<std::any> args)
	{
		bool val = std::any_cast<bool>(args[0]);
		return std::make_shared<ConcreteBoolean>(val);
	}

	std::shared_ptr<AbstractObject> PairCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> left = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		std::shared_ptr<AbstractLiteral> right = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[1]);
		return std::make_shared<ConcretePair>(std::pair{left, right});
	}

	std::shared_ptr<AbstractObject> ArrayCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> val = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		return std::make_shared<ConcreteArray>(val);
	}

	std::shared_ptr<AbstractObject> VariableCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> val = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		std::string name = std::any_cast<std::string>(args[1]);
		bool isConst = std::any_cast<bool>(args[2]);
		bool isStatic = std::any_cast<bool>(args[3]);
		return std::make_shared<ConcreteVariable>(val, name, isConst, isStatic);
	}

	/// ========== GENERIC SCOPE ==========

	std::shared_ptr<AbstractObject> GenericScope::findMember(std::string name) const
	{
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>>::const_iterator ret = members.find(name);
		if (ret == members.end()) {
			if (parent == nullptr) return nullptr;
			return parent->findMember(name);
		}
		return ret->second;
	}

	/// ========== BLOCK SCOPE ==========

	std::shared_ptr<AbstractObject> BlockScope::findMember(std::string name) const
	{
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>>::const_iterator ret = variables.find(name);
		if (ret == variables.end()) {
			if (parent == nullptr) return generic->findMember(name);
			return parent->findMember(name);
		}
		return ret->second;
	}

}