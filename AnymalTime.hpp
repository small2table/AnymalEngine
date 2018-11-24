#ifndef __ANYMAL_TIME__
#define __ANYMAL_TIME__

#include <chrono>

namespace anymal {

class AnymalTime {
private:
	std::chrono::high_resolution_clock::time_point prev;
public:
private:
public:
	AnymalTime();
	~AnymalTime();
	long long tick();
};

}

#endif