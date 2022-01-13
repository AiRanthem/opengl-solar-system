//
// Created by AiRanthem on 2022/1/13.
//

#include <GL/glew.h>
#include "Star.h"

void Star::draw() {
    glPushMatrix();
    glEnable(GL_LIGHTING);

    glRotatef(this->rSun, 0.0f, 1.0f, 0.0f);
    glTranslatef(this->distance, 0.0f, 0.0f);

    for (const auto &child: children) {
        child->draw();
    }
    material();

    glRotatef(57, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rAxis, 0.0f, 0.0f, 1.0f);

    gluQuadricTexture(e_tex, GLU_TRUE);
    glPushAttrib(GL_ENABLE_BIT | GL_TEXTURE_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->texture);

    gluSphere(e_tex, this->radius, 15.0f, 15.0f);
    glPopAttrib();
    gluQuadricTexture(e_tex, GLU_FALSE);

    this->rSun += this->angularVelocitySun;
    this->rAxis += this->angularVelocityAxis;
    while (this->rSun >= 360.0f) {
        this->rSun -= 360;
    }
    while (this->rAxis >= 360.0f) {
        this->rAxis -= 360;
    }
    glPopMatrix();
}

void Star::setTexture(GLuint tex) {
    this->texture = tex;
}

void Star::material() const {
    if (emission) {
        GLfloat sun_mat_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};  //定义材质的环境光颜色
        GLfloat sun_mat_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};  //定义材质的漫反射光颜色
        GLfloat sun_mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};   //定义材质的镜面反射光颜色
        GLfloat sun_mat_emission[] = {1.0f, 1.0f, 1.0f, 0.0f};   //定义材质的辐射光颜色
        GLfloat sun_mat_shininess = 100.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);
    } else {
        GLfloat earth_mat_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};  //定义材质的环境光颜色
        GLfloat earth_mat_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};  //定义材质的漫反射光颜色
        GLfloat earth_mat_specular[] = {0.8f, 0.8f, 0.8f, 0.2f};   //定义材质的镜面反射光颜色
        GLfloat earth_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};   //定义材质的辐射光颜色
        GLfloat earth_mat_shininess = 5.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
    }
}

void Star::addChild(Star *child) {
    children.push_back(child);
}
