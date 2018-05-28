#include "Application.h"
#include "imgui.h"
#include "ImguiGL.h"

#include <iostream>
#include <chrono>

namespace Proton
{
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

        window = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, "Proton Engine", nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            return false;
        }

        glfwSetKeyCallback(window, KeyCallback);
        glfwMakeContextCurrent(window);
        //glfwSwapInterval(1);

        if (!gladLoadGL())
        {
            return false;
        }

        // Setup ImGui binding
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui_ImplGlfwGL3_Init(window, false);

        // Setup style
        ImGui::StyleColorsClassic();

        return true;
    }

    bool App::Print()
    {
        std::cout << "Framework initialization succesful..." << std::endl;
        std::cout << "GLFW version " << glfwGetVersionString() << std::endl;
        std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;
        std::cout << "GLSL version " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

        return true;
    }

    bool App::Loop()
    {
        auto start = std::chrono::system_clock::now();
        glfwPollEvents();
        ImGui_ImplGlfwGL3_NewFrame();

        // Window
        {
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }

        glfwGetFramebufferSize(window, &m_ScreenWidth, &m_ScreenHeight);
        m_ScreenRatio = m_ScreenWidth / (float)m_ScreenHeight;
        glViewport(0, 0, m_ScreenWidth, m_ScreenHeight);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);

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

    bool App::Shutdown()
    {
        ImGui_ImplGlfwGL3_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(window);
        glfwTerminate();

        return true;
    }

    bool App::GetWindowShouldClose()
    {
        return m_WindowShouldClose;
    }
}
