#include "shader.h"
#include <glad/glad.h>

#include <iostream>
#include <fstream>

Shader::Shader(const std::string & a_Filepath) : m_Filepath(a_Filepath), m_RendererID(0)
{
    //m_RenderID = CreateShader();
}

Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}

void Shader::Bind() const
{
    glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::SetUniformLocation(std::string & a_Name, glm::vec4 a_Location)
{
    glUniform4f(GetUniformLocation(a_Name), a_Location.x, a_Location.y, a_Location.z, a_Location.w);
}

int Shader::GetUniformLocation(const std::string & a_Name)
{
    int location = glGetUniformLocation(m_RendererID, a_Name.c_str());

    return location;
}

bool Shader::CompileShader(unsigned int a_Type, const std::string& a_Source)
{
    unsigned int id = glCreateShader(a_Type);
    const char* source = a_Source.c_str();
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader!" << std::endl;
        glDeleteShader(id);
        
        return 0;
    }

    return false;
}

unsigned int Shader::CreateShader(const std::string & a_VertexShader, const std::string a_FragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, a_VertexShader);
    unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, a_FragmentShader);
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}
