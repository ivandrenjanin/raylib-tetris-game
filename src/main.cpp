#include "grid.h"
#include "raylib.h"

int main() {
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);
    Color darkBlue = {44, 44, 127, 255};
    Grid grid = Grid();
    grid.Print();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}
