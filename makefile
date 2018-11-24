all: main.o anymal.o state.o time.o
	g++ main.o anymal.o state.o time.o -o main

main.o: main.cpp
	g++ -c -o main.o main.cpp

anymal.o: Anymal.cpp
	g++ -c -o anymal.o Anymal.cpp

state.o: AnymalState.cpp
	g++ -c -o state.o AnymalState.cpp

time.o: AnymalTime.cpp
	g++ -c -o time.o AnymalTime.cpp

clean:
	rm *.o main