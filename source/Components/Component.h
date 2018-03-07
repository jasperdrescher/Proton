#pragma once

namespace Proton
{
    class Object;

    class Component
    {
    public:
        Component();
        Component(Object* parent);
        Component(const Component& a_Component);
        Component(Component&& a_Component);
        Component& operator=(const Component& a_Component);
        Component& operator=(Component&& a_Component);
        virtual ~Component();

        virtual void Initialize() = 0;
        virtual void Update(float a_DeltaTime) = 0;
        virtual void Destroy() = 0;

        bool IsInitialized() const;
        Object* GetParent() const;
        void SetParent(Object* a_pParentObject);
        void SetEnabled(bool a_IsEnabled);
        bool IsEnabled() const;
        void SetVisible(bool a_IsVisible);
        bool IsVisible() const;

    protected:
        Object* m_pParentObject;
        bool m_IsInitialized;
        bool m_IsEnabled;
        bool m_IsVisible;
    };
}