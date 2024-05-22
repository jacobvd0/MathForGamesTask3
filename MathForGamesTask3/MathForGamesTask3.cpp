#include <iostream>
#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankTurret.h"


int main()
{
    // Creating the raylib window
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "MathForGames - Task 3");

    SetTargetFPS(60);

    // Sprites
    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");
    raylib::Texture2D turretSprite("res/tankBlue_barrel2_outline.png");

    // Creating the player
    TankPlayer Player;
    Player.Sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

    // Creating the tank's turret
    TankTurret PlayerTurret;
    PlayerTurret.Sprite = &turretSprite;
    PlayerTurret.SetLocalPosition(0,0);
    PlayerTurret.SetParent(&Player);
    PlayerTurret.Origin = math::Vector3(0, 0.5, 0);

    // Game Loop
    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();
        PlayerTurret.Update(deltaTime);
        Player.Update(deltaTime);        

        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            Player.Draw();
            PlayerTurret.Draw();
        }
        EndDrawing();
    }
    return 0;

}