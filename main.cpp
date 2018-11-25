/*
	main.cpp

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#include "Anymal.hpp"
#include "AnymalState.hpp"
#include "AnymalEnvironment.hpp"
using namespace anymal;

#include "Hamster.hpp"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	Hamster hamster;

	while(true){
		hamster.update();

		system("clear");
		cout << hamster.getState(hamster.getCurrentState())->getDescription() << endl << endl;
		cout << "Tired\t| " << hamster.getEnvironment().getFloatValue("tired") << endl;
		cout << "Hungry\t| " << hamster.getEnvironment().getFloatValue("hungry") << endl;
		cout << "Thirsty\t| " << hamster.getEnvironment().getFloatValue("thirsty") << endl;

		usleep(500000);
	}
}