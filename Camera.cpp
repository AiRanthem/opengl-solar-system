//
// Created by AiRanthem on 2022/1/13.
//

#include "iostream"
#include <cmath>
#include <GL/glu.h>
#include "Camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

void Camera::displayFunc() {
    glm::vec3 target = cameraPos + cameraFront;
    gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z,
              target.x, target.y, target.z,
              cameraUp.x, cameraUp.y, cameraUp.z);
}

void Camera::godsEye() {
    earthView = false;
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    goTo(glm::vec3(-7000, 480.0f, 200.0f));
    lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
}

glm::mat4 Camera::view() {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}


void Camera::lookAt(glm::vec3 target) {
    cameraFront = glm::normalize(target - cameraPos);
    cameraRight = glm::normalize(glm::cross(cameraUp, cameraFront));
    cameraUp = glm::normalize(glm::cross(cameraFront, cameraRight));
}


void Camera::goTo(glm::vec3 target) {
    cameraPos = target;
}

void Camera::startMoving(Direction direction) {
    switch (direction) {
        case RIGHT:
            speed += velocity * cameraRight;
            break;
        case LEFT:
            speed -= velocity * cameraRight;
            break;
        case UP:
            speed -= velocity * cameraUp;
            break;
        case DOWN:
            speed += velocity * cameraUp;
            break;
        case FORWARD:
            speed += velocity * cameraFront;
            break;
        case BACKWARD:
            speed -= velocity * cameraFront;
            break;
    }
}

void Camera::stopMoving(Direction direction) {
    switch (direction) {
        case RIGHT:
            speed -= velocity * cameraRight;
            break;
        case LEFT:
            speed += velocity * cameraRight;
            break;
        case UP:
            speed += velocity * cameraUp;
            break;
        case DOWN:
            speed -= velocity * cameraUp;
            break;
        case FORWARD:
            speed -= velocity * cameraFront;
            break;
        case BACKWARD:
            speed += velocity * cameraFront;
            break;
    }
}

void Camera::onTimeFunc() {
    // move
    cameraPos += speed * (1 + 1 / cameraZoom);
    // zoom
    if (zoomStatus > 0) {
        cameraZoom -= 0.05;
    } else if (zoomStatus < 0) {
        cameraZoom += 0.05;
    }
    if (cameraZoom > 2) {
        cameraZoom = 2;
    }
    if (cameraZoom < 0.5) {
        cameraZoom = 0.5;
    }
    // rotate
    GLfloat xoffset = mouseMotion.x - mouseAnchor.x;
    GLfloat yoffset = mouseMotion.y - mouseAnchor.y;
    mouseAnchor = mouseMotion;
    GLfloat sensitivity = 0.05;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    if (earthView) {
        Star *ea = getEarthAnchor();
        Star *earth = ea->getFather();
        glm::vec3 eap = ea->getPosition();
        glm::vec3 ep = earth->getPosition();
        goTo(eap);
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        lookAt(eap + eap - ep);
    } else {
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        cameraFront = glm::normalize(front);
        lookAt(cameraPos + cameraFront);
    }
}

void Camera::stopZoom() {
    zoomStatus = 0;
}

void Camera::startZoom(bool in) {
    if (in) {
        zoomStatus = 1;
    } else {
        zoomStatus = -1;
    }
}

void Camera::setAnchor(glm::vec2 anchor) {
    mouseAnchor = anchor;
}

void Camera::setMotion(glm::vec2 motion) {
    mouseMotion = motion;
}


Star *Camera::getEarthAnchor() {
    return earthAnchor;
}

void Camera::setEarthAnchor(Star *ea) {
    this->earthAnchor = ea;
}

void Camera::info() const {
    std::cout << "Position:" << std::endl;
    std::cout << cameraPos.x << ' ' << cameraPos.y << ' ' << cameraPos.z << std::endl;
    std::cout << "Front:" << std::endl;
    std::cout << cameraFront.x << ' ' << cameraFront.y << ' ' << cameraFront.z << std::endl;
    std::cout << "Up:" << std::endl;
    std::cout << cameraUp.x << ' ' << cameraUp.y << ' ' << cameraUp.z << std::endl;
    std::cout << "Right:" << std::endl;
    std::cout << cameraRight.x << ' ' << cameraRight.y << ' ' << cameraRight.z << std::endl;
    std::cout << "Speed:" << std::endl;
    std::cout << speed.x << ' ' << speed.y << ' ' << speed.z << std::endl;
    std::cout << "Zoom: " << cameraZoom << std::endl;
    std::cout << "########################################" << std::endl << std::endl;
}

void Camera::init() const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, float(width) / float(height), 1, 50000);
    glMatrixMode(GL_MODELVIEW);
}

void Camera::humanEye() {
    earthView = true;
}

void Camera::switchView() {
    if (earthView) {
        godsEye();
    } else {
        humanEye();
    }
}
