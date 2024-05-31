#pragma once
#include "raylib-cpp.hpp"
#include "Colour.h"
#include "GameObject.h"
#include "AABB.h"

class SpriteObject : public GameObject
{
public:
	raylib::Texture2D* Sprite;
	math::Vector3 Origin;

	Colour Tint;

	SpriteObject();
protected:
	void OnDraw() override;
	void OnUpdate(float deltaTime) override;
};

