#pragma once

#include "../Math/Vec2.h"
#include "../Math/Vec3.h"
#include "../Math/Vec4.h"
#include "../Math/Mat4.h"


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
	void setVec2(const std::string& name, const Vec2& value) const;
	void setVec2(const std::string& name, float x, float y) const;
	void setVec3(const std::string& name, const Vec3& value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec4(const std::string& name, const Vec4& value) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;
	void setMat4(const std::string& name, const Mat4& value) const;
	
};