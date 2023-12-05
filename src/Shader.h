#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <unordered_map>
#include <iostream>

class Shader
{
private:
	unsigned int m_ShaderID;
	//std::unordered_map<std::string, int> UniformLocationCache;

public:
	Shader(const std::string& VertexSource, const std::string& FragmentSource);
	~Shader();

	void Bind() const; //Just being consistent. It's really "Use Program"
	void Unbind() const;

	//Uniform stuff
	void SetUniform1i(const std::string& name, int v0);
	void SetUniform1f(const std::string& name, float v0);

	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

	void SetUniform3v(const std::string& name, glm::vec3 v0);
	void SetUniform4v(const std::string& name, glm::vec3 v0, float v4);

	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);	

private:
	int GetUniformLocation(const std::string& name);
	void ErrorHandling(unsigned int shader, int count);
};