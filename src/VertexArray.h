#pragma once

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_VertexArrayID;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBufferLayout& layout);

	void Bind() const; 
	void Unbind() const;
};