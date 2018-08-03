#pragma once

namespace Proton
{
    class System
    {
    public:
        System();
        System(const System& a_System);
        System(System&& a_System);
        System& operator=(const System& a_System);
        System& operator=(System&& a_System);
        virtual ~System();

        virtual void Initialize() = 0;
        virtual void Update(float a_DeltaTime) = 0;
        virtual void Render() = 0;
        virtual void Destroy() = 0;

    private:

    };
}
