#ifndef GRID_H
#define GRID_H

#include <vector>

using namespace std;

struct Cell
{
  bool alive;
  bool active; // Will the cell change states next generation?
  Cell() : alive(false), active(false) {}
};

class Grid
{
  private:
    int width, height;
    vector <vector <Cell> > cells;
  public:
    Grid (int xDimension, int yDimension);
    void print();
    void step();
    int findLiveNeighbors(int row, int column);
    void randomizeGrid();
};

#endif
