#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(const glm::vec3& direction, const glm::vec3& color,
    const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular):
    Light(color, ambient, diffuse, specular), _direction(direction) { }