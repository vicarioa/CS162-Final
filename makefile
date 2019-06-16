ioutput: main.o Character.o Hero.o Spaces.o ChildSpaces.o Game.o Validate.o Shadow.o
	g++ -std=c++0x main.o Character.o Hero.o Spaces.o ChildSpaces.o Game.o Validate.o Shadow.o -o fight
main.o: main.cpp
	g++ -std=c++0x -c  main.cpp
Character.o: Character.cpp Character.hpp
	g++ -std=c++0x -c Character.cpp
Hero.o: Hero.cpp Hero.hpp
	g++ -std=c++0x -c Hero.cpp
Spaces.o: Spaces.cpp Spaces.hpp
	g++ -std=c++0x -c Spaces.cpp
ChildSpaces.o: ChildSpaces.cpp ChildSpaces.hpp
	g++ -std=c++0x -c ChildSpaces.cpp
Game.o: Game.cpp Game.hpp
	g++ -std=c++0x -c Game.cpp
Validate.o: Validate.cpp Validate.hpp
	g++ -std=c++0x -c Validate.cpp
Shadow.o: Shadow.cpp Shadow.hpp
	g++ -std=c++0x -c Shadow.cpp
clean:
	rm *.o fight
