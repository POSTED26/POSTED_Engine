#include "Renderer.h"
#include "../engine/Log.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>



bool Renderer::Initialize()
{
	Log::Info("Initializing Renderer");
	if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
	{
		Log::Error("Failed to init GLAD");
		return false;
	}

	Log::Info("GLAD initialized successfully");

	const GLubyte* version = glGetString(GL_VERSION);
	Log::Info("OpenGL Version: " + std::string(reinterpret_cast<const char*>(version)));

	return true;
}

void Renderer::Shutdown()
{
	Log::Info("Shutting down Renderer");
}


void Renderer::Render()
{
	
	glClearColor(0.8,0.2,0.5,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

}