/*
	Anymal.hpp
	- engine running and managing states and variables

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_ENGINE__
#define __ANYMAL_ENGINE__

#include "AnymalEnvironment.hpp"
#include "AnymalState.hpp"
#include "AnymalTime.hpp"

#include <string>
#include <map>
#include <functional>

namespace anymal{

class Anymal {
private:
	AnymalEnvironment env;
	AnymalTime time;
	std::map<int, AnymalState*> states;
	int current_state_id;

public:
	Anymal();
	~Anymal();

public:
	void update();

	void setState(AnymalState* state);
	void setState(int id, std::function<void (AnymalEnvironment&)> worker);
	AnymalState* getState(int id);

	void setCurrentState(int id);
	int getCurrentState();

	void setEnvironment(AnymalEnvironment &env);
	AnymalEnvironment& getEnvironment();
};

}

#endif /* __ANYMAL_ENGINE__ */