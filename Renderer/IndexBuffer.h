#pragma once
#include <glad/gl.h>

class IndexBuffer
{
private:
	unsigned int EBO;
	unsigned int numIndicies;
public:
	void Initialize(const unsigned int* index, unsigned int size);
	unsigned int GetNumIndicies() const;
	void Bind();
	void Unbind();
	void Shutdown();
};