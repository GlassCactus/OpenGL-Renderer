#pragma once

#include "Renderer.h"

class Texture
{
private:
	unsigned int m_TextureID;
	std::string m_FilePath;
	unsigned char* m_Data;
	int m_Width, m_Height, m_nrChannels;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};
