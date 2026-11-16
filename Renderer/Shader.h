#pragma once

#include <string>

class Shader {
private:
	unsigned int programID = 0;

	bool CheckCompileErrors(unsigned int shader, std::string type);
public:
	bool Compile(const char* vertexPath, const char* fragPath);
	void Bind();
	void Unbind();
	void Shutdown();
	// uniform functionality later
	void setInt(const std::string& name, int value) const;
};