#pragma once

#include <string>
#include <cereal\cereal.hpp>

struct SettingsStruct
{
	int screenWidth, screenHeight;

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(CEREAL_NVP(screenWidth), CEREAL_NVP(screenHeight));
	}
};

class Settings
{
public:
	Settings();
	~Settings();

	bool Load(std::string a_Filepath);
	bool Reload(std::string a_Filepath);
	bool Save(std::string a_Filepath);

	int GetScreenWidth() const;
	int GetScreenHeight() const;
	float GetScreenRatio() const;

	int SetScreenWidth();
	int SetScreenHeight();
	float SetScreenRatio();

private:
	int m_ScreenWidth = 720;
	int m_ScreenHeight = 480;
	float m_ScreenRatio;
};
