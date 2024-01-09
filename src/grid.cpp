#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    int row = 0;
    int column = 0;

    for (row = 0; row < numRows; row++) {
        for (column = 0; column < numCols; column++) {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print() {
    int row = 0;
    int column = 0;

    for (row = 0; row < numRows; row++) {
        for (column = 0; column < numCols; column++) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    int row = 0;
    int column = 0;
    int cellValue;

    for (row = 0; row < numRows; row++) {
        for (column = 0; column < numCols; column++) {
            cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column) {
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false;
    }

    return true;
}
