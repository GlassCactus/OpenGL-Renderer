#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class VertexBuffer
{
private:
	unsigned int m_VertexBufferID;

public:
	VertexBuffer(const void* data, unsigned int size); //constructor
	~VertexBuffer(); //destructor

	void Bind() const;
	void Unbind() const;
};