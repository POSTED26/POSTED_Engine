
#include "PostedEngine.h"
#include "Log.h"
#include "../Window/Window.h"
#include "../Renderer/Renderer.h"



PostedEngine::PostedEngine() : window(800, 600, "POSTED Engine")
{

}

bool PostedEngine::Initialize()
{
	Log::Info("Initializing POSTED Engine");

	//Window window(800, 600, "POSTED Engine");
	if (!window.Initialize())
		return false;

	if (!renderer.Initialize())
	{
		return false;
	}

	return true;
}

void PostedEngine::Run()
{
	Log::Info("Starting the main loop");
	while (!window.ShouldClose())
	{
		window.PollEvents();
		renderer.Render();
		window.SwapBuffers();
	}

}

void PostedEngine::Shutdown()
{
	Log::Info("Shutting down POSTED Engine");
	renderer.Shutdown();
	window.Shutdown();
}


