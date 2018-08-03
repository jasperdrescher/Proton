#include "Editor.h"
#include "imgui.h"
#include "imguiGL.h"

namespace Proton
{
    Editor::Editor()
    {
    }

    Editor::~Editor()
    {
    }

    void Editor::Initialize()
    {
        for (size_t i = 0; i < 5; i++)
        {
            m_FrameTimes[i] = 0.0f;
        }

        // Setup ImGui binding
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui_ImplGlfwGL3_Init(m_Window, false);

        // Setup style
        ImGui::StyleColorsClassic();
    }

    void Editor::Update(float a_DeltaTime)
    {
        ImGui_ImplGlfwGL3_NewFrame();

        // Window
        {
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::Text("Delta time: %.3f", a_DeltaTime);

            for (int i = 0; i < 4; i++)
            {
                m_FrameTimes[i] = m_FrameTimes[i + 1]; // Move all element to the left except first one
            }

            m_FrameTimes[4] = ImGui::GetIO().Framerate;

            ImGui::PlotLines("Frame times", m_FrameTimes, IM_ARRAYSIZE(m_FrameTimes));
        }
    }

    void Editor::Render()
    {
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Editor::Destroy()
    {
        ImGui_ImplGlfwGL3_Shutdown();
        ImGui::DestroyContext();
    }

    void Editor::SetWindow(GLFWwindow* a_Window)
    {
        m_Window = a_Window;
    }
}
