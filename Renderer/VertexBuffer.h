#pragma once

#include <glad/gl.h>

class VertexBuffer
{
private:
	unsigned int VBO;
	
public:
	void Initialize(const float* data, unsigned int size);
	void Bind();
	void Unbind();
	void Shutdown();
};