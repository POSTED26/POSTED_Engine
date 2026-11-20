#pragma once

#include "../Math/Vec3.h"
#include "../Math/Mat4.h"

#include <cmath>

class Camera
{
private:
	Vec3 position;
	Vec3 front;
	Vec3 right;
	Vec3 up;

	float fov;
	float aspectRatio;
	float nearPlane;
	float farPlane;

	float yaw;
public:
	Camera(float fov, float aspectRatio, float nearPlane, float farPlane);

	void MoveForward(float amount);
	void MoveRight(float amount);
	void MoveUp(float amount);
	void TurnRight(float amount);

	Mat4 GetViewMatrix() const;
	Mat4 GetProjectionMatrix() const;
};