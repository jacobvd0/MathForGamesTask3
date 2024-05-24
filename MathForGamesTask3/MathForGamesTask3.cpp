#include <iostream>
#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankTurret.h"

// TODO: make an array with all objects in it then pass to bullets so the collision checks can be done in TankBullet.cpp

int main()
{
    // Creating the raylib window
    int screenWidth = 800;
    int screenHeight = 600;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "MathForGames - Task 3");

    SetTargetFPS(60);

    // Sprites
    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");
    raylib::Texture2D turretSprite("res/tankBlue_barrel2_outline.png");
    raylib::Texture2D crateSprite("res/crateMetal.png");
    raylib::Texture2D bulletSprite("res/bulletBlue1_outline.png");

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
    

    // Scenery objects
    SpriteObject Crate;
    Crate.Sprite = &crateSprite;
    Crate.SetLocalPosition(screenWidth / 2 + 200, screenHeight / 2 - 150);
    Crate.solid = true; // stops the tank and bullets moving through

    // Game Loop
    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();
        PlayerTurret.Update(deltaTime);
        Player.Update(deltaTime);        
        Crate.Update(deltaTime);



        // Collision checks
        raylib::Rectangle crateRect(Crate.GetWorldPosition().x - Crate.Origin.x-27, Crate.GetWorldPosition().y - 27, crateSprite.width * Crate.GetWorldScale().x, crateSprite.height * Crate.GetWorldScale().y);
        //raylib::Rectangle tankRect(Player.GetWorldPosition().x-42, Player.GetWorldPosition().y - 42, tankSprite.width * Player.GetWorldScale().x, tankSprite.height * Player.GetWorldScale().y);

        //if (CheckCollisionRecs(crateRect, tankRect)) {
        //     
        //}
        
        for (int i = 0; i < 100; i++) {
            if (PlayerTurret.bullets[i] != nullptr) {
                raylib::Rectangle bulletRect(PlayerTurret.bullets[i]->GetWorldPosition().x - 12, PlayerTurret.bullets[i]->GetWorldPosition().y - 8, bulletSprite.width * PlayerTurret.bullets[i]->GetWorldScale().x, bulletSprite.height * PlayerTurret.bullets[i]->GetWorldScale().y);
                if (CheckCollisionRecs(crateRect, bulletRect)) {
                    delete PlayerTurret.bullets[i]->Sprite;
                    PlayerTurret.bullets[i]->Sprite = nullptr;
                    delete PlayerTurret.bullets[i];
                    PlayerTurret.bullets[i] = nullptr;
                }
            }
        }

        // Drawing
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            Crate.Draw();
            Player.Draw();

            // Draws the turret & all existing bullets
            PlayerTurret.Draw();
        }
        EndDrawing();
        

        
    }
    return 0;

}