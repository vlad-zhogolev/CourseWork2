#include "PointLight.h"

PointLight::PointLight(glm::vec3 position, glm::vec3 color,
    glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
    float constant, float linear, float quadratic):
    Light(color, ambient, diffuse, specular), _position(position)
{      
    _constant = constant <= 0 ? 1.0 : constant;
    _linear = linear <= 0 ? 1.0 : linear;
    _quadratic = quadratic <= 0 ? 1.0 : quadratic;
}