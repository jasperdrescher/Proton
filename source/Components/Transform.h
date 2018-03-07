#pragma once

#include "Component.h"

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>

namespace Proton
{
    class Transform : Component
    {
    public:
        Transform();
        ~Transform();

        void Initialize();
        void Update(float a_DeltaTime);
        void Destroy();

        const glm::vec3 GetWorldPosition();
        const glm::quat GetWorldRotation();
        const glm::vec3 GetWorldScale();
        const glm::mat4x4 GetWorldMatrix() const;

    private:
        glm::vec3 m_WorldPosition;
        glm::quat m_WorldRotation;
        glm::vec3 m_WorldScale;
        glm::mat4x4 m_WorldMatrix;
    };
}
