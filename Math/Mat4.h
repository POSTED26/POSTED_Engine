#pragma once

#include "Vec4.h"
#include "Vec3.h"

class Mat4
{
private:
	float data[16];
public:
	Mat4();
	Mat4(const float other[16]);

	float& At(int row, int col);
	float At(int row, int col) const;

	static Mat4 Identity();

	Mat4 operator+(const Mat4& other) const;
	Mat4 operator-(const Mat4& other) const;
	Mat4 operator*(const Mat4& other) const;
	Vec4 operator*(const Vec4& other) const;
	Mat4 operator*(float scalar) const;

	float Determinant() const;
	Mat4 Transpose() const;
	bool Inverse(Mat4& result) const;

	static Mat4 Scale(float scale);
	static Mat4 Scale(const Vec3& scale);

	static Mat4 Translation(const Vec3& position);
	
	static Mat4 RotateX(float angle);
	static Mat4 RotateY(float angle);
	static Mat4 RotateZ(float angle);

	void Print() const;
};