#include "System.h"

namespace Proton
{
    System::System()
    {
    }

    System::System(const System& a_System)
    {
    }

    System::System(System&& a_System)
    {
    }

    System& System::operator=(const System& a_System)
    {
        if (this != &a_System)
        {
        }

        return *this;
    }

    System& System::operator=(System&& a_System)
    {
        if (this != &a_System)
        {
        }

        return *this;
    }

    System::~System()
    {
    }
}