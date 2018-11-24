/*
	AnymalState.hpp
	- holding state information

	Author @ Kihoon Kwon (kwon9804@kaist.ac.kr)
*/

#ifndef __ANYMAL_STATE__
#define __ANYMAL_STATE__

#include <string>
#include <list>
#include <cstdarg>

namespace anymal {

class AnymalState {
private:
	std::string name;

public:
	AnymalState(std::string name);
	~AnymalState();

	void setStateName(std::string name);
	std::string getStateName();

	// return cycle of states
	static std::list<std::string> * zip(int nameNum, ...);
};

}

#endif /* __ANYMAL_STATE__ */
