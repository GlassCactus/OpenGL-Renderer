#pragma once

#include <vector>
#include "Renderer.h"

struct VertexBufferElement
{
	unsigned int count;
	unsigned int type;
	unsigned char normalized;
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> Elements;
	unsigned int Stride;

public:
	VertexBufferLayout()
		:Stride(0) {}

	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		Elements.push_back({ count, GL_FLOAT, GL_FALSE });
		Stride += sizeof(GL_FLOAT) * count;
	}
	
	template<>
	void Push<unsigned int>(unsigned int count)
	{
		Elements.push_back({ count, GL_INT, GL_FALSE });
		Stride += sizeof(GL_INT) * count;
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		Elements.push_back({ count, GL_UNSIGNED_BYTE, GL_TRUE });
		Stride += sizeof(GL_UNSIGNED_BYTE) * count;
	}
	
	inline const std::vector<VertexBufferElement> GetElements() const
	{
		return Elements;
	}

	inline unsigned int GetStride() const
	{
		return Stride;
	}
};