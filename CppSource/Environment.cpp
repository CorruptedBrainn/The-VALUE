#include "Environment.h"

using namespace ENVIRONMENT;

environment* environment::lookup(string variable) {
	if (variables.contains(variable)) return this;
	if (parent == nullptr) {
		// Throw an error
		throw 0;
	}
	return parent->lookup(variable);
}

environment::environment(environment* parent) {
	this->parent = parent;
}

any environment::declareVariable(string name, any value, bool constant, bool staticvar) {
	if (variables.contains(name)) {
		// Throw an error
		throw 0;
	}
	variables.insert({ name, value });
	if (constant) constants.insert(name);
	if (staticvar) statics.insert(name);
	return value;
}

any environment::assignVariable(string name, any value) {
	environment* env = lookup(name);
	if (env->constants.contains(name)) {
		// Throw an error
		throw 0;
	}
	env->variables[name] = value;
	return value;
}

any environment::getValue(string name) {
	environment* env = lookup(name);
	return env->variables[name];
}
