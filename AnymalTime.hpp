#ifndef __ANYMAL_TIME__
#define __ANYMAL_TIME__

#include <chrono>
#include <ctime>

namespace anymal {

class AnymalTime {
private:
	std::chrono::system_clock::time_point prev;
	std::time_t currentTime;
public:
private:
public:
	AnymalTime();
	~AnymalTime();
	long long tick();
	std::time_t * getCurrentTime();
	
};

}

#endif