#include "SpriteObject.h"
#include "raylib-cpp-utils.hpp"

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = Vector3(0.5f, 0.5f, 0.5f);
	Tint = Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	Vector3 pos = GetWorldPosition();
	Vector3 scl = GetWorldScale();

	Sprite->Draw(
		raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
		raylib::Rectangle(pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y),
		raylib::Vector2(Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y),
		GetWorldRotation(), // may need to change this check https://aie.instructure.com/courses/1344/pages/maths-for-games-timing-tutorial
		raylib::Color(Tint.colour));
}
