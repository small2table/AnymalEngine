#include "AnymalEngine.hpp"

namespace anymal{

//-------------------- Constructors --------------------//

AnymalEngine::AnymalEngine(){

}

AnymalEngine::AnymalEngine(AnymalState state){
	this->state = state;
}

//-------------------- States --------------------//

AnymalState AnymalEngine::changeState(AnymalState state){
	AnymalState old = this->state;
	this->state = state;
	return old;
}

AnymalState AnymalEngine::getState(){
	return this->state;
}

//-------------------- Variables --------------------//

AnymalVariable* AnymalEngine::findVariable(std::string type){
	return this->variables.find(type)->second;
}

AnymalVariable* AnymalEngine::changeVariable(AnymalVariable *variable){
	AnymalVariable *old = NULL;
	if(this->variables.find(variable->type) != this->variables.end())
		old = this->variables.find(variable->type)->second;

	this->variable[variable->type] = variable;
	return old;
}

}