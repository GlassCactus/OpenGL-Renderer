#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class FrameBuffer
{
private:
	unsigned int m_FrameBufferID;

public:
	FrameBuffer();
	~FrameBuffer();

	void Bind() const;
	void Unbind() const;
};