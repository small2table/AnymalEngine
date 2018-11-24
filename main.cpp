#include <iostream>
using namespace std;

#include "AnymalVariable.hpp"
using namespace Anymal;

int main(){
	AnymalVariable<float> floatVariable("hunger");
	floatVariable.changeValue(new float(3.14));
	cout<< *floatVariable.getValue() << endl;

	AnymalVariable<string> stringVariable("name");
	stringVariable.changeValue(new string("new name"));
	cout<< *stringVariable.getValue() << endl;

	return 0;
}