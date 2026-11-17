#include "Mat4.h"
#include <cmath>

#include <iostream>
#include <iomanip>

Mat4::Mat4()
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (row == col)
				At(row, col) = 1.0f;
			else
				At(row, col) = 0.0f;
		}
	}
}

Mat4::Mat4(const float other[16])
{
	int index = 0;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			data[index] = other[row * 4 + col];
			index++;
		}
	}
}

float& Mat4::At(int row, int col)
{
	return data[col * 4 + row];
}

float Mat4::At(int row, int col) const
{
	return data[col * 4 + row];
}

Mat4 Mat4::Identity()
{
	return Mat4();
}

Mat4 Mat4::operator+(const Mat4& other) const
{
	Mat4 result;
	for (int i = 0; i < 16; i++)
		result.data[i] = data[i] + other.data[i];
	return result;
}

Mat4 Mat4::operator-(const Mat4& other) const
{
	Mat4 result;
	for (int i = 0; i < 16; i++)
		result.data[i] = data[i] - other.data[i];
	return result;
}

Mat4 Mat4::operator*(const Mat4& other) const
{
	Mat4 result;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			float sum = 0.0f;
			for (int k = 0; k < 4; k++)
				sum += At(row, k) * other.At(k, col);

			result.At(row, col) = sum;
		}
		
	}
	return result;
}

Vec4 Mat4::operator*(const Vec4& other) const
{

	return Vec4(At(0,0) * other.x + At(0,1) * other.y + At(0,2) * other.z + At(0,3) * other.w,
		At(1, 0) * other.x + At(1, 1) * other.y + At(1, 2) * other.z + At(1, 3) * other.w,
		At(2, 0) * other.x + At(2, 1) * other.y + At(2, 2) * other.z + At(2, 3) * other.w,
		At(3, 0) * other.x + At(3, 1) * other.y + At(3, 2) * other.z + At(3, 3) * other.w
	);
}

Mat4 Mat4::operator*(float scalar) const
{
	Mat4 result;
	for (int i = 0; i < 16; i++)
		result.data[i] = data[i] * scalar;
	return result;
}

float Mat4::Determinant() const
{
	// 2x2 sub-determinants from rows 2 and 3 (indices 8..15)
	float s0 = data[8] * data[13] - data[9] * data[12];
	float s1 = data[8] * data[14] - data[10] * data[12];
	float s2 = data[8] * data[15] - data[11] * data[12];
	float s3 = data[9] * data[14] - data[10] * data[13];
	float s4 = data[9] * data[15] - data[11] * data[13];
	float s5 = data[10] * data[15] - data[11] * data[14];

	// Cofactors of row 0
	float c0 = (data[5] * s5 - data[6] * s4 + data[7] * s3);
	float c1 = -(data[4] * s5 - data[6] * s2 + data[7] * s1);
	float c2 = (data[4] * s4 - data[5] * s2 + data[7] * s0);
	float c3 = -(data[4] * s3 - data[5] * s1 + data[6] * s0);

	return data[0] * c0 + data[1] * c1 + data[2] * c2 + data[3] * c3;
}

Mat4 Mat4::Transpose() const
{
	Mat4 result;
	result.data[0] = data[0];
	result.data[1] = data[4];
	result.data[2] = data[8];
	result.data[3] = data[12];
	result.data[4] = data[1];
	result.data[5] = data[5];
	result.data[6] = data[9];
	result.data[7] = data[13];
	result.data[8] = data[2];
	result.data[9] = data[6];
	result.data[10] = data[10];
	result.data[11] = data[14];
	result.data[12] = data[3];
	result.data[13] = data[7];
	result.data[14] = data[11];
	result.data[15] = data[15];
	return result;
}

