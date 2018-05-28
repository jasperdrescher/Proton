#pragma once

#include <glm/vec3.hpp>
#include <string>

namespace Proton
{
    class Entity
    {
    public:
        Entity();
        Entity(const std::string& a_Name);
        Entity(const std::string& a_Name, const std::string& a_Tag);
        Entity(const Entity& a_Entity);
        Entity& operator=(const Entity& a_Entity);
        Entity& operator=(Entity&& a_Entity);
        virtual ~Entity();

        virtual void Update(float a_DeltaTime) = 0;
        virtual void Render() = 0;
        virtual void Destroy() = 0;

        const std::string& GetName() const;
        void SetName(const std::string& a_Name);
        bool CompareName(const std::string& a_Name);

        const std::string& GetTag() const;
        void SetTag(const std::string& a_Tag);
        bool CompareTag(const std::string& a_Tag);

    private:
        unsigned int m_ID;
        std::string m_Name;
        std::string m_Tag;
    };
}
