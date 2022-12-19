#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1, &m_VertexBufferID); // Generates buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID); //We're selecting the "layer" to "draw" on like in PS. This is what binding means.
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW); //Copies all the data onto the buffers
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_VertexBufferID);
}


void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
}


void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}