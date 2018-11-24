#include "AnymalTime.hpp"

namespace anymal {

AnymalTime::AnymalTime() {
	this->prev = std::chrono::high_resolution_clock::now();
}

AnymalTime::~AnymalTime() {

}

long long AnymalTime::tick() {
		
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->prev) ;
	this->prev = now;
	return dur.count();
}

}