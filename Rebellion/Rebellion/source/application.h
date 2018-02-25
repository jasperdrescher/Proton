#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "scene.h"
#include "settings.h"

class App
{
public:
	App();
	~App();

	bool Initialize();
	bool Print();
	bool Loop();
	bool Shutdown();

	GLFWwindow* GetWindow() { return window; }

private:
	GLFWwindow* window;
	Scene* scene;
	Settings* m_Settings;
	float m_RunTime;
	float m_ElapsedTime;
	float m_DeltaTime;
};
