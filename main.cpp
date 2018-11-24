/*
	main.cpp

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#include "Anymal.hpp"
#include "AnymalState.hpp"
#include "AnymalEnvironment.hpp"
using namespace anymal;

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

enum {
	SLEEP,
	SIT,
	EAT,
	DRINK,
};

int main(){
	AnymalState sleep(SLEEP, [](AnymalEnvironment &env){
		env.setFloatValue("tired", env.getFloatValue("tired") - 0.01);

		float tired = env.getFloatValue("tired");
		if(tired < 0.5){
			env.setNextState(SIT);
		}
	});
	sleep.setDescription("Hamster is Sleeping...");

	AnymalState sit(SIT, [](AnymalEnvironment &env){
		env.setFloatValue("tired", env.getFloatValue("tired") + 0.01);
		env.setFloatValue("hungry", env.getFloatValue("hungry") + 0.01);

		float tired = env.getFloatValue("tired");
		if(tired > 0.5){
			env.setNextState(SLEEP);
		}

		float hungry = env.getFloatValue("hungry");
		if(hungry > 0.5){
			env.setNextState(EAT);
		}
	});
	sit.setDescription("Hamster is sitting! It is awake!");

	AnymalState eat(EAT, [](AnymalEnvironment &env){
		env.setFloatValue("thirsty", env.getFloatValue("thirsty") + 0.01);
		env.setFloatValue("hungry", env.getFloatValue("hungry") - 0.01);

		float hungry = env.getFloatValue("hungry");
		if(hungry < 0.5){
			env.setNextState(SIT);
		}

		float thirsty = env.getFloatValue("thirsty");
		if(thirsty > 0.5){
			env.setNextState(EAT);
		}
	});
	eat.setDescription("Don't touch! I am eating");

	AnymalState drink(DRINK, [](AnymalEnvironment &env){
		env.setFloatValue("thirsty", env.getFloatValue("thirsty") - 0.01);

		float thirsty = env.getFloatValue("thirsty");
		if(thirsty < 0.5){
			env.setNextState(EAT);
		}
	});
	drink.setDescription("You want to drink with me?");

	Anymal hamster;
	hamster.setState(&sleep);
	hamster.setState(&sit);
	hamster.setState(&eat);
	hamster.setState(&drink);

	hamster.setCurrentState(SIT);

	hamster.getEnvironment().setFloatValue("tired", 0.1);
	hamster.getEnvironment().setFloatValue("hungry", 0.2);
	hamster.getEnvironment().setFloatValue("thirsty", 0.2);

	while(true){
		hamster.update();

		system("clear");
		cout << hamster.getState(hamster.getCurrentState())->getDescription() << endl << endl;
		cout << "Tired\t| " << hamster.getEnvironment().getFloatValue("tired") << endl;
		cout << "Hungry\t| " << hamster.getEnvironment().getFloatValue("hungry") << endl;
		cout << "Thirsty\t| " << hamster.getEnvironment().getFloatValue("thirsty") << endl;

		usleep(100);
	}
}