/*
	Hamster.hpp
	- implementation example for hamster

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __HAMSTER__
#define __HAMSTER__

#include "Anymal.hpp"
#include "AnymalState.hpp"
#include "AnymalEnvironment.hpp"
using namespace anymal;

enum {
	SLEEP,
	SIT,
	EAT,
	DRINK,
};

//-------------------- SLEEP STATE --------------------//

class sleepState: public AnymalState{
public:
	sleepState();

	void work(AnymalEnvironment& env);
};

sleepState::sleepState()
	: AnymalState(SLEEP)
{
	setDescription("Hamster is Sleeping...");
}

void sleepState::work(AnymalEnvironment& env){
	env.setFloatValue("tired", env.getFloatValue("tired") - env.getFloatValue("tired_decrement"));

	float tired = env.getFloatValue("tired");
	if(tired < env.getFloatValue("tired_criteria")){
		env.setNextState(SIT);
	}
}

//-------------------- SIT STATE --------------------//

class sitState: public AnymalState{
public:
	sitState();

	void work(AnymalEnvironment& env);
};

sitState::sitState()
	: AnymalState(SIT)
{
	setDescription("Hamster is sitting! It is awake!");
}

void sitState::work(AnymalEnvironment& env){
	env.setFloatValue("tired", env.getFloatValue("tired") + env.getFloatValue("tired_increment"));
	env.setFloatValue("hungry", env.getFloatValue("hungry") + env.getFloatValue("hungry_increment"));

	float tired = env.getFloatValue("tired");
	if(tired > env.getFloatValue("tired_criteria")){
		env.setNextState(SLEEP);
	}

	float hungry = env.getFloatValue("hungry");
	if(hungry > env.getFloatValue("hungry_criteria")){
		env.setNextState(EAT);
	}
}

//-------------------- EAT STATE --------------------//

class eatState: public AnymalState{
public:
	eatState();

	void work(AnymalEnvironment& env);
};

eatState::eatState()
	: AnymalState(EAT)
{
	setDescription("Don't touch! I am eating");
}

void eatState::work(AnymalEnvironment& env){
	env.setFloatValue("thirsty", env.getFloatValue("thirsty") + env.getFloatValue("thirsty_increment"));
	env.setFloatValue("hungry", env.getFloatValue("hungry") - env.getFloatValue("hungry_decrement"));

	float hungry = env.getFloatValue("hungry");
	if(hungry < env.getFloatValue("hungry_criteria")){
		env.setNextState(SIT);
	}

	float thirsty = env.getFloatValue("thirsty");
	if(thirsty > env.getFloatValue("thirsty_criteria")){
		env.setNextState(EAT);
	}
}

//-------------------- DRINK STATE --------------------//

class drinkState: public AnymalState{
public:
	drinkState();

	void work(AnymalEnvironment& env);
};

drinkState::drinkState()
	: AnymalState(DRINK)
{
	setDescription("You want to drink with me?");
}

void drinkState::work(AnymalEnvironment& env){
	env.setFloatValue("thirsty", env.getFloatValue("thirsty") - env.getFloatValue("thirsty_decrement"));

	float thirsty = env.getFloatValue("thirsty");
	if(thirsty < env.getFloatValue("thirsty_criteria")){
		env.setNextState(EAT);
	}
}

//-------------------- HAMSTER --------------------//

class Hamster: public Anymal{
public:
	Hamster();
	~Hamster();

	void initStates();
	void initValues();
};

Hamster::Hamster()
: Anymal(){
	initStates();
	initValues();
}

Hamster::~Hamster(){
	getEnvironment().saveEnvironment("hamster.environ");
}

void Hamster::initStates(){
	setState(new sleepState);
	setState(new sitState);
	setState(new eatState);
	setState(new drinkState);

	setCurrentState(SIT);
}

void Hamster::initValues(){
	getEnvironment().loadEnvironment("hamster.environ");
}

#endif