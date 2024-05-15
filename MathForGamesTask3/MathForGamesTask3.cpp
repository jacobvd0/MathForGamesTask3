#include <iostream>
#include "raylib-cpp.hpp"
#include "SpriteObject.h"

int main()
{
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "MathForGames - Task 3");

    SetTargetFPS(60);

    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");

    SpriteObject Player;
    Player.Sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();
        Player.Update(deltaTime);

        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            Player.Draw();
        }
        EndDrawing();
    }
    return 0;
}