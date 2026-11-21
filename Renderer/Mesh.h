#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexLayout.h"

class Mesh
{
private:
	VertexArray vao;
	VertexBuffer vbo;
	IndexBuffer ebo;
	VertexLayout layout;
public:
	void Initialize(const float* vertex, unsigned int vertexSize,
		const unsigned int* index, unsigned int indexSize,
		const VertexLayout& layout);
	void Bind();
	void Shutdown();
	void LoadObjFile(const char* meshPath);

	unsigned int GetIndexCount() const;
};