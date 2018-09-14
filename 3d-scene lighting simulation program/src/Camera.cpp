#include "Camera.h"

Camera::Camera(const glm::vec3& position, const glm::vec3& up, const float yaw, const float pitch) :
    _position(position), _front(glm::vec3(0.0f, 0.0f, -1.0f)), _worldUp(up),
    _yaw(yaw), _pitch(pitch), _movementSpeed(SPEED), _mouseSensitivity(SENSITIVITY), _zoom(ZOOM)
{
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) :
    Camera(glm::vec3(posX, posY, posZ), glm::vec3(upX, upY, upZ), yaw, pitch)
{
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(_position, _position + _front, _up);
}

void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime)
{
    float velocity = _movementSpeed * deltaTime;

    if (direction == CameraMovement::FORWARD)
        _position += _front * velocity;
    if (direction == CameraMovement::BACKWARD)
        _position -= _front * velocity;
    if (direction == CameraMovement::LEFT)
        _position -= _right * velocity;
    if (direction == CameraMovement::RIGHT)
        _position += _right * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= _mouseSensitivity;
    yoffset *= _mouseSensitivity;

    _yaw += xoffset;
    _pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (_pitch > 89.0f)
            _pitch = 89.0f;
        if (_pitch < -89.0f)
            _pitch = -89.0f;
    }

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    if (_zoom >= 1.0f && _zoom <= 45.0f)
        _zoom -= yoffset;
    if (_zoom <= 1.0f)
        _zoom = 1.0f;
    if (_zoom >= 45.0f)
        _zoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    front.y = sin(glm::radians(_pitch));
    front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    _front = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    _right = glm::normalize(glm::cross(front, _worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    _up = glm::normalize(glm::cross(_right, front));
}