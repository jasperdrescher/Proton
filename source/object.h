#pragma once

#include "entity.h"

class Object : public Entity
{
public:
    Object();
    Object(const std::string& a_Name);
    Object(const std::string& a_Name, const std::string& a_Tag);
    Object(const Object& a_Object);
    Object& operator=(const Object& a_Object);
    virtual ~Object(void);

    void Destroy();

    Object* GetParent() const;

protected:
    Object* m_pParentObject;

private:
    unsigned int m_ID;
    glm::vec3 m_Position;
};
