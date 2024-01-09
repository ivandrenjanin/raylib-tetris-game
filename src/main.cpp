#include "game.h"
#include "raylib.h"

int main() {
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);
    Color darkBlue = {44, 44, 127, 255};

    Game game = Game();
    while (!WindowShouldClose()) {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
