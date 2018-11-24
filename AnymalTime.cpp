#include "AnymalTime.hpp"

namespace anymal {

AnymalTime::AnymalTime() {
	this->prev = std::chrono::system_clock::now();
}

AnymalTime::~AnymalTime() {

}

long long AnymalTime::tick() {
		
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->prev) ;
	this->prev = now;
	return dur.count();
}

std::time_t * AnymalTime::getCurrentTime() {
	this->currentTime = std::chrono::system_clock::to_time_t(this->prev);
	return &(this->currentTime);
}

}