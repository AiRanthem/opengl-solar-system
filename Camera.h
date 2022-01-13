//
// Created by AiRanthem on 2022/1/13.
//

#ifndef OPENGL_SOLAR_SYSTEM_CAMERA_H
#define OPENGL_SOLAR_SYSTEM_CAMERA_H

struct Anchor {
    double x, y, z;
};

class Camera {
private:
    double eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ;
public:
    // 移动相机坐标
    void setPosition(double x, double y, double z);

    // 控制视线方向
    void setCenter(double x, double y, double z);

    // 控制头顶
    void setUp(double x, double y, double z);

    void look();

    void godsEye();

    Camera() { godsEye(); }
};


#endif //OPENGL_SOLAR_SYSTEM_CAMERA_H
