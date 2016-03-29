#include <iostream>
#include "Grid.h"

Grid::Grid (int xDimension, int yDimension)
{
	width = xDimension;
	height = yDimension;
	//Resize the grid to accomadate user-provided dimensions.
	cells.resize(height, vector<Cell>(width, Cell()) );
}

void Grid::print ()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if(cells[i][j].alive == true)
				cout << 'x';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

// Advance the simulation one generation.
// First, check for any cells who need to change states.
// Lastly, change all of these states simultaneously.
void Grid::step ()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//TESTING:
			if(i > 4 && i < 7 && j > 4 && j < 9)
				cells[i][j].alive = true;

			if(cells[i][j].alive == false) // Cell is dead
			{
				if(findLiveNeighbors(i, j) == 3)
					cells[i][j].alive = true;
			}
			else // Cell is alive
			{

			}
		}
		cout << endl;
	}
}

// Find the number of live neighbors for a given cell
int Grid::findLiveNeighbors(int row, int column)
{
	int neighborCount = 0;

	for(int i = -1; i < 2; ++i) // Check each neighboring row
	{
		if(row + i < 0 || row + i >= height) // Out of row bounds
			continue;
		for(int j = -1; j < 2; ++j) // Check each neighboring column
		{
			if(i == 0 && j == 0) // Do not count self
				continue;
			if(column + j < 0 || column + j >= width) // Out of column bounds
				continue;

			if(cells[row + i][column + j].alive == true)
				neighborCount++;
		}
	}

	return neighborCount;
}
