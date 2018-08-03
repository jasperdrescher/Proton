#include "Engine.h"
#include "Systems/Editor.h"
#include "Systems/Scene.h"
#include "Systems/Settings.h"

#include <iostream>
#include <chrono>
#include <algorithm>

// Singleton engine instnace
Proton::Engine ProtonEngine;

namespace Proton
{
	Engine::Engine()
    {
    }

	Engine::~Engine()
    {
    }

    static void ErrorCallback(int error, const char* description)
    {
        std::cout << "Error! " << stderr << description << std::endl;
    }

    static void KeyCallback(GLFWwindow* m_Window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
        }
    }

    bool Engine::Initialize()
    {
        glfwSetErrorCallback(ErrorCallback);

        if (!glfwInit())
        {
            return false;
        }

        m_Window = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, "Proton Engine", nullptr, nullptr);
        if (!m_Window)
        {
            glfwTerminate();
            return false;
        }

        glfwSetKeyCallback(m_Window, KeyCallback);
        glfwMakeContextCurrent(m_Window);
        //glfwSwapInterval(1);

        if (!gladLoadGL())
        {
            return false;
        }

        // Initialize the editor
        m_Editor = new Editor();
        m_Editor->SetWindow(m_Window);
        m_Editor->Initialize();

        return true;
    }

    bool Engine::Print()
    {
        std::cout << "Framework initialization succesful..." << std::endl;
        std::cout << "GLFW version " << glfwGetVersionString() << std::endl;
        std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;
        std::cout << "GLSL version " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

        return true;
    }

    bool Engine::Loop()
    {
        auto start = std::chrono::system_clock::now();
        glfwPollEvents();

        m_Editor->Update(m_DeltaTime);

        glfwGetFramebufferSize(m_Window, &m_ScreenWidth, &m_ScreenHeight);
        m_ScreenRatio = m_ScreenWidth / (float)m_ScreenHeight;
        glViewport(0, 0, m_ScreenWidth, m_ScreenHeight);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        m_Editor->Render();

        glfwSwapBuffers(m_Window);

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed_seconds = end - start;
        m_ElapsedTime = elapsed_seconds.count();
        m_DeltaTime = m_ElapsedTime;
        m_RunTime += m_DeltaTime;

        if (glfwWindowShouldClose(GetWindow()))
        {
            m_WindowShouldClose = false;
        }

        return true;
    }

    bool Engine::Shutdown()
    {
        m_Editor->Destroy();
        glfwDestroyWindow(m_Window);
        glfwTerminate();

        return true;
    }

    bool Engine::GetWindowShouldClose()
    {
        return m_WindowShouldClose;
    }

    // Systems
    Editor* Engine::EditorInstance() { return m_Editor; }
    Scene* Engine::SceneInstance() { return m_Scene; }
    Settings* Engine::SettingsInstance() { return m_Settings; }
}

Proton::Editor* EditorInstance()
{
    return ProtonEngine.EditorInstance();
}

Proton::Scene* SceneInstance()
{
    return ProtonEngine.SceneInstance();
}
Proton::Settings* SettingsInstance()
{
    return ProtonEngine.SettingsInstance();
}