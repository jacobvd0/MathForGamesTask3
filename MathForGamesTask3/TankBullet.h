#pragma once
#include "SpriteObject.h"
class TankBullet : public SpriteObject
{
public:
	float aliveTime = 0.0f;
	float maxAliveTime = 10.0f;
protected:
	void OnUpdate(float deltaTime) override;
	//void OnDraw() override;
};

