#include "Player.h"
#include "EnvironmentBlock.h"

Player::Player()
{
	m_color = GREEN;
}

Player::Player(Vector2 pos, Vector2 scale, Game* game) : GameObject(game)
{
	m_position = pos;
	m_scale = scale;
	UpdateRect();

	m_color = GREEN;
}

Player::~Player()
{

}

void Player::OnUpdate(float deltaTime)
{
	//Implementing Basic WASD + Space for jump

	//if (IsKeyDown(KEY_W))
	//{
	//	m_position.y -= m_speed * deltaTime;
	//}
	//if (IsKeyDown(KEY_S))
	//{
	//	m_position.y += m_speed * deltaTime;
	//}
	if (IsKeyDown(KEY_A))
	{
		m_position.x -= m_moveSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_D))
	{
		m_position.x += m_moveSpeed * deltaTime;
	}

	if (IsKeyPressed(KEY_SPACE) && canJump)
	{
		m_fallSpeed = -300;
		canJump = false;
		jumpFrame = true;
	}

	if (!jumpFrame)
	{
		for (GameObject* go : m_game->m_root->children)
		{
			EnvironmentBlock* eb = dynamic_cast<EnvironmentBlock*>(go);
			//Dont want player to check collision with itself :x
			if (eb != nullptr)
			{
				if (this->GetPos().y < eb->GetPos().y)
				{
					onPlatform = CheckCollisionRecs(m_groundedRect, go->GetGameRect());
					if (onPlatform)
					{
						m_fallSpeed = 0;
						canJump = true;
						m_position.y = eb->GetPos().y - m_gameRect.height; //wacky raylib positioning to put player in the right place upon collision
						break;
					}
					}
				
			}
		}
	}
	//Colliision logic
	

	if (!onPlatform)
	{
		m_fallSpeed += m_gravity * deltaTime; // If not on a platform continue applying gravity
	}


	m_position.y += m_fallSpeed * deltaTime;
	
	if (!canJump)
	{
		jumpFrame = false;
	}
	

}

void Player::OnDraw()
{
	UpdateRect();

	DrawRectangleRec(m_gameRect, m_color);

	DrawRectangleRec(m_groundedRect, RED);
}

void Player::UpdateRect()
{
	m_gameRect.x = m_position.x;
	m_gameRect.y = m_position.y;
	m_gameRect.width = m_scale.x;
	m_gameRect.height = m_scale.y;
	
	//Player has an invisible rect on its feet to check for ground
	m_groundedRect.width = m_gameRect.width / 2;
	m_groundedRect.height = 1;

	m_groundedRect.x = m_position.x + m_gameRect.width / 2 - m_groundedRect.width / 2;
	m_groundedRect.y = m_position.y + m_gameRect.height - m_groundedRect.height;
	
}
