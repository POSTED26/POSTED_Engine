#pragma once

#include <string>
#include <unordered_map>
#include "Shader.h"

class ShaderLibrary
{
private:
	std::unordered_map<std::string, Shader> shaders;
	bool Load(const std::string& name, const char* vertexPath, const char* fragPaht);
public:
	bool Initialize();
	Shader* Get(const std::string& name);
	void Shutdown();

};
