# Milestone 5 design notes:
Add a Mesh class. This is just an absraction for loading vertex data into and displaying.
Want to have an option to load Obj files, so I plan to use RapidObj for file parsing. 

## What problem are we solving:
A cleaner renderer class, with the ability to more easily attach other things like materials to vertex data. 
being able to load in 3d objects that are online into my engine for testing more complex shapes than just a cube.

## What are the requirements:
Creating a Mesh class that can take VAO, VBO and EBO data and display it as well as loading an OBJ file and display it correctly.

## What are the constraints:
should only care about preparing vertex data to be drawn.

## What classes will be added:
Mesh

## Who owns the class:
renderer should own the class. It will utilize the vertexBuffer, vertexArray and IndexBuffer classes.

## General class interface:
Init for passing in data and then a load OBJ function. I will need to bind it, a shutdown to signal the destruction of the sub classes.


## Why did I choose this design:
It helps down the road for flexability and I can add funtions to load other file formats too.

## What should this class not know:
It should just know vertex data. 


### Checklist
Create Mesh class
Init function should basically be the code that is currently in the renderer class but hidden.
Use rapidOBJ to load files in. 
Implement my logic to turn the data from the files into data that can work with my engine.

## Modifications to the original plan.
