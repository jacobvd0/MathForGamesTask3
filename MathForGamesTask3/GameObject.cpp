#include "GameObject.h"

void GameObject::OnUpdate(float deltaTime)
{
}

void GameObject::OnDraw()
{
}

GameObject::GameObject()
{
    Parent = nullptr;

    LocalPosition = math::Vector3(0, 0, 1);
    LocalRotation = 0;
    LocalScale = math::Vector3(1, 1, 1);
}

void GameObject::Update(float deltaTime)
{
    OnUpdate(deltaTime);
    //hitbox.SetVars(GetWorldPosition() - 20, GetWorldPosition() + 20);
}

void GameObject::Draw()
{
    OnDraw();
}

void GameObject::SetParent(GameObject* newParent)
{
    if (Parent != nullptr) {
        auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

        if (findIt != Parent->Children.end()) {
            Parent->Children.erase(findIt);
            Parent = nullptr;
        }
    }

    if (newParent != nullptr) {
        Parent = newParent;
        Parent->Children.push_back(this);
    }
}

GameObject* GameObject::GetParent()
{
    return Parent;
}

const GameObject* GameObject::GetParent() const
{
    return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
    return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
    return Children[childIndex];
}

math::Vector3 GameObject::GetLocalPosition() const
{
    return LocalPosition;
}

void GameObject::SetLocalPosition(math::Vector3 newPosition)
{
    LocalPosition = newPosition;
}

void GameObject::SetLocalPosition(float newX, float newY)
{
    LocalPosition = math::Vector3(newX, newY, LocalPosition.z);
}

math::Vector3 GameObject::GetWorldPosition() const
{
    math::Matrix3 worldMat = GetWorldMatrix();
    return math::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetLocalRotation() const
{
    return LocalRotation;
}

void GameObject::SetLocalRotation(float newRotation)
{
    LocalRotation = newRotation;
}

float GameObject::GetWorldRotation() const
{
    math::Vector3 fwd = GetForward();
    return AngleFrom2D(fwd.x, fwd.y);
}

math::Vector3 GameObject::GetLocalScale() const
{
    return LocalScale;
}

void GameObject::SetLocalScale(math::Vector3 newScale)
{
    LocalScale = newScale;
}

void GameObject::SetLocalScale(float newX, float newY)
{
    LocalScale = math::Vector3(newX, newY, LocalScale.z);
}

math::Vector3 GameObject::GetWorldScale() const
{
    math::Matrix3 myTransform = GetWorldMatrix();

    return math::Vector3(math::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(),
        math::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(),
        1.0f);
}

math::Vector3 GameObject::GetForward() const
{
    auto mat = GetWorldMatrix();
    return math::Vector3(mat[0], mat[1], mat[2]);
}

math::Matrix3 GameObject::GetLocalMatrix() const
{
    return
        math::Matrix3::MakeTranslation(LocalPosition) *
        math::Matrix3::MakeRotateZ(LocalRotation) *
        math::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

math::Matrix3 GameObject::GetWorldMatrix() const
{
    if (Parent == nullptr) {
        return GetLocalMatrix();
    }
    else {
        return Parent->GetWorldMatrix() * GetLocalMatrix();
    }
}

void GameObject::Translate(float x, float y)
{
    LocalPosition = LocalPosition + math::Vector3(x, y, 0);
}

void GameObject::Translate(math::Vector3 translation)
{
    LocalPosition = LocalPosition + translation;
}

void GameObject::Rotate(float radians)
{
    LocalRotation = LocalRotation + radians;
}

void GameObject::Scale(float x, float y)
{
    LocalScale = LocalScale * math::Vector3(x, y, 1);
}

void GameObject::Scale(math::Vector3 scaling)
{
    LocalScale = LocalScale * scaling;
}

float GameObject::AngleFrom2D(float _x, float _y) const
{
    //return LocalRotation;
    return atan2(_y,_x);
}
