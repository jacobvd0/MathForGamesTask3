#pragma once
#include "Vector3.h"
#include "Matrix3.h"
#include <vector>
 
class GameObject
{
protected:
    math::Vector3 LocalPosition;

    float LocalRotation;

    math::Vector3 LocalScale;


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


    math::Vector3 GetLocalPosition() const;
    void SetLocalPosition(math::Vector3 newPosition);
    void SetLocalPosition(float newX, float newY);

    math::Vector3 GetWorldPosition() const;

    float GetLocalRotation() const;
    void SetLocalRotation(float newRotation);

    float GetWorldRotation() const;
    
    math::Vector3 GetLocalScale() const;
    void SetLocalScale(math::Vector3 newScale);
    void SetLocalScale(float newX, float newY);

    math::Vector3 GetWorldScale() const;

    math::Vector3 GetForward() const;

    math::Matrix3 GetLocalMatrix() const;
    math::Matrix3 GetWorldMatrix() const;

    void Translate(float x, float y);
    void Translate(math::Vector3 translation);

    void Rotate(float radians);

    void Scale(float x, float y);
    void Scale(math::Vector3 scaling);

    
    float AngleFrom2D(float _x, float _y) const;


    // If true the tank cant go through and bullets despawn on impact
    bool solid = false;
};