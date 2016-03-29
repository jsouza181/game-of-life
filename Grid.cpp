#include <chrono>
#include <iostream>
#include <random>
#include "Grid.h"

Grid::Grid (int xDimension, int yDimension)
{
	width = xDimension;
	height = yDimension;
	//Resize the grid to accomadate user-provided dimensions.
	cells.resize(height, vector<Cell>(width, Cell()) );

	randomizeGrid();

}

void Grid::print ()
{
	for(auto& i : cells)
	{
		for(auto& cell : i)
		{
			if(cell.alive == true)
				cout << 'x';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	cout << endl;
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
			if(cells[i][j].alive == false) // Cell is dead
			{
				if(findLiveNeighbors(i, j) == 3)
					cells[i][j].alive = true;
			}
			else // Cell is alive
			{

			}
		}
	}
/*
	for(auto& i : cells)
		for(aut&j : i)
	*/
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

// Randomly populate cells to setup starting pattern.
void Grid::randomizeGrid()
{
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 1);

	for(auto& i : cells)
	{
		for(auto& cell : i)
		{
			if(distribution(generator) == 1)
				cell.alive = true;
		}
	}
}
