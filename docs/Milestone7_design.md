# Milestone 5 design notes:
Add a math library, Vec2 vex3, vec4 and mat4 and mat 3 maybe. Learn about the inner working of these to better understand the 
projection, transaltion and scaling needed for 3D rendering.

## What problem are we solving:
We need to perform tasks to have our view be 3d and we need to move 3d shapes around.

## What are the requirements:
Creating a small math library for my own use.

## What are the constraints:
Math functions will only know what is passed to them nothing else.

## What classes will be added:
vec2, vec3, vec4, mat4 maybe mat3

## Who owns the class:
they all own themselves and that is it.

## General class interface:
vectors have basic vector arithmatic. Add sub, cross dot, etc. Matrix has identity, transpose, multiply, etc.

## Why did I choose this design:
I could have used a math library like glm but I want to learn how these things work. later on I might switch it out if needed.

## What should this class not know:
It should only know its own thigns. 


### Checklist
Classes created with their math operations available.
They work. I will test the output.

## Modifications to the original plan.
This is currently scoped for just the math library but I might add a transform class, I dont think it is needed yet.
I might add some projections so show a cube.

I also added a camera class which is basically a wrapper around my Mat4 perspective and LookAt functoins. It also has some basic movement
