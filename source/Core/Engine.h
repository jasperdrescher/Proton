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

        GLFWwindow* GetWindow() { return myWindow; }

        Editor* EditorInstance();
        Scene* SceneInstance();
        Settings* SettingsInstance();

    private:
        // Member systems
        Editor* myEditor;
        Scene* myScene;
        Settings* mySettings;

		// GLFW
        GLFWwindow* myWindow;

		int myScreenWidth;
		int myScreenHeight;
		float myScreenRatio;
        float myDeltaTime;
        float myRunTime;
        float myElapsedTime;
        bool myWindowShouldClose = true;
    };
}

// Methods to get systems globally
extern Proton::Editor* EditorInstance();
extern Proton::Scene* SceneInstance();
extern Proton::Settings* SettingsInstance();
