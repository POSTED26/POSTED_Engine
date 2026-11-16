#include "Renderer.h"
#include "../engine/Log.h"

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>



bool Renderer::Initialize()
{
	Log::Info("Initializing Renderer");
	if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
	{
		Log::Error("Failed to init GLAD");
		return false;
	}

	Log::Info("GLAD initialized successfully");

    const GLubyte* version = glGetString(GL_VERSION);

    Log::Info(
        "OpenGL Version: " +
        std::string(reinterpret_cast<const char*>(version))
    );

    // Init shader Library. Complies all shaders and loads to a map
    shaderLibrary.Initialize();
	
    // layout creation
    layout.AddFloat(3); // pos
    layout.AddFloat(3); // color
    
    
    /*
	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};*/
    float vertices[] = {
        // pos              // color
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// top right
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f,   // top left 
    };
    /*
    float vertices[] = {
        0.0f, 0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };*/
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

    // vao, vbo, ebo creation
    vertexBuffer.Initialize(vertices, sizeof(vertices));
    indexBuffer.Initialize(indices, sizeof(indices));

    // createed vbo and ebo and unbound
    // create and bind vao then attach and re-bind vbo and ebo
    // dont unbind before you unbind vao
	
    vao.Initialize();
    vao.AddVertexBuffer(vertexBuffer, layout);
    vao.SetIndexBuffer(indexBuffer);

	return true;
}

void Renderer::Shutdown()
{
	Log::Info("Shutting down Renderer");
    vao.Shutdown();
    vertexBuffer.Shutdown();
    indexBuffer.Shutdown();
    shaderLibrary.Shutdown();
}


void Renderer::Render()
{
	
	glClearColor(0.1,0.1,0.5,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

    // drawing
    
    shaderLibrary.Get("basic")->Bind();

    // colors?

  
    vao.Bind();
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, vao.GetIndexCount(), GL_UNSIGNED_INT, nullptr);



}