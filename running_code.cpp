/*
	running_code.cpp
	- this is an expected code for running scenario

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

// This is JUST an expected code, not actually running code
// Implemention is your WORK, do not totally depend on this code.

/*
	Includes
	- AnymalEngine

	//TODO:
	- creation method can be modified
	- this provides working methods for Animals
*/
#include <AnymalEngine>
using namespace Anymal

/*
	class Hamster
	- inherited AnymalEngine

	//TODO:
	- define the way to implement inherited functions
*/
class Hamster : public AnymalEngine{
public:
	Hamster();
	~Hamster();

private:
	// Overrides
	void init();								// initialize method

public:
	// Overrides
	void changeVariable(AnymalVariable var);					// way to change variable; factors
	void changeState(AnymalState state = AnymalState::PROPER); 	// way to change states
	void update(AnymalTime time);								// overall update method

private:
	AnymalTime before;
	AnymalState::ZIP SleepCycle;
	AnymalState::ZIP MealCycle;
	AnymalState::ZIP ActivityCycle;
	AnymalState::ZIP InteractionCycle;
	// Any other ...

public:
	// Any other ...
};

/*
	Implementations
*/
Hamster::Hamster() {
	this->init(Hamster::STATE::SITTING); // default state
}

Hamster::Hamster(AnymalState state){
	this->init(state);
}

Hamster::~Hamster() {

}

void Hamster::init(AnymalState state){
	// initiallizing
	before = AnymalTime();
	this->updateState(state);

	SleepCycle = AnymalState.zip(
		Hamster::STATE::SLEEP, 
		Hamster::STATE::SLEEP_TALKING
	);

	MealCycle = AnymalState.zip(
		Hamster::STATE::MEAL, 
		Hamster::STATE::DRINK, 
		Hamster::STATE::ASK_MEAL
	);

	ActivityCycle = AnymalState.zip(
		Hamster::STATE::RUNNING, 
		Hamster::STATE::WALKING, 
		Hamster::STATE::WASHING, 
		Hamster::STATE::SITTING, 
		Hamster::STATE::LYING, 
		Hamster::STATE::STANDING
	);

	InteractionCycle = AnymalState.zip(
		Hamster::STATE::WITH_OBJECT,
		Hamster::STATE::WITH_USER,
		Hamster::STATE::WITH_ENVIRONMENT
	);
}

void Hamster::changeVariable(AnymalVariable var){
	// adopt var changing
	this->findVariable(var->type)->changeValue(var->value);
}

void Hamster::changeState(AnymalState state){
	// adopt state changing
	this->updateState(state);
}

void Hamster::update(AnymalTime time){
	switch(this->getState()){
		case Hamster::STATE::SLEEP:
		case Hamster::STATE::SLEEP_TALKING:
		if(this->findVariable(Hamster::VARIABLE::FATIGUE)->getValue() < CRITERIA_FATIGUE)
			this->updateState();
		else if(AnymalTime.random())
			this->updateState(SleepCycle);
		break;

		case Hamster::STATE::MEAL:
		case Hamster::STATE::DRINK:
		case Hamster::STATE::ASK_MEAL:
		if(this->findVariable(Hamster::VARIABLE::HUNGRY)->getValue() < CRITERIA_HUNGRY
			&& this->findVariable(Hamster::VARIABLE::THIRSTY)->getValue() < CRITERIA_THIRSTY)
			this->updateState();
		else if(AnymalTime.random())
			this->updateState(MealCycle);
		break;

		case Hamster::STATE::RUNNING:
		case Hamster::STATE::WALKING:
		case Hamster::STATE::WASHING:
		case Hamster::STATE::SITTING:
		case Hamster::STATE::LYING:
		case Hamster::STATE::STANDING:
		if(this->findVariable(Hamster::VARIABLE::ACTIVITY)->getValue() < CRITERIA_ACTIVITY
			&& this->findVariable(Hamster::VARIABLE::FATIGUE)->getValue() > CRITERIA_FATIGUE
			&& this->findVariable(Hamster::VARIABLE::HUNGRY)->getValue() > CRITERIA_HUNGRY
			&& this->findVariable(Hamster::VARIABLE::THIRSTY)->getValue() > CRITERIA_THIRSTY)
			this->updateState();
		else if(AnymalTime.random())
			this->updateState(ActivityCycle);
		break;

		case Hamster::STATE::WITH_OBJECT:
		case Hamster::STATE::WITH_USER:
		case Hamster::STATE::WITH_ENVIRONMENT:
		if(this->findVariable(Hamster::VARIABLE::ACTION)->getValue())
			this->updateState();
		else if(AnymalTime.random())
			this->updateState(InteractionCycle);
		break;

		default:
		break;
	}

	before = time;
}

/*
	main: void -> int
*/
int main(){
	Hamster hamster(Hamster::STATE::WASHING);

	AnymalTime time;
	while(true){
		hamster.update(time.tick());

		// Display code using Hamster
	}

	return 0;
}