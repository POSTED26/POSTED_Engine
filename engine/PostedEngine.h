#pragma once
#include "../Window/window.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Camera.h"

class PostedEngine
{
private:
	Window window;
	Renderer renderer;
	Camera camera;
public:
	PostedEngine();
	bool Initialize();
	void Run();
	void Shutdown();
	void ProcessInput(float deltaTime);
};