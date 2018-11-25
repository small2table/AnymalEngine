all: main.o anymal.o environ.o state.o time.o
	g++ main.o anymal.o environ.o state.o time.o -o main -std=c++11

main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++11

anymal.o: Anymal.cpp
	g++ -c Anymal.cpp -o anymal.o -std=c++11

environ.o: AnymalEnvironment.cpp
	g++ -c AnymalEnvironment.cpp -o environ.o -std=c++11

state.o: AnymalState.cpp
	g++ -c AnymalState.cpp -o state.o -std=c++11

time.o: AnymalTime.cpp
	g++ -c AnymalTime.cpp -o time.o -std=c++11

clean:
	rm *.o main