#include "anymal_state.h"
#include <iostream>

AnymalState::AnymalState(string name) {
	this->name = name;
}

AnymalState::~AnymalState() {

}

void AnymalState::setStateName(string name) {
	this->name = name;
}

string AnymalState::getStateName() {
	return this->name;
}

list<string> * AnymalState::zip(int nameNum, ...) {

	list<string> * cycle = new list<string>();
	va_list ap;
	va_start(ap, nameNum);
	for (int i = 0; i < nameNum; i++) {
		cycle->push_back((string)va_arg(ap, char *));
	}
	va_end(ap);

	return cycle;
}