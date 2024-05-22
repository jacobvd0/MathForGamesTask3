#include "TankTurret.h"

void TankTurret::InitArray()
{
	for (int i = 0; i < 100; i++) {
		delete bullets[i];
		bullets[i] = nullptr;
	}
}

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
		bool success = false;

		// Loops through all bullets in the array to find a null one
		for (int i = 0; i < 100; i++) {
			if (bullets[i] == nullptr) {				
				bullets[i] = new TankBullet;
				bullets[i]->Sprite = new raylib::Texture2D("res/bulletBlue1_outline.png");
				bullets[i]->SetLocalPosition(GetWorldPosition());
				bullets[i]->SetLocalRotation(GetWorldRotation());
				std::cout << "Bullet shot num " << i << std::endl;
				success = true;
				break;
			}
		}
		if (!success) { std::cout << "No space in the bullets array\n"; }
		
		
		
	}

	// Updates for tank bullets
	for (int i = 0; i < 100; i++) {
		if (bullets[i] != nullptr) {

			// Checks if the bullet is older than the max time
			if (bullets[i]->aliveTime >= bullets[i]->maxAliveTime) {
				delete bullets[i]->Sprite;
				bullets[i]->Sprite = nullptr;

				delete bullets[i];
				bullets[i] = nullptr;
			}

			// Updates the bullet
			else {
				bullets[i]->Update(deltaTime);
			}
		}
	}
	
}

void TankTurret::OnDraw()
{
	// Draw the turret
	float rot = GetWorldRotation() * (180.0f / 3.14159265358979323846f);
	math::Vector3 pos = GetWorldPosition();
	math::Vector3 scl = GetWorldScale();

	Sprite->Draw(
		raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
		raylib::Rectangle(pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y),
		raylib::Vector2(Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y),
		rot,
		raylib::Color(Tint.colour));


	// Draw all currently existing bullets
	for (int i = 0; i < 100; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Draw();
		}
	}
}
