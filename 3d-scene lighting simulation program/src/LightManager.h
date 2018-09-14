#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H

#include <vector>
#include <memory>
#include "PointLight.h"
#include "SpotLight.h"
#include <GLFW/glfw3.h>

enum class ActiveLightType
{
    NONE,
    POINT,
    SPOT
};

enum class Direction
{
    UP,
    DOWN,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

class LightManager
{   
    using PointLightsSharedPtr = std::shared_ptr<std::vector<PointLight>>;
    using SpotLightsSharedPtr = std::shared_ptr<std::vector<SpotLight>>;    

public:
    LightManager(PointLightsSharedPtr pointLights, SpotLightsSharedPtr spotLights) :
        _pointLights(pointLights), _spotLights(spotLights) {};

    // Processes input for lights
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    void updateDeltaTime(float deltaTime) { _deltaTime = deltaTime >= 0 ? deltaTime : 0; }

private:
    void switchToNext();

    void switchToPrevious();

    // Moves light in the space of the scene
    void translateCurrentLight(Direction dir);

    // Switches active type of the light, if parameter represents currently active type, then active type switched to ActiveLightType.NONE   
    void switchLightType(ActiveLightType type);

private:
    PointLightsSharedPtr _pointLights;
    SpotLightsSharedPtr _spotLights;
    ActiveLightType _activeType = ActiveLightType::NONE;
    int _curPointLight = 0;
    int _curSpotLight = 0;    
    float _deltaTime = 0;

    static float movementSpeed;
    static const glm::vec3 LEFT;
    static const glm::vec3 UP;
    static const glm::vec3 FRONT;
};

#endif // !LIGHT_MANAGER_H
