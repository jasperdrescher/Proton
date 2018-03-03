#include "entity.h"

Entity::Entity() : m_Name("")
{
}

Entity::Entity(const std::string & a_Name) : m_Name(a_Name)
{
}

Entity::~Entity()
{
}

void Entity::Update(float a_DeltaTime)
{
}

void Entity::Render()
{
}

void Entity::Destroy()
{
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

Entity::Entity(const Entity & a_Entity)
{
	m_Name = a_Entity.m_Name;
}

Entity & Entity::operator=(const Entity & a_Entity)
{
	if (this != &a_Entity)
	{
		m_Name = a_Entity.GetName();
	}

	return *this;
}
