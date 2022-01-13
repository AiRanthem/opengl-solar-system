//
// Created by AiRanthem on 2022/1/13.
//

#include <GL/glu.h>
#include "Camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

void Camera::look() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4000, 4000, -3000, 3000, 10000, -10000);
    glMultMatrixf(glm::value_ptr(view));
    glMatrixMode(GL_MODELVIEW);
}

void Camera::godsEye() {
    this->view = glm::lookAt(
            glm::vec3(0.0f, -500.0f, 1000.0f),
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f)
    );
}
