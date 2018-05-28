#include "Settings.h"

#include <cereal/archives/xml.hpp>

#include <fstream>

namespace Proton
{
    Settings::Settings()
    {
    }

    Settings::~Settings()
    {
    }

    bool Settings::Load(std::string a_Filepath)
    {
        /*std::ifstream instream(a_Filepath);
        cereal::XMLInputArchive archive(instream);

        archive(settings);*/

        return true;
    }

    bool Settings::Reload(std::string a_Filepath)
    {
        std::ifstream instream(a_Filepath);
        cereal::XMLInputArchive archive(instream);

        //archive(m_Settings);

        return false;
    }

    bool Settings::Save(std::string a_Filepath)
    {
        SettingsStruct settings;
        settings.screenWidth = 1;
        settings.screenHeight = 1;

        std::ofstream outstream(a_Filepath);
        cereal::XMLOutputArchive archive(outstream);

        archive(CEREAL_NVP(settings));

        return true;
    }

    int Settings::GetScreenWidth() const
    {
        return m_ScreenWidth;
    }

    int Settings::GetScreenHeight() const
    {
        return m_ScreenHeight;
    }
}
