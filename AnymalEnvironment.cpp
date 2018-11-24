#include "AnymalEnvironment.hpp"

namespace anymal {

//-------------------- set --------------------//

void AnymalEnvironment::setStringValue(std::string key, std::string value){
	variables[key] = value;
}

void AnymalEnvironment::setIntegerValue(std::string key, int value){
	variables[key] = std::to_string(value);
}

void AnymalEnvironment::setFloatValue(std::string key, float value){
	variables[key] = std::to_string(value);
}

void AnymalEnvironment::setBoolValue(std::string key, bool value){
	variables[key] = std::to_string(value);
}

void AnymalEnvironment::setLongValue(std::string key, long value){
	variables[key] = std::to_string(value);
}

void AnymalEnvironment::setLongLongValue(std::string key, long long value){
	variables[key] = std::to_string(value);
}


//-------------------- get --------------------//

std::string AnymalEnvironment::getStringValue(std::string key){
	return variables[key];
}

int AnymalEnvironment::getIntegerValue(std::string key){
	return std::stoi(variables[key]);
}

float AnymalEnvironment::getFloatValue(std::string key){
	return std::stof(variables[key]);
}

bool AnymalEnvironment::getBoolValue(std::string key){
	return variables[key] != "0";
}

long AnymalEnvironment::getLongValue(std::string key){
	return std::stol(variables[key]);
}

long long AnymalEnvironment::getLongLongValue(std::string key){
	return std::stoll(variables[key]);
}

//-------------------- state update --------------------//

bool AnymalEnvironment::getStateModified(){
	return getBoolValue("__STATE_MODIFIED");
}

int AnymalEnvironment::getPreviousState(){
	return getIntegerValue("__STATE_LAST_WORKED");
}

long long AnymalEnvironment::getElapsedTime(){
	return getLongLongValue("__STATE_ELAPSED");
}

void AnymalEnvironment::setNextState(int id){
	if(id != getIntegerValue("__STATE_LAST_WORKED")){
		setBoolValue("__STATE_MODIFIED", true);
		setIntegerValue("__STATE_MODIFIED_TO", id);
	}
}


}