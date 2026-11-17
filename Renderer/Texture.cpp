#include "Texture.h"

#include "../engine/Log.h"

#include <glad/gl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../external/STB_IMAGE/stb_image.h"

void Texture::Load(const char* imgPath)
{
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(imgPath, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		Log::Error("Failed to load texture");
	}
	stbi_image_free(data);
}

void Texture::Initilize()
{
	glGenTextures(1, &texture);
	Bind();
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::Activate(unsigned int texNum) // maybe pass in which texture you need like 0 for TEXTURE0, 1 for TEXTURE1
{

	// TODO: each tecure would utilize GL_TEXUTRE0 at this point, having more than one at a time doesnt work yet.
	glActiveTexture(GL_TEXTURE0 + texNum);
	Bind();
}
