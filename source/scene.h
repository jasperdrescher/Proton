#pragma once

#include <string>
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();

	bool Load(std::string a_Filepath);
	bool Reload(std::string a_Filepath);
	bool Save(std::string a_Filepath);

private:
};
