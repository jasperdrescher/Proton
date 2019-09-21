#include "Settings.h"

#include <fstream>

namespace Proton
{
    Settings::Settings()
		: mySettingsPath("../resources/settings/")
    {
    }

    Settings::~Settings()
    {
    }

    bool Settings::LoadWindowSettings(int& aScreenWidth, int& aScreenHeight)
    {
        std::ifstream instream(mySettingsPath + "window.xml");
        cereal::XMLInputArchive archive(instream);

		WindowSettingsData test;
		archive(test);

		aScreenWidth = test.screenWidth;
		aScreenHeight = test.screenHeight;

        return true;
    }

    bool Settings::SaveWindowSettings(int aScreenWidth, int aScreenHeight)
    {
		WindowSettingsData test;

		test.screenWidth = aScreenWidth;
		test.screenHeight = aScreenHeight;

        std::ofstream outstream(mySettingsPath + "window.xml");
        cereal::XMLOutputArchive archive(outstream);

        archive(CEREAL_NVP(test));

        return true;
    }
}
