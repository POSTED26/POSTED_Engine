# Milestone 2 design notes:

## What problem are we solving:
The engine needs a platform window that owns communication with the OS. It provides a rendering surface and provides 
system events to the engine.

## What are the requirements:
We want a window to be created and to be able to handle user input to handle closing the window.
The window should start when you run the application and close and handle clean up.

## What are the constraints:
We dont need to worry about resizing or anything else, just have a window and be able to close it.
It should not be hard to swap out how we create a window and the end user should not be concerned with those details.

## What classes will be added:
There will be the window.h and window.cpp files with the Window class in it. 

## Who owns the window class:
PostedEngine will own the window class. It will be responsible for initializing it and handing polling and other functions.

## General class interface:
void Initialize()
void Shutdown()
bool ShouldClose()
void PollEvents()
void SwapBuffers()
int getWidth()
int getHeight()

## Why did I choose this desing:
Having the window have its own class allows for possible window creation methods (GLFW, Windows, MacOS, Linux, SDL2)
The user would see roughly the same thing and not have to worry about have all the window code hanging around.
It is clean and contained by itself.

## What should this class not know:
Anything that isnt important to the window. It should just be a window with a size and then be told to poll input and swap buffers.


### Checklist
Add GLFW, GLAD and GLM to the project and get CMake to link them
Create Window class structure
Add GLFWwindow as a private member
Implement the fuctions of the window class
Update PostedEngine to use the window class
have engine.Run() actually have a loop to keep the window open
Run and test.