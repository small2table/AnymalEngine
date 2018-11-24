#include "Anymal.hpp"

namespace anymal{

//-------------------- Constructors --------------------//

Anymal::Anymal(){
}

Anymal::Anymal(AnymalState state){
	this->state = state;
}

Anymal::~Anymal(){
}

//-------------------- States --------------------//

AnymalState Anymal::setState(AnymalState state){
	AnymalState old = this->state;
	this->state = state;
	return old;
}

AnymalState Anymal::getState(){
	return this->state;
}

//-------------------- Variables --------------------//

float Anymal::getVariable(std::string type){
	if(this->variables.find(type) == this->variables.end())
		return -1;
	return this->variables.find(type)->second;
}

float Anymal::setVariable(std::string type, float variable){
	float old = this->getVariable(type);
	this->variables[type] = variable;
	return old;
}

}