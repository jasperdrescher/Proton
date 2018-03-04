#pragma once

#include <string>
#include <glm/vec4.hpp>

class Shader
{
public:
    Shader(const std::string& a_Filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetUniformLocation(std::string& a_Name, glm::vec4 a_Location);
    int GetUniformLocation(const std::string& a_Name);
    bool CompileShader(unsigned int a_Type, const std::string& a_Source);
    unsigned int CreateShader(const std::string & a_VertexShader, const std::string a_FragmentShader);

private:
    unsigned int m_RendererID;
    std::string m_Filepath;
};
