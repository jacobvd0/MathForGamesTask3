#pragma once
#include "Vector3.h"
#include "Matrix3.h"
#include <vector>

using namespace MathClasses;
class GameObject
{
protected:
    Vector3 LocalPosition;

    float LocalRotation;

    Vector3 LocalScale;


    GameObject* Parent;
    std::vector<GameObject*> Children;


    virtual void OnUpdate(float deltaTime);
    virtual void OnDraw();


public:
    GameObject();



    void Update(float deltaTime);
    void Draw();

    void SetParent(GameObject* newParent);
    GameObject* GetParent();
    const GameObject* GetParent() const;

    GameObject* GetChild(size_t childIndex);
    const GameObject* GetChild(size_t childIndex)const ;


    Vector3 GetLocalPosition() const;
    void SetLocalPosition(Vector3 newPosition);
    void SetLocalPosition(float newX, float newY);

    Vector3 GetWorldPosition() const;

    float GetLocalRotation() const;
    void SetLocalRotation(float newRotation);

    float GetWorldRotation() const;
    
    Vector3 GetLocalScale() const;
    void SetLocalScale(Vector3 newScale);
    void SetLocalScale(float newX, float newY);

    Vector3 GetWorldScale() const;

    Vector3 GetForward() const;

    Matrix3 GetLocalMatrix() const;
    Matrix3 GetWorldMatrix() const;

    void Translate(float x, float y);
    void Translate(Vector3 translation);

    void Rotate(float radians);

    void Scale(float x, float y);
    void Scale(Vector3 scaling);

    
    float AngleFrom2D(float _x, float _y) const;
};