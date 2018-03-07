#pragma once

#include "Component.h"

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

    private:

    };
}
