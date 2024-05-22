#include "TankTurret.h"


void TankTurret::OnUpdate(float deltaTime)
{
	// Turret Rotation
	const float ROTATESPEED = 2.0f;
	float rotation = 0.0f;

	if (IsKeyDown(KeyboardKey::KEY_Q)) { // left
		rotation -= ROTATESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_E)) { // right
		rotation += ROTATESPEED;
	}

	Rotate(rotation * deltaTime);


	// Turret shooting (WIP)
	// TODO: Make it update each bullet when the tank turret's update function is called and the same with drawing
	// Make it continue in the direction it was shot
	// Set the location and rotation to be correct
	// and probably more
	if (IsKeyDown(KeyboardKey::KEY_SPACE)) { // space
		raylib::Texture2D bulletSprite("res/bulletBlue2_outline.png");
		SpriteObject Bullet;
		Bullet.Sprite = &bulletSprite;
		Bullet.SetLocalPosition(GetWorldPosition());
		BeginDrawing();
		{
			Bullet.Draw();
		}
		EndDrawing();
		
	}
	
}
