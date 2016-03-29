CXX = g++
CXXFLAGS = -c -std=c++0x -Wall -O2

GameOfLife: main.o Grid.o
	$(CXX) -o $@ $^

Grid.o: Grid.cpp Grid.h
	$(CXX) $(CXXFLAGS) $^

clean:
	rm -f GameOfLife *.o *.gch
