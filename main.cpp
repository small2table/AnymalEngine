#include "Anymal.hpp"
using namespace anymal;

class Hamster : public Anymal{
public:
	Hamster();
	Hamster(std::string stateName);
	~Hamster();

private:
	void init(std::string stateName);

public:
	void update(long long time);								// overall update method

private:
	long long elapsed;
	std::list<AnymalState>* SleepCycle;
	std::list<AnymalState>* MealCycle;
	std::list<AnymalState>* ActivityCycle;
	std::list<AnymalState>* InteractionCycle;
};

/*
	Implementations
*/
Hamster::Hamster() : Anymal() {
	this->init("sitting"); // default state
}

Hamster::Hamster(std::string stateName) : Anymal() {
	this->init(stateName);
}

Hamster::~Hamster() {
	delete SleepCycle;
	delete MealCycle;
	delete ActivityCycle;
	delete InteractionCycle;
}

void Hamster::init(std::string stateName){
	elapsed = 0;
	this->setState(AnymalState(stateName));

	SleepCycle = AnymalState::zip(2, 
		"sleep", 
		"sleep_talking"
	);

	MealCycle = AnymalState::zip(3, 
		"meal", 
		"drink", 
		"ask_meal"
	);

	ActivityCycle = AnymalState::zip(6, 
		"running", 
		"walking", 
		"washing", 
		"sitting", 
		"lying", 
		"standing"
	);

	InteractionCycle = AnymalState::zip(3, 
		"with_object",
		"with_user",
		"with_environment"
	);
}

void Hamster::update(long long time){
	//switch(this->getState().getStateName()){
	//default:
	//break;
	//}

	elapsed += time;
	if((int)(elapsed/1000) != ((int)(elapsed-time)/1000)){
		this->setVariable("activity", this->getVariable("activity") + 0.01);
		this->setVariable("fatigue", this->getVariable("fatigue") + 0.01);
		this->setVariable("hungry", this->getVariable("hungry") + 0.01);
		this->setVariable("thirsty", this->getVariable("thirsty") + 0.01);
	}
}

/*
	main: void -> int
*/
int main(){
	Hamster hamster("washing");

	AnymalTime time;
	while(true){
		hamster.update(time.tick());

		// Display code using Hamster
	}

	return 0;
}