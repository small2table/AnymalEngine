/*
	AnymalVariable.hpp
	- holding variables

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_VARIABLE__
#define __ANYMAL_VARIABLE__

#include <string>

namespace anymal{

class AnymalVariableTemplate {
public:
	AnymalVariableTemplate(const std::string& name)
	: type(name){}

private:
	std::string type;
};

template <typename T>
class AnymalVariable : public AnymalVariableTemplate {
private:
	T *value;

public:
	AnymalVariable() : AnymalVariableTemplate(""), value(NULL) {}
	AnymalVariable(std::string type) : AnymalVariableTemplate(type), value(NULL) {}
	AnymalVariable(std::string type, T *_value) : AnymalVariableTemplate(type), value(_value) {}
	~AnymalVariable();

public:
	std::string getType();
	std::string changeType(std::string type);

	T* getValue();
	T* changeValue(T* value);

public:
	friend class AnymalEngine;
};

//-------------------- Constructors --------------------//

template <typename T>
AnymalVariable<T>::~AnymalVariable(){
	if(this->value != NULL){
		delete this->value;
	}
}

//-------------------- Operations --------------------//

template <typename T>
T* AnymalVariable<T>::getValue(){
	return this->value;
}

template <typename T>
T* AnymalVariable<T>::changeValue(T* value){
	T *old = this->value;
	this->value = value;
	return old;
}

template <typename T>
std::string AnymalVariable<T>::getType(){
	return this->type;
}

template <typename T>
std::string AnymalVariable<T>::changeType(std::string type){
	std::string old = this->type;
	this->type = type;
	return old;
}

}

#endif /* __ANYMAL_VARIABLE__ */