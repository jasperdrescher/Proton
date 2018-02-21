#include "application.h"

#include <iostream>
#include <chrono>

App::App()
{
}

App::~App()
{
}

static void ErrorCallback(int error, const char* description)
{
	std::cout << "Error! " << stderr << description << std::endl;
}

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

bool App::Initialize()
{
	glfwSetErrorCallback(ErrorCallback);

	if (!glfwInit())
	{
		return false;
	}

	window = glfwCreateWindow(1280, 720, "Rebellion Engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return false;
	}

	glfwSetKeyCallback(window, KeyCallback);
	glfwMakeContextCurrent(window);
	//glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		return false;
	} 

	settings->Save("resources/settings/settings.xml");
	//settings->Load("resources/settings/settings.xml");
	//scene->Save("resources/scenes/small.xml");
	//scene->Load("resources/scenes/small.xml");

	return true;
}

bool App::Print()
{
	std::cout << "Framework initialization succesful..." << std::endl;
	std::cout << "GLFW version " << glfwGetVersionString() << std::endl;
	std::cout << "GLEW version " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;

	return true;
}

bool App::Loop()
{
	auto start = std::chrono::system_clock::now();

	glfwGetFramebufferSize(window, &m_ScreenWidth, &m_ScreenHeight);
	m_ScreenRatio = m_ScreenWidth / (float)m_ScreenHeight;

	glViewport(0, 0, m_ScreenWidth, m_ScreenHeight);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);

	glfwPollEvents();

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float> elapsed_seconds = end - start;
	m_ElapsedTime = elapsed_seconds.count();
	m_DeltaTime = m_ElapsedTime;
	m_RunTime += m_DeltaTime;

	return true;
}

bool App::Shutdown()
{
	glfwDestroyWindow(window);
	glfwTerminate();

	return true;
}