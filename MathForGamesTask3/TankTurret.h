#pragma once
#include "SpriteObject.h"
#include "TankBullet.h"
class TankTurret : public SpriteObject
{
public:
	TankBullet *bullets[100];
	//void InitArray();

	float cooldownTimer = 0.5f;
	float shootCooldown = 0.5f;
	
protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
};

