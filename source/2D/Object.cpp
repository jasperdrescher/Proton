#include "Object.h"
#include "Components/Transform.h"

#include <algorithm>
#include <typeinfo>
#include <iostream>

namespace Proton
{
    Object::Object() : m_pParentObject(nullptr)
    {
    }

    Object::Object(const std::string& a_Name) : Entity(a_Name), m_pParentObject(nullptr)
    {
    }

    Object::Object(const std::string& a_Name, const std::string& a_Tag) : Entity(a_Name, a_Tag), m_pParentObject(nullptr)
    {
    }

    Object::Object(const Object& a_Object)
    {
        this->SetName(a_Object.GetName());
        this->SetTag(a_Object.GetTag());
    }

    Object & Object::operator=(const Object& a_Object)
    {
        if (this != &a_Object)
        {
            this->SetName(a_Object.GetName());
            this->SetTag(a_Object.GetTag());
        }

        return *this;
    }

    Object & Object::operator=(Object&& a_Object)
    {
        if (this != &a_Object)
        {
            this->SetName(a_Object.GetName());
            this->SetTag(a_Object.GetTag());
        }

        return *this;
    }

    Object::~Object()
    {
    }

    void Object::Update(float a_DeltaTime)
    {
    }

    void Object::Render()
    {
    }

    void Object::Destroy()
    {
    }

	void Object::AddChild(Object* a_pObject)
	{
		a_pObject->m_pParentObject = this;

		m_pChildren.push_back(a_pObject);
	}

    Object* Object::GetParent() const
    {
        return (m_pParentObject);
    }
}
