#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <string>


class Window
{
private:
	int width;
	int height;
	bool wasResized;
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
	GLFWwindow* GetNativeWindow() const;

	bool WasResized();
	void SetResized(bool resize);

	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};