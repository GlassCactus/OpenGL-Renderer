#pragma once

class IndexBuffer
{
private:
	unsigned int m_IndexBufferID;

public:
	IndexBuffer(const void* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
};
