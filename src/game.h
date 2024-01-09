#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;

private:
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};