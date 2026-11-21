#include "Mesh.h"

#include <filesystem>
#include <map>
#include <vector>

#include "../engine/Log.h"

#include "../external/RapidObj/rapidobj.hpp"


struct VertexData
{
	int pos;
	int tex;
	int normal;

	bool operator<(const VertexData& other) const
	{
		if (pos != other.pos)
			return pos < other.pos;

		if (tex != other.tex)
			return tex < other.tex;

		return normal < other.normal;
	}
	//VertexData(int pos, int tex, int normal) : pos(pos), tex(tex), normal(normal) {};
};

void Mesh::Initialize(const float* vertex, unsigned int vertexSize,
	const unsigned int* index, unsigned int indexSize,
	const VertexLayout& layout)
{
	vbo.Initialize(vertex, vertexSize);
	ebo.Initialize(index, indexSize);

	vao.Initialize();
	vao.AddVertexBuffer(vbo, layout);
	vao.SetIndexBuffer(ebo);
}

void Mesh::Bind()
{
	vao.Bind();
}

void Mesh::Shutdown()
{
	vao.Shutdown();
	vbo.Shutdown();
	ebo.Shutdown();
	
}

void Mesh::LoadObjFile(const char* meshPath)
{
	std::filesystem::path filePath = meshPath;
	rapidobj::Result result = rapidobj::ParseFile(filePath, rapidobj::MaterialLibrary::Ignore());

	if (result.error)
	{
		Log::Error("Error loading OBJ: " + result.error.code.message());

	}
	bool success = rapidobj::Triangulate(result);

	if (!success)
	{
		Log::Error("Error Triangulate OBJ: " + result.error.code.message());
	}

	//size_t num_tri{};
	//size_t num_index{};
	
	for (const auto& shape : result.shapes)
	{
		for (unsigned char faceSize : shape.mesh.num_face_vertices)
		{
			if (faceSize != 3)
			{
				Log::Error("Found a face that is not a triangle!");
			}
		}
	}


	std::vector<int> idx;
	std::vector<float> vertexArray;
	std::map<VertexData, int> vertices;
	for (const auto& shape : result.shapes)
	{
		//num_tri += shape.mesh.num_face_vertices.size();
		//num_index += shape.mesh.indices.size();
		Log::Info("Shape names: " + shape.name);

		//unsigned int idx[(int)num_index];
		
		int key = 0;
		for (const auto& index : shape.mesh.indices)
		{
			// check if map is empty if it is then add in
			auto [it, inserted] = vertices.try_emplace(
				VertexData{ index.position_index, index.texcoord_index, index.normal_index }, key);
			
			if (!inserted)
			{
				// add key to idx
				idx.push_back(it->second);
			}

			// if inserted increase key,only want to do it if inserted. 
			if (inserted)
			{
				
				idx.push_back(key);
				vertexArray.push_back(result.attributes.positions[it->first.pos * 3]);
				vertexArray.push_back(result.attributes.positions[it->first.pos * 3 + 1]);
				vertexArray.push_back(result.attributes.positions[it->first.pos * 3 + 2]);
				vertexArray.push_back(result.attributes.texcoords[it->first.tex * 2]);
				vertexArray.push_back(result.attributes.texcoords[it->first.tex * 2 + 1]);
				vertexArray.push_back(result.attributes.normals[it->first.normal * 3]);
				vertexArray.push_back(result.attributes.normals[it->first.normal * 3 + 1]);
				vertexArray.push_back(result.attributes.normals[it->first.normal * 3 + 2]);
				key++;
			}
		}
		
		/*
			I need to go throughall index and dedupe them.
			then go through that and find the actual data and construct my vbo.
		*/

	}
	/*
	Log::Info("Index size: " + std::to_string(idx.size()));
	Log::Info("Vertex: " + std::to_string(vertexArray.at(0)) + std::to_string(vertexArray.at(1))
		+ std::to_string(vertexArray.at(2)));
		*/
	Log::Info("Index count: " + std::to_string(idx.size()));
	Log::Info("Unique vertex count: " + std::to_string(vertexArray.size() / 8));
	unsigned int maxIndex = 0;

	for (unsigned int index : idx)
	{
		if (index > maxIndex)
			maxIndex = index;
	}

	Log::Info("Maximum index: " + std::to_string(maxIndex));
	

	auto indexBuffer = std::make_unique<unsigned int[]>(idx.size());
	auto vertexBuff = std::make_unique<float[]>(vertexArray.size());
	std::copy(idx.begin(), idx.end(), indexBuffer.get());
	std::copy(vertexArray.begin(), vertexArray.end(), vertexBuff.get());

	layout.AddFloat(3); // pos
	layout.AddFloat(2); // tex
	layout.AddFloat(3); // normal

	Initialize(vertexBuff.get(), vertexArray.size() * sizeof(float), indexBuffer.get(), idx.size() * sizeof(int), layout);
	

	
}

unsigned int Mesh::GetIndexCount() const
{
	return vao.GetIndexCount();
}
