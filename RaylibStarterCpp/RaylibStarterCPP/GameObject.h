#pragma once
#include "Vector3.h"
class GameObject
{
protected:
	Vector3 LocalPosition;

	float LocalRotation;
	
	Vector3 LocalScale;

	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw();


public:
	GameObject();



	void Update(float deltaTime);
	void Draw();
};

