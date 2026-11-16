#include "IndexBuffer.h"

#include "../engine/Log.h"



void IndexBuffer::Initialize(const unsigned int* indices, unsigned int size)
{
	Log::Info("Initializing Index Buffer");
	glGenBuffers(1, &EBO);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	numIndicies = size / sizeof(unsigned int);// sizeof(indices) / sizeof(indices[0]);
	Unbind();
}

unsigned int IndexBuffer::GetNumIndicies() const
{
	return numIndicies;
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Shutdown()
{
	glDeleteBuffers(1, &EBO);
}
