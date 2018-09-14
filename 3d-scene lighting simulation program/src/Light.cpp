#include "Light.h"

Light::Light(const glm::vec3& color, const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3 specular) :
    _color(color), _ambient(ambient), _diffuse(diffuse), _specular(specular) { }