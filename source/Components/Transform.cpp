#include "Transform.h"

namespace Proton
{
    Transform::Transform()
    {
    }

    Transform::~Transform()
    {
    }

    void Transform::Initialize()
    {
    }

    void Transform::Update(float a_DeltaTime)
    {
    }

    void Transform::Destroy()
    {
    }

	void Transform::Translate(const glm::vec3 & a_Translation)
	{
		m_WorldPosition = a_Translation;
	}

	void Transform::Translate(float a_X, float a_Y, float a_Z)
	{
		m_WorldPosition = glm::vec3(a_X, a_Y, a_Z);
	}

	void Transform::Rotate(const glm::quat & a_Rotation)
	{
		m_WorldRotation = a_Rotation;
	}

	void Transform::Scale(const glm::vec3 & a_Scale)
	{
		m_WorldScale = a_Scale;
	}

	void Transform::Scale(float a_X, float a_Y, float a_Z)
	{
		m_WorldScale = glm::vec3(a_X, a_Y, a_Z);
	}

	const glm::vec3 Transform::GetWorldPosition()
	{
		return m_WorldPosition;
	}

	const glm::quat Transform::GetWorldRotation()
	{
		return m_WorldRotation;
	}

	const glm::vec3 Transform::GetWorldScale()
	{
		return m_WorldScale;
	}

	const glm::mat4x4 Transform::GetWorldMatrix() const
	{
		return m_WorldMatrix;
	}
}
