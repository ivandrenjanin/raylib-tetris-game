#include "game.h"
#include "raylib.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);
    Color darkBlue = {44, 44, 127, 255};

    Game game = Game();
    while (!WindowShouldClose()) {
        game.HandleInput();

        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
