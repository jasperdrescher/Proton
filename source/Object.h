#pragma once

#include "Entity.h"

#include <vector>

class Component;
class Transform;

namespace Proton
{
    class Object : public Entity
    {
    public:
        Object();
        Object(const std::string& a_Name);
        Object(const std::string& a_Name, const std::string& a_Tag);
        Object(const Object& a_Object);
        Object& operator=(const Object& a_Object);
        Object& operator=(Object&& a_Object);
        virtual ~Object(void);

        void Update(float a_DeltaTime);
        void Render();
        void Destroy();

        void AddComponent(Component* a_pComponent);
        void RemoveComponent(Component * a_pComponent);
        void AddChild(Object* a_pObject);
        void RemoveChild(const Object* a_pObject);
        void RemoveChild(const std::string & a_Name);

        const std::vector<Object*>& GetChildren() const;
        Transform * GetTransform() const;
        Object* GetParent() const;

    protected:
        bool m_IsInitialized;
        bool m_IsVisible;
        bool m_IsFrozen;
        Object* m_pParentObject;
        std::vector<Component*> m_pComponents;
        std::vector<Object*> m_pChildren;

    private:
        glm::vec3 m_Position;
    };
}
