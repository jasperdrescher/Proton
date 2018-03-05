#include "scene.h"
#include <cereal/archives/xml.hpp>

#include <fstream>

Scene::Scene()
{
}

Scene::~Scene()
{
}

bool Scene::Load(std::string a_Filepath)
{
	/*std::ifstream instream(a_Filepath);
	cereal::XMLInputArchive archive(instream);

	archive(m_Entities);

	if (m_Entities.size() <= 0)
	{
		return false;
	}*/

	return true;
}

bool Scene::Reload(std::string a_Filepath)
{
	/*std::ifstream instream(a_Filepath);
	cereal::XMLInputArchive archive(instream);

	archive(m_Entities);

	if (m_Entities.size() <= 0)
	{
		return false;
	}*/

	return false;
}

bool Scene::Save(std::string a_Filepath)
{
	/*if (m_Entities.size() <= 0)
	{
		return false;
	}

	std::ofstream outstream(a_Filepath);
	cereal::XMLOutputArchive archive(outstream);

	archive(m_Entities);*/

	return true;
}
