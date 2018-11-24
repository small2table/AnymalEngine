/*
	AnymalEnvironment.hpp
	- environments

	Author @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_ENVIRONMENT__
#define __ANYMAL_ENVIRONMENT__

#include <map>
#include <string>

namespace anymal {

class AnymalEnvironment{
private:
	std::map<std::string, std::string> variables;

public:
	void setStringValue(std::string key, std::string value);
	void setIntegerValue(std::string key, int value);
	void setFloatValue(std::string key, float value);
	void setBoolValue(std::string key, bool value);
	void setLongValue(std::string key, long value);
	void setLongLongValue(std::string key, long long value);

	std::string getStringValue(std::string key);
	int getIntegerValue(std::string key);
	float getFloatValue(std::string key);
	bool getBoolValue(std::string key);
	long getLongValue(std::string key);
	long long getLongLongValue(std::string key);

public:
	bool getStateModified();
	int getPreviousState();
	long long getElapsedTime();

	void setNextState(int id);
};

}

#endif /* __ANYMAL_ENVIRONMENT__ */