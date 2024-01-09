#include "colors.h"
#include "game.h"
#include <iostream>
#include <raylib.h>

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
    InitWindow(500, 620, "raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("assets/fonts/monogram.ttf", 64, 0, 0);

    Game game = Game();
    while (!WindowShouldClose()) {
        game.HandleInput();

        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 32, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 32, 2, WHITE);

        if (game.gameOver) {
            DrawTextEx(font, "Game Over", {320, 450}, 32, 2, WHITE);
        }

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 scoreTextSize = MeasureTextEx(font, scoreText, 32, 2);

        DrawRectangleRounded({320, 50, 170, 60}, 0.3, 6, lightBlue);
        DrawTextEx(font, scoreText, {320 + (170 - scoreTextSize.x) / 2, 65}, 32, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
