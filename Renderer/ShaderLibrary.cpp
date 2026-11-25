#include "ShaderLibrary.h"
#include "../engine/Log.h"



bool ShaderLibrary::Load(const std::string& name, const char* vertexPath, const char* fragPath)
{
	auto [it, inserted] = shaders.try_emplace(name);

	if (!inserted)
	{
		Log::Error("Shader already exits: " + name);
		return false;
	}

	if (!it->second.Compile(vertexPath, fragPath))
	{
		shaders.erase(it);
		return false;
	}

	return true;
}

bool ShaderLibrary::Initialize()
{
	Log::Info("Started Initialize ShaderLibrary");

	if (!Load("basic", "Resources/Shaders/basic.vs", "Resources/Shaders/basic.fs"))
	{
		Log::Error("Failed to load basic shader");
		return false;
	}

	if (!Load("light", "Resources/Shaders/light.vs", "Resources/Shaders/light.fs"))
	{
		Log::Error("Failed to load light shader");
		return false;
	}

	Log::Info("Successfully loaded shaders");


	return true;
}

Shader* ShaderLibrary::Get(const std::string& name)
{
	auto it = shaders.find(name);

	if (it == shaders.end())
		return nullptr;

	return &it->second;
}

void ShaderLibrary::Shutdown()
{
	for (auto& [name, shader] : shaders)
	{
		shader.Shutdown();
	}
}
