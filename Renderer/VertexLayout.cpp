#include "VertexLayout.h"

#include "../engine/Log.h"

void VertexLayout::AddFloat(unsigned int count)
{
	VertexAttribute attribute;
	attribute.componentCount = count;
	attribute.dataType = GL_FLOAT;
	attribute.offset = stride;

	stride += count * sizeof(float);

	attributes.push_back(attribute);

}

const std::vector<VertexAttribute>& VertexLayout::GetAttribute() const
{
	return attributes;
}

unsigned int VertexLayout::GetStride() const
{
	return stride;
}
