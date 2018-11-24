/*
	AnymalEngine.hpp
	- engine running and managing states and variables

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_ENGINE__
#define __ANYMAL_ENGINE__

#include <string>
#include <map>

#include "AnymalVariable.hpp"
#include "AnymalState.hpp"

namespace anymal{

class AnymalEngine {
private:
	AnymalState state;
	std::map<std::string, AnymalVariable*> variables;

public:
	AnymalEngine();
	AnymalEngine(AnymalState state);

public:
	AnymalState changeState(AnymalState state);
	AnymalState getState();

	AnymalVariable* findVariable(std::string type);
	AnymalVariable* changeVariable(AnymalVariable *variable);
};

}

#endif /* __ANYMAL_ENGINE__ */