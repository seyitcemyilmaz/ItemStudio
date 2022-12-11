#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Scene;

enum class CameraDirection {
	NONE = 0,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera {
public:
	static Camera* activeCamera;
	glm::vec3 position;

	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;

	glm::vec3 worldUp;

	float yaw; // x-axis
	float pitch; // y-axis
	float speed;
	float sensitivity;
	float zoom;

	Camera(glm::vec3 position = glm::vec3(0.0f));

	void updateCameraDirection(double dx, double dy); // moving mouse
	void updateCameraPosition(CameraDirection direction, double dt); // keyboard input
	void updateCameraZoom(double dy); // scroll wheel

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

	float getZoom();

private:
	void updateCameraVectors();
};

#endif