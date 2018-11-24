#include "AnymalEngine.hpp"

namespace anymal{

//-------------------- Constructors --------------------//

AnymalEngine::AnymalEngine()
{
	this->state = NULL;
}

AnymalEngine::AnymalEngine(AnymalState *state){
	this->state = state;
}

AnymalEngine::~AnymalEngine(){
	if(this->state != NULL){
		delete this->state;
	}
}

//-------------------- States --------------------//

AnymalState* AnymalEngine::changeState(AnymalState *state){
	AnymalState *old = this->state;
	this->state = state;
	return old;
}

AnymalState* AnymalEngine::getState(){
	return this->state;
}

//-------------------- Variables --------------------//

AnymalVariableTemplate* AnymalEngine::findVariable(std::string type){
	if(this->variables.find(type) == this->variables.end())
		return NULL;
	return this->variables.find(type)->second;
}

}