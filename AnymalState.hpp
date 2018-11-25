/*
	AnymalState.hpp
	- holding state information

	Author @ Kihoon Kwon (kwon9804@kaist.ac.kr)
	Editor @ Juan Lee (juanlee@kaist.ac.kr)
*/

#ifndef __ANYMAL_STATE__
#define __ANYMAL_STATE__

#include "AnymalEnvironment.hpp"
#include <map>
#include <cstdarg>
#include <string>
#include <functional>

namespace anymal {

class AnymalState {
private:
	int state_id;
	std::string description;

	std::function<void (AnymalEnvironment&)> simple_worker;

public:
	AnymalState(int _id);
	AnymalState(int _id, std::function<void (AnymalEnvironment&)> worker);

public:
	virtual void work(AnymalEnvironment &env);

	int getID();
	void setID(int id);

	std::string getDescription();
	void setDescription(std::string description);

	//-------------------- Multi-state --------------------//

	class ZIP;
};

class AnymalState::ZIP{
private:
	std::map<int, AnymalState*> zip;

public:
	ZIP(int num, ...);

public:
	AnymalState* getState(int id);
	void setState(AnymalState* state);
};

}

#endif /* __ANYMAL_STATE__ */
