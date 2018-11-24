#include "AnymalState.hpp"

namespace anymal {

AnymalState::AnymalState(std::string name) {
	this->name = name;
}

AnymalState::~AnymalState() {

}

void AnymalState::setStateName(std::string name) {
	this->name = name;
}

std::string AnymalState::getStateName() {
	return this->name;
}

std::list<std::string> * AnymalState::zip(int nameNum, ...) {
	std::list<std::string> * cycle = new std::list<std::string>();
	va_list ap;
	va_start(ap, nameNum);
	for (int i = 0; i < nameNum; i++) {
		cycle->push_back((std::string)va_arg(ap, char *));
	}
	va_end(ap);

	return cycle;
}

}