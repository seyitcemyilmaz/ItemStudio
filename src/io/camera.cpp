#include "camera.h"

#include "windowmanager.h"

Camera* Camera::activeCamera = nullptr;

Camera::Camera(glm::vec3 position)
	: position(position),
	worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	yaw(0.0f),
	pitch(0.0f),
	speed(2.5f),
	sensitivity(1.0f),
	zoom(45.0f),
	front(glm::vec3(1.0f, 0.0f, 0.0f))
{
	updateCameraVectors();
}

void Camera::updateCameraDirection(double dx, double dy) {
	yaw += (float) dx;
	pitch += (float) dy;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	updateCameraVectors();
}

void Camera::updateCameraPosition(CameraDirection direction, double dt) {
	float velocity = (float)dt * speed;

	switch (direction) {
	case CameraDirection::FORWARD:
		position += front * velocity;
		break;
	case CameraDirection::BACKWARD:
		position -= front * velocity;
		break;
	case CameraDirection::RIGHT:
		position += right * velocity;
		break;
	case CameraDirection::LEFT:
		position -= right * velocity;
		break;
	case CameraDirection::UP:
		position += up * velocity;
		break;
	case CameraDirection::DOWN:
		position -= up * velocity;
		break;
	}
}

void Camera::updateCameraZoom(double dy) {
	if (zoom >= 1.0f && zoom <= 45.0f) {
		zoom -= (float) dy;
	}
	else if (zoom < 1.0f) {
		zoom = 1.0f;
	}
	else { // > 45.0f
		zoom = 45.0f;
	}
}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::perspective(glm::radians(Camera::activeCamera->getZoom()),
							(float) WindowManager::getActiveWindow()->getWindowWidth() / WindowManager::getActiveWindow()->getWindowHeight(),
							0.1f, 100.0f);
}

float Camera::getZoom() {
	return zoom;
}

void Camera::updateCameraVectors() {
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(direction);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}