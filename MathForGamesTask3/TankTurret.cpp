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
	//Translate(0, (rotation * deltaTime) * 22);
}
