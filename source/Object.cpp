#include "Object.h"
#include "Components/Transform.h"

namespace Proton
{
    Object::Object() : m_pParentObject(nullptr)
    {
    }

    Object::Object(const std::string & a_Name) : Entity(a_Name), m_pParentObject(nullptr)
    {
    }

    Object::Object(const std::string & a_Name, const std::string & a_Tag) : Entity(a_Name, a_Tag), m_pParentObject(nullptr)
    {
    }

    Object::Object(const Object & a_Object)
    {
        this->SetName(a_Object.GetName());
        this->SetTag(a_Object.GetTag());
    }

    Object & Object::operator=(const Object & a_Object)
    {
        if (this != &a_Object)
        {
            this->SetName(a_Object.GetName());
            this->SetTag(a_Object.GetTag());
        }

        return *this;
    }

    Object & Object::operator=(Object && a_Object)
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

	void Object::AddComponent(Component * a_pComponent)
	{
		for (int i = 0; i < m_pComponents.size(); i++)
		{
			if (typeid(*m_pComponents[i]) == typeid(*a_pComponent))
			{
				break;
			}
		}

		a_pComponent->SetParent(this);

		if (!a_pComponent->IsInitialized())
		{
			a_pComponent->Initialize();
		}

		m_pComponents.push_back(a_pComponent);
	}

	void Object::RemoveComponent(Component * a_pComponent)
	{
		auto it = std::find(m_pComponents.begin(), m_pComponents.end(), a_pComponent);
		bool exists = it != m_pComponents.end();
		if (exists)
		{
			a_pComponent->Destroy();
		}
	}

	void Object::AddChild(Object * a_pObject)
	{
		a_pObject->m_pParentObject = this;
		if (a_pObject->GetName() == GetName())
		{
			// error
		}

		if (!a_pObject->m_IsInitialized)
		{

		}

		m_pChildren.push_back(a_pObject);
	}

    Object* Object::GetParent() const
    {
        return (m_pParentObject);
    }
}
