# Milestone 3 design notes:
Rendering class

## What problem are we solving:
We need a Rendering class that handles the graphics api. 

## What are the requirements:
We want to be able to initilize OpenGl, create an OpenGl context, clear the screan and shut down correctly.
The Renderer should start when the applications starts and closed when the application closes.


## What are the constraints:
We are only worrying about OpenGL right now, we dont need to design or using multiple graphics api.
There should not be any rendering code outside of the rendering class.

## What classes will be added:
There will be the renderer.h and renderer.cpp files with the Renderer class in it. 

## Who owns the renderer class:
PostedEngine will own the renderer class. Window will need to share context with renderer to be able to render to the window.

## General class interface:
void Initialize()
void Shutdown()
void Render()

## Why did I choose this design:
PostedEngine is responsible for orchestrating what the engine needs, ti should own the renderer and be able to call what needs to be called and pass things to it if needed.


## What should this class not know:
input, main loop, asset loading, etc. 


### Checklist
Add GLAD and get CMake configured
Create Renderer class structure
Establish OpenGL context
Initialize GLAD
Implement basic Renderer functionality
Update PostedEngine to use Renderer
Run and test