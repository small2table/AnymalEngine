/*
	AnymalVariable.hpp
	- holding variables

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_VARIABLE__
#define __ANYMAL_VARIABLE__

#include <string>

namespace anymal{

template <typename T>
class AnymalVariable {
private:
	std::string type;
	T *value;

public:
	AnymalVariable();
	AnymalVariable(std::string type);
	AnymalVariable(std::string type, T *value);
	~AnymalVariable();

public:
	std::string getType();
	std::string changeType(std::string type);

	T* getValue();
	T* changeValue(T* value);

public:
	friend AnymalEngine;
};

//-------------------- Constructors --------------------//

template <typename T>
AnymalVariable<T>::AnymalVariable(){
	this->type = "";
	this->value = NULL;
}

template <typename T>
AnymalVariable<T>::AnymalVariable(std::string type){
	this->type = type;
	this->value = NULL;
}

template <typename T>
AnymalVariable<T>::AnymalVariable(std::string type, T* value){
	this->type = type;
	this->value = value;
}

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