bool Mat4::Inverse(Mat4& result) const
{

	// 2x2 sub-determinants for the top two rows (rows 0 and 1)
	float s0 = data[0] * data[5] - data[4] * data[1];
	float s1 = data[0] * data[6] - data[4] * data[2];
	float s2 = data[0] * data[7] - data[4] * data[3];
	float s3 = data[1] * data[6] - data[5] * data[2];
	float s4 = data[1] * data[7] - data[5] * data[3];
	float s5 = data[2] * data[7] - data[6] * data[3];

	// 2x2 sub-determinants for the bottom two rows (rows 2 and 3)
	float c5 = data[10] * data[15] - data[14] * data[11];
	float c4 = data[9] * data[15] - data[13] * data[11];
	float c3 = data[9] * data[14] - data[13] * data[10];
	float c2 = data[8] * data[15] - data[12] * data[11];
	float c1 = data[8] * data[14] - data[12] * data[10];
	float c0 = data[8] * data[13] - data[12] * data[9];

	// Determinant using the precomputed 2x2 sub-determinants
	float det = s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;

	// Check for singularity with a small epsilon
	if (std::abs(det) < 1e-8f) {
		return false;
	}

	float invDet = 1.0f / det;

	// Compute the transposed cofactor (adjugate) matrix multiplied by 1/det
	result.data[0] = (data[5] * c5 - data[6] * c4 + data[7] * c3) * invDet;
	result.data[1] = (-data[1] * c5 + data[2] * c4 - data[3] * c3) * invDet;
	result.data[2] = (data[13] * s5 - data[14] * s4 + data[15] * s3) * invDet;
	result.data[3] = (-data[9] * s5 + data[10] * s4 - data[11] * s3) * invDet;

	result.data[4] = (-data[4] * c5 + data[6] * c2 - data[7] * c1) * invDet;
	result.data[5] = (data[0] * c5 - data[2] * c2 + data[3] * c1) * invDet;
	result.data[6] = (-data[12] * s5 + data[14] * s2 - data[15] * s1) * invDet;
	result.data[7] = (data[8] * s5 - data[10] * s2 + data[11] * s1) * invDet;

	result.data[8] = (data[4] * c4 - data[5] * c2 + data[7] * c0) * invDet;
	result.data[9] = (-data[0] * c4 + data[1] * c2 - data[3] * c0) * invDet;
	result.data[10] = (data[12] * s4 - data[13] * s2 + data[15] * s0) * invDet;
	result.data[11] = (-data[8] * s4 + data[9] * s2 - data[11] * s0) * invDet;

	result.data[12] = (-data[4] * c3 + data[5] * c1 - data[6] * c0) * invDet;
	result.data[13] = (data[0] * c3 - data[1] * c1 + data[2] * c0) * invDet;
	result.data[14] = (-data[12] * s3 + data[13] * s1 - data[14] * s0) * invDet;
	result.data[15] = (data[8] * s3 - data[9] * s1 + data[10] * s0) * invDet;

	return true;
}

Mat4 Mat4::Scale(float scale)
{
	Mat4 result = Mat4();
	result.At(0, 0) = scale;
	result.At(1, 1) = scale;
	result.At(2, 2) = scale;
	return result;
}

Mat4 Mat4::Scale(const Vec3& scale)
{
	Mat4 result = Mat4();
	result.At(0, 0) = scale.x;
	result.At(1, 1) = scale.y;
	result.At(2, 2) = scale.z;
	return result;
}

Mat4 Mat4::Translation(const Vec3& position)
{
	Mat4 result = Mat4();
	result.At(0, 3) = position.x;
	result.At(1, 3) = position.y;
	result.At(2, 3) = position.z;
	return result;
}

Mat4 Mat4::RotateX(float angle)
{
	Mat4 result = Mat4();
	result.At(1, 1) = std::cos(angle);
	result.At(1, 2) = -std::sin(angle);
	result.At(2, 1) = std::sin(angle);
	result.At(2, 2) = std::cos(angle);
	return result;
}

Mat4 Mat4::RotateY(float angle)
{
	Mat4 result = Mat4();
	result.At(0, 0) = std::cos(angle);
	result.At(0, 2) = std::sin(angle);
	result.At(2, 0) = -std::sin(angle);
	result.At(2, 2) = std::cos(angle);
	return result;
}

Mat4 Mat4::RotateZ(float angle)
{
	Mat4 result = Mat4();
	result.At(0, 0) = std::cos(angle);
	result.At(0, 1) = -std::sin(angle);
	result.At(1, 0) = std::sin(angle);
	result.At(1, 1) = std::cos(angle);
	return result;
}


void Mat4::Print() const
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			std::cout << std::setw(10) << At(row, col) << " ";
		}

		std::cout << '\n';
	}
}
