#pragma once

#include <string>
#include <cereal/archives/xml.hpp>

namespace Proton
{
    struct	WindowSettingsData
    {
		int screenWidth;
		int screenHeight;

        template<class Archive>
        void serialize(Archive& anArchive)
        {
            anArchive(CEREAL_NVP(screenWidth), CEREAL_NVP(screenHeight));
        }
    };

    class Settings
    {
    public:
        Settings();
        ~Settings();

        bool LoadWindowSettings(int& aScreenWidth, int& aScreenHeight);
        bool SaveWindowSettings(int aScreenWidth, int aScreenHeight);

	private:
		std::string mySettingsPath;
    };
}
