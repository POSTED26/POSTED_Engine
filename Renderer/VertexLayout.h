#pragma once

#include <glad/gl.h>

#include <vector>

struct VertexAttribute
{
	unsigned int componentCount;
	GLenum dataType;
	unsigned int offset;
};

class VertexLayout 
{
private:
	std::vector<VertexAttribute> attributes;
	unsigned int stride = 0;

public:
	void AddFloat(unsigned int count);
	const std::vector<VertexAttribute>& GetAttribute() const;
	unsigned int GetStride() const;
};