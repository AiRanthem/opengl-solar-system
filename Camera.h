//
// Created by AiRanthem on 2022/1/13.
//

#ifndef OPENGL_SOLAR_SYSTEM_CAMERA_H
#define OPENGL_SOLAR_SYSTEM_CAMERA_H

#include "glm/glm.hpp"
#include "Star.h"

enum Direction {
    UP, DOWN, LEFT, RIGHT, FORWARD, BACKWARD
};

class Camera {
private:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 speed{};
    glm::vec2 mouseAnchor{}, mouseMotion{};
    float velocity = 10.0;
    float width, height;
    GLfloat yaw{}, pitch{};

    bool earthView = false;
    Star *earthAnchor = nullptr;

public:
    Camera(float w, float h) : width(w), height(h) {};

    Star *getEarthAnchor();

    void setEarthAnchor(Star *ea);

    void displayFunc();

    void onTimeFunc();

    void godsEye();

    void humanEye();

    void startMoving(Direction direction);

    void stopMoving(Direction direction);

    void lookAt(glm::vec3 target);

    void goTo(glm::vec3 target);

    void setAnchor(glm::vec2 anchor);

    void setMotion(glm::vec2 motion);

    void init() const;

    void switchView();
};


#endif //OPENGL_SOLAR_SYSTEM_CAMERA_H
