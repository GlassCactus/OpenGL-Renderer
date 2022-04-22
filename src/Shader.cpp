#include <iostream>
#include <string>
#include "Shader.h"


Shader::Shader(const std::string& VertexSource, const std::string& FragmentSource)
{
	m_ShaderID = glCreateProgram();
	const char* vSource = VertexSource.c_str();
	const char* fSource = FragmentSource.c_str();
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vSource, NULL);
	glShaderSource(fragmentShader, 1, &fSource, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	glAttachShader(m_ShaderID, vertexShader);
	glAttachShader(m_ShaderID, fragmentShader);

	glLinkProgram(m_ShaderID);
	glValidateProgram(m_ShaderID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	ErrorHandling(vertexShader, 0);  //ITS NOT WORKING D:
	ErrorHandling(fragmentShader, 1);
}

Shader::~Shader()
{
	glDeleteProgram(m_ShaderID);
}

void Shader::Bind() const
{
	glUseProgram(m_ShaderID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

void Shader::SetUniform1i(const std::string& name, int v0)
{
	glUniform1i(GetUniformLocation(name), v0);
}

void Shader::SetUniform1f(const std::string& name, float v0)
{
	glUniform1f(GetUniformLocation(name), v0);
}

void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2)
{
	glUniform3f(GetUniformLocation(name), v0, v1, v2);
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

int Shader::GetUniformLocation(const std::string& name)
{
	int location = glGetUniformLocation(m_ShaderID, name.c_str());
	if (location == -1)
	{
		std::cout << "WARNING: Uniform " << name << " doesn't exist :(" << std::endl;
	}

	return location;
}
 
void Shader::ErrorHandling(unsigned int shader, int count) //Checks for shader compilation errors.
{
	int success;
	char infoLog[512];
	std::string shaderType;

	if (count == 0)
	{
		shaderType.append("Vertex");
	}

	else
	{
		shaderType.append("Fragment");
	}

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR: " << shaderType << " compilation failed.\n" << infoLog << std::endl;
	}
}