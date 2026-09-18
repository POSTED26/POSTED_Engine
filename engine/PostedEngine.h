#pragma once
#include "../Window/window.h"
#include "../Renderer/Renderer.h"

class PostedEngine
{
private:
	Window window;
	Renderer renderer;
public:
	PostedEngine();
	bool Initialize();
	void Run();
	void Shutdown();
};