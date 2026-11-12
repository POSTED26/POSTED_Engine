# Milestone 5 design notes:
Shader class for better management of shaders 

## What problem are we solving:
Getting shaders from strings to files, reading and managing the shader objects for easier compilation and handling.

## What are the requirements:
Reading shaders from files and a shader object handling the compilation and binding.


## What are the constraints:
Just working within the shader class and the renderer class. Renderer class for creating the shader object.

## What classes will be added:
A shader class. 

## Who owns the class:
Renderer

## General class interface:
bool Compile(vertexPath, fragPath)
void Bind()
void Unbind()
void Shutdown()

## Why did I choose this design:
Keeping renderer in charge of the sahder objects. choosing to bind and unbind should be its responsibility. Passing in the paths for shaders and then having the shader be responsible for the compile and link. 


## What should this class not know:
The class should not know anything outside of the shader class. Just getting shader code passed in.


### Checklist
Create shader .h and .cpp
Add in the logic for reading the shader files
compile and link the shader code
bind the shader
the result should be the same as before. 