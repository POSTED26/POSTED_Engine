# Milestone 5 design notes:
Geometry abstractions. Finishing up cleaning out the renderer class. Creating Vertex buffer, Index buffer, and vertex array classes.

## What problem are we solving:
cleaning out the renderer class to now have hardcoaded vertex data, this also enables me to have multiple vertex data and swap around which I want to use more easily.

## What are the requirements:
Creating the vertexbuffer,indexBuffer and vertexArray classes and having a object that we can use to draw with. 


## What are the constraints:
Each class being constarined to what they are responsible for. Indexbuffer should not be doing anything with vertexBuffer.

## What classes will be added:
A shader class. 

## Who owns the class:
vertexBuffer and IndexBuffer are owned by vertexArray and then vertex array is owned by Renderer.???

## General class interface:


## Why did I choose this design:
Vertexbuffer and IndexBuffer are for abstracting the openGL calls while vertexArray is for handiling the overall vertex information.


## What should this class not know:
These classes should only know about vertex/index information. 


### Checklist
Pass data into vbo and ebo, bind and pass data to gpu. create VAO then bind and connect everyting and draw. 

## Modifications to the original plan.
I added Texture class to be able to load images, and bind to texture and then activate to be drawn. 