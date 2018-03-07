#include "Resource_manager.h"
#include "Resource.h"

#include <iostream>

namespace Proton
{
    Resource * ResourceManager::GetResource(unsigned int ID)
    {
        if (m_Resources[ID] != NULL)
        {
            return m_Resources[ID];
        }
        else
        {
            std::cout << "Can't find resource with ID: " << ID << std::endl;
            return 0;
        }
    }
}
