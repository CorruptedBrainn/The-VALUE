#include "runtime.h"

namespace Runtime {

	/// ========== ABSTRACT OBJECT ==========

	std::ostream& operator<<(std::ostream& os, const AbstractObject& obj)
	{
		obj.print(os);
		return os;
	}

	/// ========== ABSTRACT LITERAL ==========

	std::any AbstractLiteral::setValue(std::shared_ptr<AbstractObject> val)
	{
		value = val->getValue();
		return val;
	}

	/// ========== ABSTRACT CONTAINER ==========

	void AbstractContainer::print(std::ostream& os) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> vec(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		if (vec.empty()) os << "{ }";
		else {
			os << "{ " << **vec.begin();
			std::for_each(std::next(vec.begin()), vec.end(), [&os](const std::shared_ptr<AbstractLiteral>& val) {
				os << ", " << *val;
				});
			os << " }";
		}
		return;
	}

	/// ========== CONCRETE INTEGER ==========

	std::any ConcreteInteger::setValue(std::shared_ptr<AbstractObject> val)
	{
		value = val->getValue();
		_V = std::any_cast<long>(value);
		return val;
	}

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

	std::shared_ptr<AbstractObject> ConcreteString::operator<=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs <= srhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteString::operator>=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs >= srhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteString::operator<(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs < srhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteString::operator>(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::string slhs(std::any_cast<std::string>(this->getValue()));
		std::string srhs(std::any_cast<std::string>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs > srhs }));
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

