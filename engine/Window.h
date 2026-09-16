#pragma once
#include <GLFW/glfw3.h>


class Window
{
private:
	int width;
	int height;
	std::string title;
	GLFWwindow* window;
public:
	Window(int width, int height, const std::string& title);
	bool Initialize();
	void Shutdown();
	void SwapBuffers();
	bool ShouldClose();
	void PollEvents();
	int GetWidth();
	int GetHeight();
};