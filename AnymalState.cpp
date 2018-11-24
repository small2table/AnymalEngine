#include "AnymalState.hpp"

namespace anymal {

AnymalState::AnymalState() {
	this->name = "";
}

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

std::list<AnymalState>* AnymalState::zip(int nameNum, ...) {
	std::list<AnymalState>* cycle = new std::list<AnymalState>();
	va_list ap;
	va_start(ap, nameNum);
	for (int i = 0; i < nameNum; i++) {
		std::string name = (std::string)va_arg(ap, char *);
		cycle->push_back(AnymalState(name));
	}
	va_end(ap);

	return cycle;
}

}