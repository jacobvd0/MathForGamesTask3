#include "SpriteObject.h"
#include "raylib-cpp-utils.hpp"

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = math::Vector3(0.5f, 0.5f, 0.5f);
	Tint = Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	float rot = GetWorldRotation() * (180.0f / 3.14159265358979323846f);
	math::Vector3 pos = GetWorldPosition();
	math::Vector3 scl = GetWorldScale();

	Sprite->Draw(
		raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
		raylib::Rectangle(pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y),
		raylib::Vector2(Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y),
		rot,
		raylib::Color(Tint.colour));
}
