#include <iostream>
#include "Grid.h"

Grid::Grid (int xDimension, int yDimension)
{
	width = xDimension;
	height = yDimension;
	//Resize the grid to accomadate user-provided dimensions.
	cells.resize(height, vector<char>(width, ' ') );
}

void Grid::print ()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cout << cells[i][j];
		}
		cout << endl;
	}
}

void Grid::step ()
{

}
