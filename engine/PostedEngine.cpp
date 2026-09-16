
#include "PostedEngine.h"
#include "Log.h"
#include "Window.h"



PostedEngine::PostedEngine() : window(nullptr)
{

}

bool PostedEngine::Initialize()
{
	Log::Info("Initializing POSTED Engine");

	Window window(800, 600, "POSTED Engine");
	if (!window.Initialize())
		return false;



	return true;
}

void PostedEngine::Run()
{
	Log::Info("Starting the main loop");
	while (!window.ShouldClose())
	{

	}
}

void PostedEngine::Shutdown()
{
	Log::Info("Shutting down POSTED Engine");
}


