#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_VertexArrayID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VertexArrayID);
}

void VertexArray::AddBuffer(const VertexBufferLayout& layout)
{	
	Bind();

	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glVertexAttribPointer(i, element.count, element.type, element.normalized, 8 * sizeof(float), (const void*)offset);
		glEnableVertexAttribArray(i);
		offset += element.count * 4;
	}

}

void VertexArray::Bind() const
{
	glBindVertexArray(m_VertexArrayID); //Binding the VAO again restores all buffer binds and attribute setting previously set up
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0); //Unbinds
}