#
#	File: Makefile
#	Description: This is the script to automatically compile everything into an executable
#	Date: Monday, March 16th 2020 1:01 PM
#

CXX = g++
CXXFLAGS = -Wall -O2
CXXLIBS = -lsfml-graphics -lsfml-window -lsfml-system

cubefight: obj/Release/main.o obj/Release/Game.o obj/Release/Player.o obj/Release/Bullet.o obj/Release/Enemy.o obj/Release/Lehmer.o 
	$(CXX) $(CXXFLAGS) -o bin/Release/cubefight obj/Release/main.o obj/Release/Game.o obj/Release/Player.o obj/Release/Bullet.o obj/Release/Enemy.o obj/Release/Lehmer.o $(CXXLIBS)

obj/Release/main.o: src/main.cpp include/Game.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/Release/main.o $(CXXLIBS)

obj/Release/Game.o: include/data.h include/Game.h include/Player.h include/Bullet.h include/Enemy.h include/Lehmer.h
	$(CXX) $(CXXFLAGS) -c src/Game.cpp -o obj/Release/Game.o $(CXXLIBS)

obj/Release/Player.o: include/data.h include/Player.h include/Bullet.h 
	$(CXX) $(CXXFLAGS) -c src/Player.cpp -o obj/Release/Player.o $(CXXLIBS)

obj/Release/Bullet.o: include/data.h include/Bullet.h
	$(CXX) $(CXXFLAGS) -c src/Bullet.cpp -o obj/Release/Bullet.o $(CXXLIBS)

obj/Release/Enemy.o: include/data.h include/Bullet.h include/Player.h
	$(CXX) $(CXXFLAGS) -c src/Enemy.cpp -o obj/Release/Enemy.o $(CXXLIBS)

obj/Release/Lehmer.o: include/data.h
	$(CXX) $(CXXFLAGS) -c src/Lehmer.cpp -o obj/Release/Lehmer.o $(CXXLIBS)

clean:
	rm bin/Release/cubefight obj/Release/main.o obj/Release/Game.o obj/Release/Player.o obj/Release/Bullet.o obj/Release/Enemy.o obj/Release/Lehmer.o
