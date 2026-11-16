#pragma once
#include "VertexBuffer.h"
#include "VertexLayout.h"
#include "IndexBuffer.h"

class VertexArray
{
private:
	unsigned int VAO;
	unsigned int indexCount = 0;
public:
	void Initialize();
	void AddVertexBuffer(VertexBuffer& vbo, const VertexLayout& layout);
	void SetIndexBuffer(IndexBuffer& ebo);
	unsigned int GetIndexCount() const;
	void Bind();
	void Unbind();
	void Shutdown();
};