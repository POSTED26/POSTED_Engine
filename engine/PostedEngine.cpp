
#include "PostedEngine.h"
#include "Log.h"
#include "../Window/Window.h"
#include "../Renderer/Renderer.h"


#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


PostedEngine::PostedEngine() 
	: window(800, 600, "POSTED Engine"), camera(45.0f, window.GetWidth() / window.GetHeight(), 0.1f, 100.0f)
{
	//camera = Camera(45.0f, window.GetWidth() / window.GetHeight(), 0.1f, 100.0f);
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
	double prevTime = glfwGetTime();

	while (!window.ShouldClose())
	{
		double currTime = glfwGetTime();
		float deltaTime = (float)(currTime - prevTime);
		prevTime = currTime;
		window.PollEvents();
		ProcessInput(deltaTime);
		renderer.Render(camera);
		window.SwapBuffers();
	}

}

void PostedEngine::Shutdown()
{
	Log::Info("Shutting down POSTED Engine");
	renderer.Shutdown();
	window.Shutdown();
}

void PostedEngine::ProcessInput(float deltaTime)
{
	float moveSpeed = 5.0f * deltaTime;
	float turnSpeed = 30.0f * deltaTime;

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_W) == GLFW_PRESS)
		camera.MoveForward(moveSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_S) == GLFW_PRESS)
		camera.MoveForward(-moveSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_D) == GLFW_PRESS)
		camera.MoveRight(-moveSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_A) == GLFW_PRESS)
		camera.MoveRight(moveSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
		camera.MoveUp(moveSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		camera.MoveUp(-moveSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_Q) == GLFW_PRESS)
		camera.TurnRight(turnSpeed);

	if (glfwGetKey(window.GetNativeWindow(), GLFW_KEY_E) == GLFW_PRESS)
		camera.TurnRight(-turnSpeed);

}


