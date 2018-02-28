#include "resource_manager.h"
#include "resource.h"

#include <iostream>

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
