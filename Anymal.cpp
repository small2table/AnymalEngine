#include "Anymal.hpp"

namespace anymal{

//-------------------- Constructors --------------------//

Anymal::Anymal(){
	current_state_id = -1;

	// set up initial environments
	environ.setIntegerValue("__STATE_MODIFIED_TO", -1);
	environ.setIntegerValue("__STATE_LAST_WORKED", -1);
	environ.setBoolValue("__STATE_MODIFIED", false);
}

Anymal::~Anymal(){
	for(auto iter = states.begin(); iter != states.end(); ++iter){
		delete iter->second;
	}
}

//-------------------- update --------------------//

void Anymal::update(){
	long long elapsed = time.tick();

	if(current_state_id != -1){
		environ.setLongLongValue("__STATE_ELAPSED", elapsed);
		states[current_state_id]->work(environ);
		environ.setIntegerValue("__STATE_LAST_WORKED", current_state_id);

		if(environ.getBoolValue("__STATE_MODIFIED")){
			int new_id = environ.getIntegerValue("__STATE_MODIFIED_TO");
			current_state_id = new_id;
		}
	}
}

//-------------------- states --------------------//

void Anymal::setState(AnymalState *state){
	states[state->getID()] = state;
}

AnymalState* Anymal::getState(int id){
	return states[id];
}

//-------------------- states --------------------//

void Anymal::setEnvironment(AnymalEnvironment& environ){
	environ = environ;
}

AnymalEnvironment& Anymal::getEnvironment(){
	return environ;
}

void Anymal::setCurrentState(int id){
	current_state_id = id;
}

int Anymal::getCurrentState(){
	return current_state_id;
}

}