#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Proton
{
    // Forward declarations of systems
    class Editor;
    class Scene;
    class Settings;

    class Engine
    {
    public:
		Engine();
        ~Engine();

        bool Initialize();
        bool Print();
        bool Loop();
        bool Shutdown();
        bool GetWindowShouldClose();

        GLFWwindow* GetWindow() { return m_Window; }

        Editor* EditorInstance();
        Scene* SceneInstance();
        Settings* SettingsInstance();

    private:
        // Member systems
        Editor* m_Editor;
        Scene* m_Scene;
        Settings* m_Settings;

        GLFWwindow* m_Window;
        float m_RunTime;
        float m_ElapsedTime;
        float m_DeltaTime;
        int m_ScreenWidth = 720;
        int m_ScreenHeight = 480;
        float m_ScreenRatio;
        bool m_WindowShouldClose = true;
    };
}

// Methods to get systems globally
extern Proton::Editor* EditorInstance();
extern Proton::Scene* SceneInstance();
extern Proton::Settings* SettingsInstance();
