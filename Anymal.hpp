/*
	Anymal.hpp
	- engine running and managing states and variables

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_ENGINE__
#define __ANYMAL_ENGINE__

#include <string>
#include <map>

#include "AnymalState.hpp"
#include "AnymalTime.hpp"

namespace anymal{

class Anymal {
private:
	AnymalState state;
	std::map<std::string, float> variables;

public:
	Anymal();
	Anymal(AnymalState state);
	~Anymal();

public:
	AnymalState setState(AnymalState state);
	AnymalState getState();

	float getVariable(std::string type);
	float setVariable(std::string type, float variable);
};

}

#endif /* __ANYMAL_ENGINE__ */