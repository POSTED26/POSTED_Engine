POSTED Engine (Rendering) 

Purpose: 

POSTED Engine is an educational real-time rendering engine whose primary goal is to teach graphics programming, rendering architecture, GPU programming, and software design. 

The project prioritizes understandability over feature count and intentionally favors clear architecture over maximum performance. 

The renderer should remain small enough that one person can understand every subsystem. 

Non-goals: 

Non Goals 

Commercial engine 

Physics engine 

Audio engine 

Networking 

Animation system 

Scripting language 

Editor 

Multiplayer 

ECS (initially) 

Job system 

 

 

 

 

 

C++ Philosophy 

Use the simplest language feature that clearly solves the problem. 

Prefer 

classes  

RAII  

references  

std::vector  

std::string  

Avoid introducing 

templates  

inheritance  

shared_ptr  

move semantics  

virtual functions  

until they solve a real design problem. 

 

Organization: 

A file structure like this 

PostedEngine/ 

|- CMakeLists.txt 

|-external/ 

|-|-glfw/ 

|-|-glad/ 

|-|-glm/ 

|-shaders/ 

|-assests/ 

|-src/ 

|-|-main.cpp 

|-engine/ 

|-|-application.h 

|-|-application.cpp 

|-|- etc. 

|-build/ 

|- docs/ 

 

When to create a new class: 

When it is meaningful to extract it out. A file or class should be doing only one thing. If it is a camera class it should only do and know things the camera should do and know. If it starts to get things in there that it shouldnt have then it should be moved or create a new file/class for it. 

Composition vs inheritance: 

I think most things should be composition. The engine ‘has a’ camera and a window etc. It isnt a camera or a window. 

There are times for inheritance, but I think it would be cleaner to be composition. 

 

 

 

 

 

 

 

 

 

 

 

Data flow: 

Disk 

v

AssetManager 

v 

Model 

v

Mesh 

v 

Material 

v 

Shader 

v 

Renderer 

v 

GPU 

v 

Framebuffer 

v 

Screen 

There should be an asset manager that handles the selection and loading of assets. When the scene wants needs an asset it will call it and load it in, then it will handle the textures and other aspects of the asset. 
Mesh -> texture -> shader etc. The camera will then calculate what it sees and then it will go through the rendering process. What passes we have will affect the process as well.  

 

 

What will main.cpp contain: 

Not much, main.cpp is not the engine. It is just the code that will be responsible for creating the engine, initializing it, and starting it.  

 

Principals to guide the architecture: 

I think I will learn more as I go, but thinking about clean code. If it becomes messy to deal with, can I think of a way to make it more manageable. Files/classes should only be doing one thing. 
Only using classes for things that make sense. We will prefer the simplest design that solves today's problem while leaving room for tomorrow's requirements. Every subsystem should be independently understandable. 
Accept sensible default until there is a reason to customize them. 