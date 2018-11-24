#ifndef __ANYMAL_STATE__
#define __ANYMAL_STATE__

#include <string>
#include <list>
#include <cstdarg>

using namespace std;

namespace anymal {
	class AnymalState {
	private:
		string name;
	public:
	private:
	public:
		AnymalState(string name);
		~AnymalState();

		void setStateName(string name);
		string getStateName();

		// return cycle of states
		static list<string> * zip(int nameNum, ...);

	};
}


#endif
