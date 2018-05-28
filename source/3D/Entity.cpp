#include "Entity.h"

namespace Proton
{
    Entity::Entity() : m_Name(""), m_Tag("")
    {
    }

    Entity::Entity(const std::string & a_Name) : m_Name(a_Name)
    {
    }

    Entity::Entity(const std::string & a_Name, const std::string& a_Tag) : m_Name(a_Name), m_Tag(a_Tag)
    {
    }

    Entity::Entity(const Entity & a_Entity)
    {
        m_Name = a_Entity.m_Name;
    }

    Entity::~Entity()
    {
    }

    Entity & Entity::operator=(const Entity & a_Entity)
    {
        if (this != &a_Entity)
        {
            m_Name = a_Entity.GetName();
            m_Tag = a_Entity.GetTag();
        }

        return *this;
    }

    Entity & Entity::operator=(Entity && a_Entity)
    {
        if (this != &a_Entity)
        {
            m_Name = a_Entity.GetName();
            m_Tag = a_Entity.GetTag();
        }

        return *this;
    }

    const std::string & Entity::GetName() const
    {
        return m_Name;
    }

    void Entity::SetName(const std::string & a_Name)
    {
        m_Name = a_Name;
    }

    bool Entity::CompareName(const std::string & a_Name)
    {
        if (m_Name == a_Name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    const std::string & Entity::GetTag() const
    {
        return m_Tag;
    }

    void Entity::SetTag(const std::string & a_Tag)
    {
        m_Tag = a_Tag;
    }

    bool Entity::CompareTag(const std::string & a_Tag)
    {
        if (m_Tag == a_Tag)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
