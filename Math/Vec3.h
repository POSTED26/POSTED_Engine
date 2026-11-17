#pragma once



struct Vec3
{
	float x;
	float y;
	float z;

	Vec3();
	Vec3(float x, float y, float z);

	Vec3 operator+(const Vec3& other) const;
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator*(float scalar) const;

	float Length() const;
	float LengthSquared() const;
	Vec3 Normalize() const;

	Vec3 Cross(const Vec3& other) const;
	float Dot(const Vec3& other) const;
};