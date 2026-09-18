

#include "Window.h"
#include "../engine/Log.h"
#include <iostream>

#include <GLFW/glfw3.h>




Window::Window(int width, int height, const std::string& title) : width(width), height(height), title(title), window(nullptr)
{
	Log::Info("Creating a window of size: " + std::to_string(width) + " x " + std::to_string(height));
}



bool Window::Initialize()
{
	Log::Info("Initializing Window");

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (window == NULL)
	{
		Log::Error("Failed to create GLFW window");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);
	return true;
}

void Window::Shutdown()
{
	Log::Info("Shutting down window");
	if (window != nullptr)
	{
		glfwDestroyWindow(window);
		window = nullptr;
	}


	glfwTerminate();
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}

bool Window::ShouldClose()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		return true;
	return glfwWindowShouldClose(window);
}

void Window::PollEvents()
{
	glfwPollEvents();
}

int Window::GetWidth()
{
	return width;
}

int Window::GetHeight()
{
	return height;
}