	std::shared_ptr<AbstractObject> ConcretePair::pair_get_first()
	{
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> val = std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue());
		return val.first;
	}

	std::shared_ptr<AbstractObject> ConcretePair::pair_get_second()
	{
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> val = std::any_cast<std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>>>(this->getValue());
		return val.second;
	}

	/// ========== CONCRETE ARRAY ==========

	void ConcreteArray::print(std::ostream& os) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> vec(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		if (vec.empty()) os << "{ }";
		else {
			os << "{ " << **vec.begin();
			std::for_each(std::next(vec.begin()), vec.end(), [&os](const std::shared_ptr<AbstractLiteral>& val) {
				os << ", " << *val;
				});
			os << " }";
		}
		return;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator[](std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		long lrhs(std::any_cast<long>(rhs->getUnderlying()));
		return alhs[lrhs];
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator+(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::vector<std::shared_ptr<AbstractLiteral>> arhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		alhs.insert(alhs.end(), arhs.begin(), arhs.end());
		BaseCreator* cfactory(new ContainerCreator());
		std::shared_ptr<AbstractObject> oval(cfactory->createObject({ alhs, this->type }));
		std::shared_ptr<AbstractLiteral> val(std::static_pointer_cast<AbstractLiteral>(oval));
		delete cfactory;
		BaseCreator* factory = new ArrayCreator();
		std::shared_ptr<AbstractObject> ret(factory->createObject({ val, this->type }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::vector<std::shared_ptr<AbstractLiteral>> arhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ alhs == arhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::vector<std::shared_ptr<AbstractLiteral>> alhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(this->getValue()));
		std::vector<std::shared_ptr<AbstractLiteral>> arhs(std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ alhs != arhs }));
		delete factory;
		return ret;
	}

	void ConcreteArray::array_append_single(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		alhs.push_back(rhs);
		_V.push_back(rhs);
		return;
	}

	void ConcreteArray::array_insert_single(std::shared_ptr<AbstractLiteral> rhs, long pos)
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		alhs.insert(alhs.begin() + pos, rhs);
		_V.insert(_V.begin() + pos, rhs);
		return;
	}

	void ConcreteArray::array_pop_single()
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		alhs.pop_back();
		_V.pop_back();
		return;
	}

	void ConcreteArray::array_remove_single(long pos)
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		alhs.erase(alhs.begin() + pos);
		_V.erase(_V.begin() + pos);
		return;
	}

	void ConcreteArray::array_clear_elements()
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		alhs.clear();
		_V.clear();
		return;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::array_check_empty()
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ alhs.empty() }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteArray::array_check_size()
	{
		std::vector<std::shared_ptr<AbstractLiteral>>& alhs = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>&>(this->getReference());
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ (long) alhs.size() }));
		delete factory;
		return ret;
	}

	/// ========== CONCRETE SET ==========

	void ConcreteSet::print(std::ostream& os) const
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> vec(std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>>(this->getValue()));
		if (vec.empty()) os << "{ }";
		else {
			os << "{ " << **vec.begin();
			std::for_each(std::next(vec.begin()), vec.end(), [&os](const std::shared_ptr<AbstractLiteral>& val) {
				os << ", " << *val;
				});
			os << " }";
		}
		return;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::operator==(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> slhs(std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>>(this->getValue()));
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> srhs(std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs == srhs }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::operator!=(std::shared_ptr<AbstractLiteral> rhs) const
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> slhs(std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>>(this->getValue()));
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> srhs(std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>>(rhs->getUnderlying()));
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs != srhs }));
		delete factory;
		return ret;
	}

	void ConcreteSet::ordered_list_insert_single(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		slhs.insert(rhs);
		_V.insert(rhs);
		return;
	}

	void ConcreteSet::ordered_list_remove_single(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		slhs.erase(slhs.find(rhs));
		_V.erase(_V.find(rhs));
		return;
	}

	void ConcreteSet::ordered_list_clear_elements()
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		slhs.clear();
		_V.clear();
		return;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_check_empty()
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs.empty() }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_check_size()
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ (long) slhs.size() }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_count_single(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		BaseCreator* factory(new IntegerCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ (long) slhs.count(rhs) }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_contains_single(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		BaseCreator* factory(new BooleanCreator());
		std::shared_ptr<AbstractObject> ret(factory->createObject({ slhs.contains(rhs) }));
		delete factory;
		return ret;
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_find_element(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		return *slhs.find(rhs);
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_lower_bound(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		return *slhs.lower_bound(rhs);
	}

	std::shared_ptr<AbstractObject> ConcreteSet::ordered_list_upper_bound(std::shared_ptr<AbstractLiteral> rhs)
	{
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>& slhs = std::any_cast<std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp>&>(this->getReference());
		if (rhs->getType().name == "Variable") rhs = std::any_cast<std::shared_ptr<AbstractLiteral>>(rhs->getValue());
		return *slhs.upper_bound(rhs);
	}

	/// ========== CONCRETE VARIABLE ==========

	std::any ConcreteVariable::setValue(std::shared_ptr<AbstractObject> val)
	{
		if (val->getType().name == "Variable") val = std::any_cast<std::shared_ptr<AbstractLiteral>>(val->getValue());
		value = std::static_pointer_cast<AbstractLiteral>(val);
		_V = std::static_pointer_cast<AbstractLiteral>(val);
		return val;
	}

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

	std::shared_ptr<AbstractObject> ContainerCreator::createObject(std::vector<std::any> args)
	{
		std::vector<std::shared_ptr<AbstractLiteral>> vec = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(args[0]);
		std::vector<std::shared_ptr<AbstractLiteral>> val(vec.begin(), vec.end());
		TypeInformation ty(std::any_cast<TypeInformation>(args[1]));
		return std::make_shared<ConcreteArray>(val, ty);
	}

	std::shared_ptr<AbstractObject> PairCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> lcont = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		std::vector<std::shared_ptr<AbstractLiteral>> vec = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(std::static_pointer_cast<AbstractContainer>(lcont)->getValue());
		std::pair<std::shared_ptr<AbstractLiteral>, std::shared_ptr<AbstractLiteral>> val(vec[0], vec[1]);
		TypeInformation ty(std::any_cast<TypeInformation>(args[1]));
		return std::make_shared<ConcretePair>(val, ty);
	}

	std::shared_ptr<AbstractObject> ArrayCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> lcont = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		std::vector<std::shared_ptr<AbstractLiteral>> vec = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(std::static_pointer_cast<AbstractContainer>(lcont)->getValue());
		std::vector<std::shared_ptr<AbstractLiteral>> val(vec.begin(), vec.end());
		TypeInformation ty(std::any_cast<TypeInformation>(args[1]));
		return std::make_shared<ConcreteArray>(val, ty);
	}

	std::shared_ptr<AbstractObject> SetCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> lcont = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		std::vector<std::shared_ptr<AbstractLiteral>> vec = std::any_cast<std::vector<std::shared_ptr<AbstractLiteral>>>(std::static_pointer_cast<AbstractContainer>(lcont)->getValue());
		std::multiset<std::shared_ptr<AbstractLiteral>, ObjectComp> val(vec.begin(), vec.end());
		TypeInformation ty(std::any_cast<TypeInformation>(args[1]));
		return std::make_shared<ConcreteSet>(val, ty);
	}

	std::shared_ptr<AbstractObject> VariableCreator::createObject(std::vector<std::any> args)
	{
		std::shared_ptr<AbstractLiteral> val = std::any_cast<std::shared_ptr<AbstractLiteral>>(args[0]);
		TypeInformation ty = { "Variable", {std::any_cast<TypeInformation>(args[1])} };
		std::string name = std::any_cast<std::string>(args[2]);
		bool isConst = std::any_cast<bool>(args[3]);
		bool isStatic = std::any_cast<bool>(args[4]);
		return std::make_shared<ConcreteVariable>(val, ty, name, isConst, isStatic);
	}

	std::shared_ptr<AbstractObject> FunctionCreator::createObject(std::vector<std::any> args)
	{
		std::any val = args[0];
		TypeInformation ty = { "Function", {std::any_cast<TypeInformation>(args[1])} };
		std::string name = std::any_cast<std::string>(args[2]);
		std::unordered_set<std::string> templ = std::any_cast<std::unordered_set<std::string>>(args[3]);
		std::vector<std::shared_ptr<ConcreteVariable>> params = std::any_cast<std::vector<std::shared_ptr<ConcreteVariable>>>(args[4]);
		std::shared_ptr<GenericScope> scope = std::any_cast<std::shared_ptr<GenericScope>>(args[5]);
		return std::make_shared<ConcreteFunction>(val, ty, name, templ, params, scope);
	}

	std::shared_ptr<AbstractObject> ClassCreator::createObject(std::vector<std::any> args)
	{
		std::any val = args[0];
		TypeInformation ty = { "Class", {}};
		std::string name = std::any_cast<std::string>(args[1]);
		std::unordered_set<std::string> templ = std::any_cast<std::unordered_set<std::string>>(args[2]);
		std::shared_ptr<GenericScope> scope = std::any_cast<std::shared_ptr<GenericScope>>(args[3]);
		return std::make_shared<ConcreteClass>(val, ty, name, templ, scope);
	}

	/// ========== GENERIC SCOPE ==========

	std::shared_ptr<AbstractObject> GenericScope::findMember(std::string& name) const
	{
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>>::const_iterator ret = members.find(name);
		if (ret == members.end()) {
			if (parent == nullptr) return nullptr;
			return parent->findMember(name);
		}
		return ret->second;
	}

	/// ========== BLOCK SCOPE ==========

	std::shared_ptr<AbstractObject> BlockScope::findMember(std::string& name) const
	{
		std::unordered_map<std::string, std::shared_ptr<AbstractObject>>::const_iterator ret = variables.find(name);
		if (ret == variables.end()) {
			if (parent == nullptr) return generic->findMember(name);
			return parent->findMember(name);
		}
		return ret->second;
	}

}