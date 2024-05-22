#include "TankBullet.h"

void TankBullet::OnUpdate(float deltaTime)
{
	aliveTime += deltaTime;

	// Bullet Movement
	const float MOVESPEED = 250.0f;
	math::Vector3 finalMove = GetForward() * (MOVESPEED * deltaTime);
	Translate(finalMove);
	
}