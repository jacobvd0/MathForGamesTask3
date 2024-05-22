#pragma once
#include "SpriteObject.h"
#include "TankBullet.h"
class TankTurret : public SpriteObject
{
public:
	TankBullet *bullets[100];
	void InitArray();
	
protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
};

