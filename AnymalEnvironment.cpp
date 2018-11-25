#include "AnymalEnvironment.hpp"
#include <iostream>

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

//-------------------- load & save --------------------//

void AnymalEnvironment::loadEnvironment(std::string from){
	std::ifstream in;
	in.open(from);
	if(in.is_open()){
		std::string line;
		while(getline(in, line)){
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
			if(line == "") continue;

			int separator = line.find_first_of("=");

			std::string key = line.substr(0, separator);
			std::string value = line.substr(separator + 1);

			key.erase(remove_if(key.begin(), key.end(), isspace), key.end());
			value.erase(remove_if(value.begin(), value.end(), isspace), value.end());

			variables[key] = value;
		}
		in.close();
	}
}

void AnymalEnvironment::saveEnvironment(std::string to){
	std::ofstream out;
	out.open(to);

	std::map<std::string, std::string>::iterator iter;
	while(iter != variables.end()){
		out<<iter->first<<"="<<iter->second<<'\n';
		++iter;
	}

	out.close();
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