#ifndef GRID_H
#define GRID_H

#include <vector>

using namespace std;

class Grid
{
  private:
    int width, height;
    vector <vector <char> > cells;
  public:
    Grid (int xDimension, int yDimension);
    void print();
    void step();
};

#endif
