#pragma once

#include <string>
#include <vector>

class Entity;

class Scene
{
public:
	Scene();
	~Scene();

	bool Load(std::string a_Filepath);
	bool Reload(std::string a_Filepath);
	bool Save(std::string a_Filepath);

private:
	std::vector<Entity> m_Entities;
};
