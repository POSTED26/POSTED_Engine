#pragma once
#include "ShaderLibrary.h"
#include "VertexLayout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

class Renderer
{
private:
	VertexLayout layout;
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;
	VertexArray vao;
    ShaderLibrary shaderLibrary;
    unsigned int VAO, EBO;
public:
	bool Initialize();
	void Shutdown();
	void Render();


};
