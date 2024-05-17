#include "TankPlayer.h"

void TankPlayer::OnUpdate(float deltaTime)
{
	// Tank Movement
	const float MOVESPEED = 150.0f;

	float yMove = 0.0f;

	if (IsKeyDown(KeyboardKey::KEY_W)) {
		yMove += MOVESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_S)) {
		yMove -= MOVESPEED;
	}

	math::Vector3 finalMove = GetForward() * (yMove * deltaTime);

	Translate(finalMove);



	// Tank Rotation
	const float ROTATESPEED = 3.0f;
	float rotation = 0.0f;

	if (IsKeyDown(KeyboardKey::KEY_A)) { // left
		rotation -= ROTATESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_D)) { // right
		rotation += ROTATESPEED;
	}

	Rotate(rotation * deltaTime);
}
