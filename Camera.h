//
// Created by AiRanthem on 2022/1/13.
//

#ifndef OPENGL_SOLAR_SYSTEM_CAMERA_H
#define OPENGL_SOLAR_SYSTEM_CAMERA_H

#include "glm/glm.hpp"

class Camera {
private:
    glm::vec3 cameraPos = glm::vec3(0.0f, -500.0f, 1000.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
    glm::mat4 view = glm::mat4();
public:
    void look();
    void godsEye();
};


#endif //OPENGL_SOLAR_SYSTEM_CAMERA_H
