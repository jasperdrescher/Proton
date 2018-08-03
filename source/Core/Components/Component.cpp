#include "Component.h"
#include "../Object.h"

namespace Proton
{
    Component::Component()
    {
    }

    Component::Component(Object* a_ParentObject)
    {
    }

    Component::Component(const Component& a_Component)
    {
    }

    Component::Component(Component&& a_Component)
    {
    }

    Component& Component::operator=(const Component& a_Component)
    {
        if (this != &a_Component)
        {
            m_pParentObject = a_Component.GetParent();
            m_IsInitialized = a_Component.IsInitialized();
            m_IsEnabled = a_Component.IsEnabled();
            m_IsVisible = a_Component.IsVisible();
        }

        return *this;
    }

    Component& Component::operator=(Component&& a_Component)
    {
        if (this != &a_Component)
        {
            m_pParentObject = a_Component.GetParent();
            m_IsInitialized = a_Component.IsInitialized();
            m_IsEnabled = a_Component.IsEnabled();
            m_IsVisible = a_Component.IsVisible();
        }

        return *this;
    }

    Component::~Component()
    {
    }

    bool Component::IsInitialized() const
    {
        return m_IsInitialized;
    }

    Object * Component::GetParent() const
    {
        return nullptr;
    }

    void Component::SetParent(Object* a_pParentObject)
    {
    }

    void Component::SetEnabled(bool a_IsEnabled)
    {
        m_IsEnabled = a_IsEnabled;
    }

    bool Component::IsEnabled() const
    {
        return m_IsEnabled;
    }

    void Component::SetVisible(bool a_IsVisible)
    {
        m_IsVisible = a_IsVisible;
    }

    bool Component::IsVisible() const
    {
        return m_IsVisible;
    }
}
