//
// Created by AiRanthem on 2022/1/13.
//

#include "SolarSystem.h"

void SolarSystem::addStar(Star* star) {
    stars.push_back(star);
}

void SolarSystem::draw() {
    for (const auto &star: stars) {
        star->draw();
    }
}
