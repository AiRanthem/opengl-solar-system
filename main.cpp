#include <GL/glut.h>
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
    gluLookAt(0, 0, 1000, 0, 0, 0, 0, 1, 0);
    // lights
    GLfloat light_position[] = { 1.0f, 1.0f, -1.0f, 0.0f };	// 光源位置
    GLfloat light_ambient[] = { 0.35f, 0.35f, 0.35f, 0.2f };	// 环境强度
    GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 0.2f };	// 散射强度
    GLfloat light_specular[] = { 0.4f, 0.4f, 0.4f, 0.2f };	// 镜面强度
    //设置第一个光源的参数
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_COLOR_MATERIAL);	// 使用颜色材质
    glEnable(GL_LIGHTING);	 // 使用灯光
    glEnable(GL_LIGHT0);	// 使用默认的0号灯
    glEnable(GL_AUTO_NORMAL);	//图形能把光反射到各个方向
    glEnable(GL_NORMALIZE);	//根据函数glNormal的设置条件，启用法向量
    glEnable(GL_DEPTH_TEST);	//开启深度测试
    glDepthFunc(GL_LESS);	//如果输入的深度值小于参考值，则通过

    //others
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

float earthAngle=0, moonAngle=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -500, 1000, 0, 0, 0, 0, 1, 0);
    // SUN: Red ball
    glColor3f(1, 0, 0);
    glutSolidSphere(500, 40, 20);
    // Earth: Blue ball
    glRotatef(earthAngle, 0, 1, 0);
    glTranslatef(2500, 0, 0);
    glColor3f(0, 0, 1);
    glutSolidSphere(300, 40, 20);
    // Moon: Yellow ball
    glRotatef(moonAngle, 0, 1, 0);
    glTranslatef(1000, 0, 0);
    glColor3f(1, 1, 0);
    glutSolidSphere(200, 40, 20);

    glutSwapBuffers();
    glFlush();
}

void onTime(int value)
{
    if (earthAngle > 360)
        earthAngle -= 360;
    if (moonAngle > 360)
        moonAngle -= 360;
    earthAngle += 0.1;
    moonAngle += 3;
    glutPostRedisplay();
    glutTimerFunc(16, onTime, 1);
}

void reshape(int width,int height)
{
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, onTime, 1);
    glutMainLoop();
}