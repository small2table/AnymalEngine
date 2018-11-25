#include "Anymal.hpp"

namespace anymal{

//-------------------- Constructors --------------------//

Anymal::Anymal(){
	current_state_id = -1;

	// set up initial envments
	env.setIntegerValue("__STATE_MODIFIED_TO", -1);
	env.setIntegerValue("__STATE_LAST_WORKED", -1);
	env.setBoolValue("__STATE_MODIFIED", false);
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
		env.setLongLongValue("__STATE_ELAPSED", elapsed);
		states[current_state_id]->work(env);
		env.setIntegerValue("__STATE_LAST_WORKED", current_state_id);

		if(env.getBoolValue("__STATE_MODIFIED")){
			int new_id = env.getIntegerValue("__STATE_MODIFIED_TO");
			current_state_id = new_id;
		}
	}
}

//-------------------- states --------------------//

void Anymal::setState(AnymalState *state){
	states[state->getID()] = state;
}

void Anymal::setState(int id, std::function<void (AnymalEnvironment&)> worker){
	states[id] = new AnymalState(id, worker);
}

AnymalState* Anymal::getState(int id){
	return states[id];
}

//-------------------- states --------------------//

void Anymal::setEnvironment(AnymalEnvironment& env){
	this->env = env;
}

AnymalEnvironment& Anymal::getEnvironment(){
	return env;
}

void Anymal::setCurrentState(int id){
	current_state_id = id;
}

int Anymal::getCurrentState(){
	return current_state_id;
}

}