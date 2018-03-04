#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#include "scene.h"
//#include "settings.h"

class App
{
public:
	App();
	~App();

	bool Initialize();
	bool Print();
	bool Loop();
	bool Shutdown();
    bool GetWindowShouldClose();

	GLFWwindow* GetWindow() { return window; }

private:
	GLFWwindow* window;
	//Scene* scene;
	//Settings* m_Settings;
	float m_RunTime;
	float m_ElapsedTime;
	float m_DeltaTime;
    int m_ScreenWidth = 720;
    int m_ScreenHeight = 480;
    float m_ScreenRatio;
    bool m_WindowShouldClose = true;
};
