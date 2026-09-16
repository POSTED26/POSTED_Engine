#pragma once
#include "window.h"

class PostedEngine
{
private:
	Window window;
public:
	PostedEngine();
	bool Initialize();
	void Run();
	void Shutdown();
};