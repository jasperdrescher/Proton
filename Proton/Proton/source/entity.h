#pragma once

#include <glm\vec3.hpp>
#include <string>

class Entity
{
public:
	Entity();
	Entity(const std::string& a_Name);
	Entity(const Entity& a_Entity);
	Entity& operator=(const Entity& a_Entity);
	~Entity();

	void Update(float a_DeltaTime);
	void Render();
	void Destroy();

	const std::string& GetName() const;
	void SetName(const std::string& a_Name);
	bool CompareName(const std::string& a_Name);

private:
	unsigned int m_ID;
	std::string m_Name;
	glm::vec3 m_Position;
};
