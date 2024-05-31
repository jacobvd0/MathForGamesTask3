#include "TankTurret.h"

void TankTurret::OnUpdate(float deltaTime)
{
	hitbox.SetVars(GetWorldPosition() - (Sprite->width / 2), GetWorldPosition() + (Sprite->height / 2));

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



	// Turret shooting
	cooldownTimer += deltaTime;
	if (IsKeyDown(KeyboardKey::KEY_SPACE)) { // space
		if (shootCooldown <= cooldownTimer) {
			bool success = false;

			// Loops through all bullets in the array to find a null one
			for (int i = 0; i < 100; i++) {
				if (bullets[i] == nullptr) {
					bullets[i] = new TankBullet;
					bullets[i]->Sprite = new raylib::Texture2D("res/bulletBlue1_outline.png");
					bullets[i]->SetLocalPosition(GetWorldPosition() + (GetForward() * 73));
					bullets[i]->SetLocalRotation(GetWorldRotation());

					raylib::Texture2D tmpSprite("res/bulletBlue1_outline.png");

					bullets[i]->hitbox.SetVars(bullets[i]->GetWorldPosition() - (tmpSprite.width / 2), bullets[i]->GetWorldPosition() + (tmpSprite.height / 2));
					success = true;
					cooldownTimer = 0;
					break;
				}
			}
			// Prints out a debug message if theres no room left in the array
			// this shouldn't happen since bullets despawning free up space
			if (!success) { std::cout << "No space in the bullets array\n"; }
		}
	}

	// Updates for tank bullets
	for (int i = 0; i < 100; i++) {
		if (bullets[i] != nullptr) {
			int screenWidth = GetScreenWidth();
			int screenHeight = GetScreenHeight();

			// Checks if the bullet is older than the max time
			if (bullets[i]->aliveTime >= bullets[i]->maxAliveTime) {
				delete bullets[i]->Sprite;
				bullets[i]->Sprite = nullptr;

				delete bullets[i];
				bullets[i] = nullptr;
			}

			// Checking if the bullet goes past the left and top of the screen
			else if (bullets[i]->GetLocalPosition().x <= -10 || bullets[i]->GetLocalPosition().y <= -10) {
				delete bullets[i]->Sprite;
				bullets[i]->Sprite = nullptr;

				delete bullets[i];
				bullets[i] = nullptr;
			}
		
			// Checking if the bullet goes past the right and bottom of the screen
			else if (bullets[i]->GetLocalPosition().x >= (screenWidth + 10) || bullets[i]->GetLocalPosition().y >= (screenHeight + 10)) {
				delete bullets[i]->Sprite;
				bullets[i]->Sprite = nullptr;

				delete bullets[i];
				bullets[i] = nullptr;
			}

			// Updates the bullet
			else {
				bullets[i]->Update(deltaTime);
				math::Vector3 turretWorldPos = GetWorldPosition();
				raylib::Texture2D tmpSprite("res/bulletBlue1_outline.png");

				bullets[i]->hitbox.SetVars(bullets[i]->GetWorldPosition() - (tmpSprite.width / 2), bullets[i]->GetWorldPosition() + (tmpSprite.height / 2));
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
