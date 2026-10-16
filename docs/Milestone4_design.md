# Milestone 4 design notes:
Draw a triangle

## What problem are we solving:
Getting a triangle on the screen. Making sure we can utilize openGl to draw shapes.

## What are the requirements:
Utilizing openGl to draw a triangle and fill it. This means using a vertex and fragment shader.


## What are the constraints:
The only worry is getting the triangle to show up on the screen. Not currently worried about shader management or where vertex data gets created.
vertex data will most likey be hard coded within the Renderer class.

## What classes will be added:
I dont think I will add any this milestone. The very simple shader code will most likey be a const string within the renderer class.

## Who owns the class:
N/A

## General class interface:
N/A

## Why did I choose this design:
Just need to get openGL to draw a triangle. This is more of a does it work rather than a design milestone. I will next milestone get shaders more fleshed out with their own class and management system.


## What should this class not know:
Anything not important to renderering. We care about vertex data currently and so it will have it but later maybe that data lives elsewhere.


### Checklist
create vertex data.
load into opengl.
minimal vertex and fragment shader.
compile and link shaders.
draw.
verify it is correct.