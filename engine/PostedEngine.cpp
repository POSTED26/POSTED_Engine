
#include "PostedEngine.h"
#include "Log.h"

bool PostedEngine::Initialize()
{
	Log::Info("Initializing POSTED Engine");
	return true;
}

void PostedEngine::Run()
{
	Log::Info("Starting the main loop");
}

void PostedEngine::Shutdown()
{
	Log::Info("Shutting down POSTED Engine");
}


