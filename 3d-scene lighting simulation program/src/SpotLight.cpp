#include "SpotLight.h"

using namespace std;

SpotLight::SpotLight(glm::vec3 position, glm::vec3 color, glm::vec3 direction,
    glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, 
    float constant, float linear, float quadratic,
    float cutOff, float outerCutOff):
    Light(color, ambient, diffuse, specular), _position(position), _direction(direction)
{     
    _constant = constant <= 0 ? 1.0 : constant;
    _linear = linear <= 0 ? 1.0 : linear;
    _quadratic = quadratic <= 0 ? 1.0 : quadratic;
    setCutOff(cutOff);
    setOuterCutOff(outerCutOff);
}

void SpotLight::setCutOff(float cutOff)
{
    if (cutOff < 0)
        _cutOff = 0;
    else if (cutOff > 90)
        _cutOff = 90;
    else
        _cutOff = cutOff;
}

void SpotLight::setOuterCutOff(float outerCutOff)
{
    if (outerCutOff < 0)
        _outerCutOff = 0;
    else if (outerCutOff > 90)
        _outerCutOff = 90;
    else
        _outerCutOff = outerCutOff;
}