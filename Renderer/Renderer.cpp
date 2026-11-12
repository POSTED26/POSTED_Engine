#include "Renderer.h"
#include "../engine/Log.h"

#include <glad/gl.h>
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
	
    /*
	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};*/
    float vertices[] = {
        0.0f, 0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};
	
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

	return true;
}

void Renderer::Shutdown()
{
	Log::Info("Shutting down Renderer");
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    //glDeleteProgram(shaderProgram);
    shaderLibrary.Shutdown();
}


void Renderer::Render()
{
	
	glClearColor(0.1,0.1,0.5,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

    // drawing
    //glUseProgram(shaderProgram);
    
    shaderLibrary.Get("basic")->Bind();

 

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



}