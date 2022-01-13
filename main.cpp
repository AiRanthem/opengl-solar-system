#include "Star.h"
#include "SolarSystem.h"
#include "TextureManager.h"
#include "Camera.h"
#include <GL/glut.h>

GLUquadricObj* e_tex = gluNewQuadric();
TextureManager textureManager = TextureManager();
SolarSystem solarSystem = SolarSystem();
Camera camera = Camera();

float earthAngle=0, moonAngle=0;

void init()
{
    // display
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // window
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Extreme Solar System");
    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4000, 4000, -3000, 3000, 10000, -10000);
    glMatrixMode(GL_MODELVIEW);
    // 环境光
    GLfloat environment_ambient[] = {0.0,0.0,0.0,0.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, environment_ambient);
    // 全局点光源
    GLfloat global_light_position[] = {1.0f, 0.0f, 0.0f, 1.0f };	// 光源位置
    GLfloat global_light_ambient[] = {0.0f, 0.0, 0.0, 0.2f };	// 环境强度
    GLfloat global_light_diffuse[] = {0.5f, 0.5f, 0.5f, 0.1f };	// 散射强度
    GLfloat global_light_specular[] = {0.9f, 0.9f, 0.9f, 0.9f };	// 镜面强度
    glLightfv(GL_LIGHT1, GL_POSITION, global_light_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, global_light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, global_light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, global_light_specular);

    glEnable(GL_COLOR_MATERIAL);	// 使用颜色材质
    glEnable(GL_LIGHTING);	 // 使用灯光
    glEnable(GL_LIGHT0);	// 使用默认的0号灯
    glEnable(GL_LIGHT1);
    glEnable(GL_AUTO_NORMAL);	//图形能把光反射到各个方向
    glEnable(GL_NORMALIZE);	//根据函数glNormal的设置条件，启用法向量
    glEnable(GL_DEPTH_TEST);	//开启深度测试
    glDepthFunc(GL_LESS);	//如果输入的深度值小于参考值，则通过

    // texture
    textureManager.addTexture("/home/airan/workspace/opengl-solar-system/assets/sun.jpg");
    textureManager.addTexture("/home/airan/workspace/opengl-solar-system/assets/earth.jpg");
    textureManager.addTexture("/home/airan/workspace/opengl-solar-system/assets/moon.jpg");
    textureManager.init();
    // stars
    Star* sun = new Star(0.5, 0, 500, textureManager.getTexture(0), 0, e_tex, true);
    Star* earth = new Star(3, 0.5, 300, textureManager.getTexture(1), 2500, e_tex);
    Star* moon = new Star(4, 4, 100, textureManager.getTexture(2), 1000, e_tex);
    earth->addChild(moon);
    sun->addChild(earth);
    solarSystem.addStar(sun);
    //others
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -500, 1000, 0, 0, 0, 0, 1, 0);
    solarSystem.draw();
    glutSwapBuffers();
    glFlush();
}

void reshape(int width,int height)
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}