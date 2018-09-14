#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "Light.h"

class SpotLight : public Light
{
public:
    SpotLight(glm::vec3 position, glm::vec3 color, glm::vec3 direction,
        glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, 
        float constant, float linear, float quadratic, 
        float cutOff, float outerCutOff);   

    glm::vec3 getPosition() { return _position; }    

    void setPosition(const glm::vec3& pos) { _position = pos; }

    glm::vec3 getDirection() { return _direction; }

    float getConstant() { return _constant; }

    float getLinear() { return _linear; }

    float getQuadratic() { return _quadratic; }

    void setConstant(float constant) { this->_constant = (constant > 0) ? constant : 1.0; }

    void setLinear(float linear) { this->_linear = (linear >= 0) ? linear : 1.0; }

    void setQuadratic(float quadratic) { this->_quadratic = (quadratic >= 0) ? quadratic : 1.0; }
    
    float getCutOff() { return _cutOff; }

    float getOuterCutOff() { return _outerCutOff; }

    void setCutOff(float cutOff);

    void setOuterCutOff(float cutOff);

private:
    glm::vec3 _direction;
    glm::vec3 _position;
    float _constant;
    float _linear;
    float _quadratic;
    float _cutOff;     //stores angle (need to pass cos(cutOff) to shader)
    float _outerCutOff;// same as cutOff
};

#endif