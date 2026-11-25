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

    // gloval config
    glEnable(GL_DEPTH_TEST);


    // Init shader Library. Complies all shaders and loads to a map
    shaderLibrary.Initialize();
	
    // layout creation
    layout.AddFloat(3); // pos
    layout.AddFloat(3); // color
    layout.AddFloat(3);
    //layout.AddFloat(2); // texture coords
    
    


    /*
	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};*/
    float vertices[] = {
        // pos              // color          // normals          // texture coords
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, /* 1.0f, 1.0f,*/   //f top right
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, /* 1.0f, 0.0f, */  //f bottom right
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, /* 0.0f, 0.0f, */  //f bottom left
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, /* 0.0f, 1.0f,*/   //f top left 
 
        0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,/* 1.0f, 1.0f,*/   //r top right
        0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, /*1.0f, 0.0f, */  //r bot right
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,/* 0.0f, 0.0f,*/   //r bot left
        0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, /*0.0f, 1.0f, */  //r top right

        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, /*1.0f, 1.0f,*/  //back top right
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, /* 1.0f, 0.0f,*/  //back bot right
        0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f, /* 0.0f, 0.0f, */  //back bot left
        0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,/* 0.0f, 1.0f,*/   //back top left

        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, /* 1.0f, 1.0f,*/  //l top right
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, /* 1.0f, 0.0f,*/  //l bot right
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, /* 0.0f, 0.0f,*/
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, /*0.0f, 1.0f,*/

        0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, /* 1.0f, 1.0f,*/
        0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, /* 1.0f, 0.0f,*/
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,0.0f, 1.0f, 0.0f, /* 0.0f, 0.0f,*/
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,0.0f, 1.0f, 0.0f, /* 0.0f, 1.0f,*/

        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,/* 1.0f, 1.0f,*/
        0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,/* 1.0f, 0.0f,*/
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f,-1.0f, 0.0f,/* 0.0f, 0.0f,*/
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f,-1.0f, 0.0f/* 0.0f, 1.0f,*/


    };
    /*
    float vertices[] = {
        0.0f, 0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };*/
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  //f first Triangle
		1, 2, 3,   //f second Triangle
        4, 5, 7,
        5, 6, 7,
        8, 9, 11,
        9, 10, 11,
        12, 13, 15,
        13, 14, 15,
        16, 17, 19,
        17, 18, 19,
        20, 21, 23,
        21, 22, 23
	};

    // Mesh setup
    //mesh.Initialize(vertices, sizeof(vertices), indices, sizeof(indices), layout);

    mesh.LoadObjFile("Resources/Meshs/hornet.obj");

    light.Initialize(vertices, sizeof(vertices), indices, sizeof(indices), layout);

    // vao, vbo, ebo creation

    //vertexBuffer.Initialize(vertices, sizeof(vertices));
    //indexBuffer.Initialize(indices, sizeof(indices));

    // createed vbo and ebo and unbound
    // create and bind vao then attach and re-bind vbo and ebo
    // dont unbind before you unbind vao
	
    //vao.Initialize();
    //vao.AddVertexBuffer(vertexBuffer, layout);
    //vao.SetIndexBuffer(indexBuffer);

    // texture


    texture.Initilize();
    texture.Load("Resources/Textures/container.jpg");

    // uniforms
    Vec3 lightColor = Vec3(1.0f, 1.0f, 1.0f);
    shaderLibrary.Get("basic")->Bind();
    shaderLibrary.Get("basic")->setInt("texture1", 0);
    shaderLibrary.Get("basic")->setVec3("lightColor", lightColor);
    shaderLibrary.Get("basic")->setVec3("objectColor", Vec3(0.9352f, 0.8490f, 0.0017f));

    shaderLibrary.Get("light")->Bind();
    shaderLibrary.Get("light")->setVec3("lightColor", lightColor);

	return true;
}

void Renderer::Shutdown()
{
	Log::Info("Shutting down Renderer");
    //vao.Shutdown();
    //vertexBuffer.Shutdown();
    //indexBuffer.Shutdown();
    mesh.Shutdown();
    shaderLibrary.Shutdown();
}


void Renderer::Render(const Camera& camera)
{
	
	glClearColor(0.1,0.1,0.1,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    Vec3 lightPos = Vec3(-0.8f, 0.8f, -0.5f);

    // drawing
    
    shaderLibrary.Get("basic")->Bind();

    Mat4 view = camera.GetViewMatrix();  //Mat4::LookAt(Vec3(0.0f, 0.0f, -3.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
    Mat4 proj = camera.GetProjectionMatrix(); //Mat4::Perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    Mat4 model = Mat4();
    model = model * Mat4::RotateY(1.5f);

    shaderLibrary.Get("basic")->setMat4("view", view);
    shaderLibrary.Get("basic")->setMat4("projection", proj);
    shaderLibrary.Get("basic")->setMat4("model", model);
    shaderLibrary.Get("basic")->setVec3("lightPos", lightPos);


    // texture
    texture.Activate(0);


    //vao.Bind();
    mesh.Bind();

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr);

    // light
    shaderLibrary.Get("light")->Bind();

    // light model view proj
    Mat4 lightModel = Mat4() * Mat4::Translation(lightPos) * Mat4::Scale(Vec3(0.2f, 0.2f, 0.2f));

    shaderLibrary.Get("light")->setMat4("view", view);
    shaderLibrary.Get("light")->setMat4("projection", proj);
    shaderLibrary.Get("light")->setMat4("model", lightModel);

    

 

    light.Bind();
    glDrawElements(GL_TRIANGLES, light.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
 
}