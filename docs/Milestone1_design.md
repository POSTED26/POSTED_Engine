# Milestone 1 design notes: 

## What problem are we solving: 

We are establishing the architectural foundation that every future graphics feature will build upon. We are building the project using cmake, and creating an application class that will oversee handling running and managing the renderer and building a logging class so we will have logging from the start. 

 

## What are the requirements: 

We need cmake downloaded, visual studio downloaded and enough knowledge of c++ and cmake to get it up and running. 

 

## What are the constraints: 

I am constrained by my knoweldge of cmake and c++.  

 

## What classes exist: 

There will be a Logging class to handle logging, a Application class to manage creation of the renderer and managing other aspects of the renderer, a folder structure created by cmake and a main.cpp file that is only responsible for creating the application class. 

 

## Which classes own other classess: 

Application class will own logger, Ideally it will be one instance of a logger for where ever we need to log. 

Logger will only be in charge of itself. 

Change -> Log will be a static class instead

 

## Project directory: 

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

 

## What should main.cpp do: 

Just start the application class. Create and initialize it and get it running. 

 

## Why did we make these decisions: 

We want the renderer to be well designed, this means that there will be an application that gets 
created and run and that will handle everything, logging is very useful so we have clear idea of what was 
happening when things went wrong or even or performance. Cmake is pretty standard for project builds. 