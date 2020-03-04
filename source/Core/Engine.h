#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Proton
{
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
        Editor* myEditor;
        Scene* myScene;
        Settings* mySettings;

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

extern Proton::Editor* EditorInstance();
extern Proton::Scene* SceneInstance();
extern Proton::Settings* SettingsInstance();
