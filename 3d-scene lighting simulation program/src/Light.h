#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light
{   
public:

    Light() = default;

    Light(const glm::vec3& color, const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3 specular);

    void setColor(const glm::vec3& color) { _color = color; }

    void setAmbient(const glm::vec3& ambient) { _ambient = ambient; }

    void setDiffuse(const glm::vec3& diffuse) { _diffuse = diffuse; }

    void setSpecular(const glm::vec3& specular) { _specular = specular; }

    const glm::vec3& getColor() { return _color; }

    const glm::vec3& getAmbient() { return _ambient; }

    const glm::vec3& getDiffuse() { return _diffuse; }

    const glm::vec3& getSpecular() { return _specular; }

private:
    glm::vec3 _color;
    glm::vec3 _ambient;
    glm::vec3 _diffuse;
    glm::vec3 _specular;
};


#endif