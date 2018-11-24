#include <iostream>
using namespace std;

#include "AnymalEngine.hpp"
using namespace anymal;

int main(){
	AnymalEngine engine(new AnymalState("Initial State"));

	AnymalState *old = engine.changeState(new AnymalState("Update"));
	cout<< old->getStateName() << endl;
	delete old;		// user is responsible for mamory leak

	return 0;
}