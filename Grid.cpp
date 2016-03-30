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
	cout << "\n\n\n\n\n";
	for(auto i : cells)
	{
		for(auto cell : i)
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
			int neighborCount = findLiveNeighbors(i, j);

			if(cells[i][j].alive == false) // Cell is dead
			{
				if(neighborCount == 3)
					cells[i][j].active = true;
			}
			else // Cell is alive
			{
				if(neighborCount < 2 || neighborCount > 3)
					cells[i][j].active = true;
			}
		}
	}

	// Change the states of all cells that were set to change.
	for(auto& i : cells)
		for(auto& cell : i)
		{
			if(cell.active == true)
			{
				if(cell.alive == true)
					cell.alive = false;
				else
					cell.alive = true;

				cell.active = false;
			}
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

// Randomly populate cells to setup starting pattern.
// Cells are more likely to be generated as dead than alive.
void Grid::randomizeGrid()
{
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 7);

	for(auto& i : cells)
	{
		for(auto& cell : i)
		{
			if(distribution(generator) == 0)
				cell.alive = true;
		}
	}
}
