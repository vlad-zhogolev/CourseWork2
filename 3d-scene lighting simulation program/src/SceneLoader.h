#ifndef SCENE_LOADER_H
#define SCENE_LOADER_H

#include <iostream>
#include <vector>
#include <memory>
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Model.h"
#include "Object.h"
#include <fstream>
#include <sstream>

class SceneLoader
{
    using DirLightsSharedPtr = std::shared_ptr<vector<DirectionalLight>>;
    using PointLightsSharedPtr = std::shared_ptr<std::vector<PointLight>>;
    using SpotLightsSharedPtr = std::shared_ptr<std::vector<SpotLight>>;

public:
    SceneLoader();

    void loadScene(std::string lightsDataPath, std::string modelsDataPath,
        DirLightsSharedPtr dirLights, PointLightsSharedPtr pointLights,
        SpotLightsSharedPtr spotLights, std::vector<Model>& models, vector<Object>& objects);

private:
    static int getModelIndex(std::string path, std::vector<Model>& modles);

    static glm::vec3 getVec3(std::stringstream& data);

    static bool checkRangeVec3(glm::vec3 vector, double left, double right, string message);

    static bool checkAttenuation(double constant, double linear, double quadratic);

    static bool checkAngles(double cutOff, double outerCutOff);

    static bool checkScale(glm::vec3 scale);

    static void exitOnError();

    static void loadLights(const std::string& lightData, DirLightsSharedPtr dirLights,
        PointLightsSharedPtr pointLights, SpotLightsSharedPtr spotLights);

    static DirectionalLight loadDirectionalLight(std::stringstream& lightData, bool& good);

    static PointLight loadPointLight(std::stringstream& lightData, bool& good);

    static SpotLight loadSpotLight(std::stringstream& lightData, bool& good);

    static void loadModels(const std::string& modelsDataPath, std::vector<Model>& models,
        std::vector<Object>& objects);
};

#endif

