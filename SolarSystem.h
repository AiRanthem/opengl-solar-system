//
// Created by AiRanthem on 2022/1/13.
//

#ifndef OPENGL_SOLAR_SYSTEM_SOLARSYSTEM_H
#define OPENGL_SOLAR_SYSTEM_SOLARSYSTEM_H


#include "vector"
#include "Star.h"

class SolarSystem {
private:
    std::vector<Star*> stars;
public:
    void addStar(Star* star);
    void displayFunc();
    void onTimeFunc();
    ~SolarSystem() {
        for (const auto &star: stars) {
            delete star;
        }
    }
};


#endif //OPENGL_SOLAR_SYSTEM_SOLARSYSTEM_H
