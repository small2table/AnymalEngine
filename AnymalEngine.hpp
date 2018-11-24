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
	AnymalState *state;
	std::map<std::string, AnymalVariableTemplate* > variables;

public:
	AnymalEngine();
	AnymalEngine(AnymalState *state);
	~AnymalEngine();

public:
	AnymalState* changeState(AnymalState *state);
	AnymalState* getState();

	AnymalVariableTemplate* findVariable(std::string type);
};

}

#endif /* __ANYMAL_ENGINE__ */