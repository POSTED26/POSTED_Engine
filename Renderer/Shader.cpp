#include "Shader.h"
#include "../engine/Log.h"


#include <fstream>
#include <sstream>
#include <filesystem>

#include <glad/gl.h>
#include <GLFW/glfw3.h>


bool Shader::CheckCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[512];
	if (type != "Program")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			Log::Error(type + " shader compilation failed" + std::string(infoLog));
			return false;
			//std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
			Log::Error(type + " shader linking failed" + std::string(infoLog));
			return false;
			//std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
	return true;
}

bool Shader::Compile(const char* vertexPath, const char* fragPath)
{
	std::string vertexCode;
	std::string fragCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	
	try
	{
		// Open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragPath);
		std::stringstream vShaderStream, fShaderStream;
		// read file buffer contents into stream
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragCode = fShaderStream.str();

	}
	catch (std::ifstream::failure& e)
	{
		Log::Error(std::string("Shader file read failed: ") + e.what());
		return false;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragCode.c_str();

	unsigned vertex, frag;
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	if (!CheckCompileErrors(vertex, "Vertex"))
		return false;

	// frag shader
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fShaderCode, NULL);
	glCompileShader(frag);
	if (!CheckCompileErrors(frag, "Fragment"))
		return false;

	// link shaders
	programID = glCreateProgram();
	glAttachShader(programID, vertex);
	glAttachShader(programID, frag);
	glLinkProgram(programID);
	if (!CheckCompileErrors(programID, "Program"))
		return false;

	// delete shaders
	glDeleteShader(vertex);
	glDeleteShader(frag);


	return true;
}

void Shader::Bind()
{
	if (programID == 0)
	{
		Log::Error("Attempted to bind an invalid shader program");
		return;
	}
	glUseProgram(programID);
}

void Shader::Unbind()
{
}



void Shader::Shutdown()
{
	if (programID != 0)
	{
		glDeleteProgram(programID);
		programID = 0;
	}
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}
