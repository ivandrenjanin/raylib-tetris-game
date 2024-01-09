#pragma once
#include "raylib.h"
#include <vector>

class Grid {
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool isCellOutside(int row, int column);
    int grid[20][10]{};

private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};