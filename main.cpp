#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include "Grid.h"

using namespace std;

int main(int argc, char ** argv)
{
	int numGens, width, height;

	// Check for valid number of flags.
	if(argc != 4)
	{
			cout << "Invalid number of flags. Please try again.\n";
			return 1;
	}

	stringstream(argv[1]) >> width;
	stringstream(argv[2]) >> height;
	stringstream(argv[3]) >> numGens;

	Grid displayGrid(width, height);
	displayGrid.step();
	displayGrid.print();

	while(numGens > 1)
	{
		displayGrid.step();
		this_thread::sleep_for(chrono::milliseconds(1000));
		displayGrid.print();
		numGens--;
	}
	return 0;
}
