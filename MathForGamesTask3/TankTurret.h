#pragma once
#include "SpriteObject.h"
class TankTurret : public SpriteObject
{
protected:
	void OnUpdate(float deltaTime) override;
};

