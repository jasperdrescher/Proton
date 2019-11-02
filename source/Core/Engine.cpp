#include "Engine.h"
#include "Systems/Editor.h"
#include "Systems/Scene.h"
#include "Systems/Settings.h"

#include <iostream>
#include <chrono>
#include <algorithm>

Proton::Engine ProtonEngine;

namespace Proton
{
	Engine::Engine()
		: myEditor(nullptr)
		, myScene(nullptr)
		, mySettings(nullptr)
		, myWindow(nullptr)
		, myScreenHeight(480)
		, myScreenWidth(720)
		, myScreenRatio(0.0f)
		, myDeltaTime(0.0f)
		, myRunTime(0.0f)
		, myElapsedTime(0.0f)
		, myWindowShouldClose(false)
    {
    }

	Engine::~Engine()
    {
    }

    static void ErrorCallback(int anError, const char* aDescription)
    {
        std::cout << "Error: " << anError << stderr << aDescription << std::endl;
    }

    static void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int anAction, int aMode)
    {
        if (aKey == GLFW_KEY_ESCAPE && anAction == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(aWindow, GLFW_TRUE);
        }
    }

    bool Engine::Initialize()
    {
        glfwSetErrorCallback(ErrorCallback);

        if (!glfwInit())
        {
			std::cout << "Error: " << "Failed to initialize GLFW" << std::endl;
            return false;
        }

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        myWindow = glfwCreateWindow(myScreenWidth, myScreenHeight, "Proton Engine", nullptr, nullptr);
        if (!myWindow)
        {
			std::cout << "Error: " << "Failed to create a GLFW window" << std::endl;
            glfwTerminate();
            return false;
        }

		glfwMakeContextCurrent(myWindow);
        glfwSetKeyCallback(myWindow, KeyCallback);
		glfwSetInputMode(myWindow, GLFW_STICKY_KEYS, GL_TRUE);
        glfwSwapInterval(1);

        if (!gladLoadGL())
        {
			std::cout << "Error: " << "Failed to initialize GLAD context" << std::endl;
            return false;
        }

		// RENDER
		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		static const GLfloat g_vertex_buffer_data[] = {
		   -1.0f, -1.0f, 0.0f,
		   1.0f, -1.0f, 0.0f,
		   0.0f,  1.0f, 0.0f,
		};

		// This will identify our vertex buffer
		GLuint vertexbuffer;
		// Generate 1 buffer, put the resulting identifier in vertexbuffer
		glGenBuffers(1, &vertexbuffer);
		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		// 1st attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);
		// END

        myEditor = new Editor();
		myEditor->SetWindow(myWindow);
		myEditor->Initialize();

		mySettings = new Settings();
		mySettings->SaveWindowSettings(myScreenWidth, myScreenHeight);

		mySettings->LoadWindowSettings(myScreenWidth, myScreenHeight);

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

        myEditor->Update(myDeltaTime);

		int screenWidth = static_cast<int>(myScreenWidth);
		int screenHeight = static_cast<int>(myScreenHeight);

        glfwGetFramebufferSize(myWindow, &screenWidth, &screenHeight);
        myScreenRatio = myScreenWidth / (float)myScreenHeight;
        glViewport(0, 0, myScreenWidth, myScreenHeight);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
		myEditor->Render();

        glfwSwapBuffers(myWindow);

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed_seconds = end - start;
        myElapsedTime = elapsed_seconds.count();
        myDeltaTime = myElapsedTime;
        myRunTime += myDeltaTime;

        if (glfwWindowShouldClose(GetWindow()))
        {
            myWindowShouldClose = true;
        }

        return true;
    }

    bool Engine::Shutdown()
    {
        myEditor->Destroy();
        glfwDestroyWindow(myWindow);
        glfwTerminate();

        return true;
    }

    bool Engine::GetWindowShouldClose()
    {
        return myWindowShouldClose;
    }

    Editor* Engine::EditorInstance() { return myEditor; }
    Scene* Engine::SceneInstance() { return myScene; }
    Settings* Engine::SettingsInstance() { return mySettings; }
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