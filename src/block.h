#pragma once

#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
    Block();
    int id{};
    std::map<int, std::vector<Position>> cells;
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();
    std::vector<Position> GetCellPosition();

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};