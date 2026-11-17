#pragma once



struct Vec2
{
	float x;
	float y;

	Vec2();
	Vec2(float x, float y);

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator*(float scalar) const;

	float Length() const;
	float LengthSquared() const;
	Vec2 Normalize() const;
	
};