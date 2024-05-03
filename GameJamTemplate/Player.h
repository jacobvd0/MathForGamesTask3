#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:

	Player();
	Player(Vector2 pos, Vector2 scale, Game* game);
	~Player();

	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

private:
	float m_moveSpeed = 300;
	const float m_gravity = 700.f;
	float m_fallSpeed = 0;
	bool canJump = true;
	bool onPlatform = false;
	Rectangle m_groundedRect {0,0,0,0};

	bool jumpFrame;

	void UpdateRect();
};

