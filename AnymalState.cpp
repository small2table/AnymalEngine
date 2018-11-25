#include "AnymalState.hpp"

namespace anymal {

//-------------------- Constructor --------------------//

AnymalState::AnymalState(int _id)
	: state_id(_id)
{
	simple_worker = [](AnymalEnvironment &env){};
}	

AnymalState::AnymalState(int _id, std::function<void (AnymalEnvironment&)> worker)
	: state_id(_id), simple_worker(worker)
{}

//-------------------- Work --------------------//

void AnymalState::work(AnymalEnvironment &env){
	simple_worker(env);
}

//-------------------- set & get --------------------//

void AnymalState::setID(int new_id){
	this->state_id = new_id;
}

int AnymalState::getID(){
	return this->state_id;
}

std::string AnymalState::getDescription(){
	return this->description;
}

void AnymalState::setDescription(std::string description){
	this->description = description;
}

//-------------------- Multi-states Helper --------------------//

AnymalState::ZIP::ZIP(int num, ...){
	va_list ap;
	va_start(ap, num);
	for (int i = 0; i < num; i++) {
		AnymalState *state = (AnymalState*)va_arg(ap, AnymalState*);
		zip[state->getID()] = state;
	}
	va_end(ap);
}

AnymalState* AnymalState::ZIP::getState(int id){
	if(zip.find(id) != zip.end() && zip.find(id)->second->getID() == id){
		return zip.find(id)->second;
	}

	std::map<int, AnymalState*>::iterator iter;
	for(iter = zip.begin(); iter != zip.end(); ++iter){
		if(iter->second->getID() == id){
			AnymalState *state = iter->second;

			zip.erase(iter);
			zip[id] = state;

			return state;
		}
	}

	return NULL;
}

void AnymalState::ZIP::setState(AnymalState *state){
	zip[state->getID()] = state;
}

}