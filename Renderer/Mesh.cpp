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
	

	std::vector<int> idx;
	std::vector<float> vertexArray;
	std::map<int, VertexData> vertices;
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
			auto [it, inserted] = vertices.try_emplace(key, 
				VertexData{ index.position_index, index.texcoord_index, index.normal_index });
			
			if (!inserted)
			{
				// add key to idx
				idx.push_back(it->first);
			}

			// if inserted increase key,only want to do it if inserted. 
			if (inserted)
			{
				key++;
				idx.push_back(key);
				vertexArray.push_back(result.attributes.positions[it->second.pos * 3]);
				vertexArray.push_back(result.attributes.positions[it->second.pos * 3 + 1]);
				vertexArray.push_back(result.attributes.positions[it->second.pos * 3 + 2]);
				vertexArray.push_back(result.attributes.positions[it->second.tex * 2]);
				vertexArray.push_back(result.attributes.positions[it->second.tex * 2 + 1]);
				vertexArray.push_back(result.attributes.positions[it->second.normal * 3]);
				vertexArray.push_back(result.attributes.positions[it->second.normal * 3 + 1]);
				vertexArray.push_back(result.attributes.positions[it->second.normal * 3 + 2]);
			}
		}
		
		/*
			I need to go throughall index and dedupe them.
			then go through that and find the actual data and construct my vbo.
		*/

	}

	Log::Info("Index size: " + std::to_string(idx.size()));
	Log::Info("Vertex: " + std::to_string(vertexArray.at(0)) + std::to_string(vertexArray.at(1))
		+ std::to_string(vertexArray.at(2)));

	//Log::Info("Shapes: " + std::to_string(result.shapes.size()));
	//Log::Info("Triangles: " + std::to_string(num_tri));
	//Log::Info("Indicies: " + std::to_string(num_index));

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
