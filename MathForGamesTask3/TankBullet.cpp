#include "TankBullet.h"

void TankBullet::OnUpdate(float deltaTime)
{
	aliveTime += deltaTime;

	// Bullet Movement
	const float MOVESPEED = 25.0f;
	math::Vector3 finalMove = GetForward() * (MOVESPEED * deltaTime);
	Translate(finalMove);
	
}

//void TankBullet::OnDraw()
//{
//	raylib::Texture2D bulletSprite("res/bulletBlue2_outline.png");
//	float rot = GetWorldRotation() * (180.0f / 3.14159265358979323846f);
//	math::Vector3 pos = GetWorldPosition();
//	math::Vector3 scl = GetWorldScale();
//	std::cout << "Drawing bullet\n";
//	bulletSprite.Draw(
//		raylib::Rectangle(0, 0, (float)bulletSprite.width, (float)bulletSprite.height),
//		raylib::Rectangle(pos.x, pos.y, bulletSprite.width * scl.x, bulletSprite.height * scl.y),
//		raylib::Vector2(bulletSprite.width * Origin.x * scl.x, bulletSprite.height * Origin.y * scl.y),
//		rot,
//		raylib::Color(Tint.colour));
//}
