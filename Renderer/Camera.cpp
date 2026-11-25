#include "Camera.h"
#include "../engine/Log.h"

/*
TODO:

Use mouse input for camera rotaions

*/

Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane) 
	: fov(fov), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane)
{
	position = Vec3(0.0f, 0.0f, -3.0f); // default start
	front = Vec3(0.0f, 0.0f, 1.0f);
	right = Vec3(1.0f, 0.0f, 0.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);
	yaw = 3.14159f / 2.0f;
}

void Camera::MoveForward(float amount)
{
	//Log::Info("Moving forward: " + std::to_string(amount));
	position = position + front * amount;
}

void Camera::MoveRight(float amount)
{
	position = position + right * amount;
}

void Camera::MoveUp(float amount)
{
	position = position + up * amount;
}

void Camera::TurnRight(float amount)
{
	yaw += amount * (3.14159f / 180.0f);
	front.x = std::cos(yaw);
	front.z = std::sin(yaw);
	front.Normalize();
	right = up.Cross(front).Normalize();
	//Log::Info("Yaw: " + std::to_string(yaw));
	//Log::Info("Front: " + std::to_string(front.x) + ", " + std::to_string(front.y) + ", " + std::to_string(front.z));
}

Mat4 Camera::GetViewMatrix() const
{
	Vec3 target = position + front;
	return Mat4::LookAt(position, target, up);
}

Mat4 Camera::GetProjectionMatrix() const
{
	return Mat4::Perspective(fov, aspectRatio, nearPlane, farPlane);
}

Vec3 Camera::GetPosition() const
{
	return position;
}
