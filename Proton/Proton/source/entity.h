#pragma once

#include <glm\vec3.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	void Update(float a_DeltaTime);
	void Render();
	void Destroy();

	glm::vec3 m_Position;

private:
};
