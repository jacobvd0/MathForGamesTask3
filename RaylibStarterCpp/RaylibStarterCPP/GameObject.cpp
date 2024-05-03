#include "GameObject.h"

void GameObject::OnUpdate(float deltaTime)
{
}

void GameObject::OnDraw()
{
}

GameObject::GameObject()
{
	LocalPosition = Vector3(0, 0, 1);
	LocalRotation = 0;
	LocalScale = Vector3(1, 1, 1);
}

void GameObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);
}

void GameObject::Draw()
{
	OnDraw();
}
