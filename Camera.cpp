//
// Created by AiRanthem on 2022/1/13.
//

#include <GL/glu.h>
#include "Camera.h"

void Camera::setPosition(double x, double y, double z) {
    eyeX = x;
    eyeY = y;
    eyeZ = z;
}

void Camera::setCenter(double x, double y, double z) {
    centerX = x;
    centerY = y;
    centerZ = z;
}

void Camera::setUp(double x, double y, double z) {
    upX = x;
    upY = y;
    upZ = z;
}

void Camera::look() {
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
}

void Camera::godsEye() {
    upY = 1;
    eyeY = -500;
    eyeZ = 1000;
    centerX = centerY = centerZ = upX = upZ = eyeX = 0;
}
