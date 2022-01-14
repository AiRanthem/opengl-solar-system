//
// Created by AiRanthem on 2022/1/13.
//

#ifndef OPENGL_SOLAR_SYSTEM_STAR_H
#define OPENGL_SOLAR_SYSTEM_STAR_H


#include <GL/gl.h>
#include <GL/glu.h>
#include "glm/glm.hpp"
#include "vector"

class Star {
public:
    float angularVelocityAxis; // 自转角速度
    float angularVelocitySun; // 公转角速度
    float radius; // 球体半径
    GLuint texture; // 贴图
    float distance; // 太阳距离
    bool emission; // 是否发光
    GLUquadricObj *e_tex;

    float rSun = 0.0f; // 公转累计角度
    float rAxis = 0.0f; // 自转累计角度
    std::vector<Star *> children; // 子星
    Star *father = nullptr; // 母星

    void material() const;

public:
    Star(float angularVelocityAxis, float angularVelocitySun, float radius, GLuint texture, float distance,
         GLUquadricObj *e_tex, bool emission = false) {
        this->angularVelocityAxis = angularVelocityAxis;
        this->angularVelocitySun = angularVelocitySun;
        this->radius = radius;
        this->texture = texture;
        this->distance = distance;
        this->e_tex = e_tex;
        this->emission = emission;
    }

    void draw();

    void addChild(Star *child);

    void setFather(Star *f);

    Star* getFather();

    glm::vec3 getPosition();

    void move();

    ~Star()
    = default;
};


#endif //OPENGL_SOLAR_SYSTEM_STAR_H
