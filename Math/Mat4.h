#pragma once

#include "Vec4.h"

class Mat4
{
private:
	float data[16];
public:
	Mat4();
	Mat4(float other[16]);

	float& At(int row, int col);
	float At(int row, int col) const;

	static Mat4 Identity();

	Mat4 operator+(const Mat4& other) const;
	Mat4 operator-(const Mat4& other) const;
	Mat4 operator*(const Mat4& other) const;
	Mat4 operator*(const Mat4& other) const;
	Vec4 operator*(const Vec4& other) const;
	Mat4 operator*(float scalar) const;

	float Determinant() const;
	Mat4 Transpose() const;
	Mat4 Inverse() const;
};