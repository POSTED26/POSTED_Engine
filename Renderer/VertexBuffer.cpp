#include "VertexBuffer.h"

#include "../engine/Log.h"





void VertexBuffer::Initialize(const float* data, unsigned int size)
{
	Log::Info("Initializing Vertex Buffer");
	glGenBuffers(1, &VBO);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	Unbind();
}

void VertexBuffer::Bind()
{
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Shutdown()
{
	glDeleteBuffers(1, &VBO);
}
