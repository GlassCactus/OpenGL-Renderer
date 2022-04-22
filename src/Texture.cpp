#include "Texture.h"
#include "stb_image/stb_image.h"

Texture::Texture(const std::string& path)
	: m_TextureID(0), m_FilePath(path), m_Data(nullptr), m_Width(0), m_Height(0), m_nrChannels(0) //You can initialize here
{
	stbi_set_flip_vertically_on_load(1); //This flips our texture vertically (upside down lol)
	m_Data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_nrChannels, 0);

	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);//what to do when we shrink it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//what to do when we enlarge it

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //"x coordinate and type of pattern"
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //"y coordinate and type of pattern"

	if (m_Data)
	{
		GLenum format;
		if (m_nrChannels == 3)
			format = GL_RGB;
		else if (m_nrChannels == 4)
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, m_Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		std::cout << "Image not here :c" << std::endl;
	}

	stbi_image_free(m_Data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_TextureID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}