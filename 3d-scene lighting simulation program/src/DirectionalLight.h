#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTINOAL_LIGHT_H

#include <iostream>
#include "Light.h"

class DirectionalLight : public Light
{
public:
    DirectionalLight() = default;

    DirectionalLight(const glm::vec3& direction, const glm::vec3& color, 
        const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular);

    void setDirection(const glm::vec3& direction) { _direction = direction; }

    const glm::vec3& getDirection() { return _direction; }

private:
    glm::vec3 _direction;
};

#endif