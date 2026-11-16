#include "VertexArray.h"
#include <vector>

#include "../engine/Log.h"



void VertexArray::Initialize()
{
	Log::Info("Initializing Vertex Array Object");
	glGenVertexArrays(1, &VAO);
	//Bind();
	// add vertex buffer will be done outside of init
	// set index will be done outseid init

	
}

void VertexArray::AddVertexBuffer(VertexBuffer& vbo, const VertexLayout& layout)
{
	Bind();
	vbo.Bind();

	const std::vector<VertexAttribute>& attributes = layout.GetAttribute();

	unsigned int index = 0;
	for (const VertexAttribute& attrib : attributes)
	{
		glVertexAttribPointer(
			index,
			attrib.componentCount,
			attrib.dataType,
			GL_FALSE,
			layout.GetStride(),
			(void*)(uintptr_t)attrib.offset
		);
		glEnableVertexAttribArray(index);

		index++;
	}
	Unbind();
	vbo.Unbind();
}

void VertexArray::SetIndexBuffer(IndexBuffer& ebo)
{
	Bind();
	ebo.Bind();
	indexCount = ebo.GetNumIndicies();
	Unbind();
}

unsigned int VertexArray::GetIndexCount() const
{
	return indexCount;
}

void VertexArray::Bind()
{
	glBindVertexArray(VAO);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::Shutdown()
{
	glDeleteVertexArrays(1, &VAO);
}
