#include "Component.h"
#include "../object.h"

namespace Proton
{
    Proton::Component::Component()
    {
    }

    Proton::Component::Component(Object * parent)
    {
    }

    Proton::Component::Component(const Component & a_Component)
    {
    }

    Proton::Component::Component(Component && a_Component)
    {
    }

    Component& Proton::Component::operator=(const Component & a_Component)
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

    Component& Proton::Component::operator=(Component && a_Component)
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

    Proton::Component::~Component()
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

    void Component::SetParent(Object * a_pParentObject)
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
