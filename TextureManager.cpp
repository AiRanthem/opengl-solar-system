//
// Created by AiRanthem on 2022/1/13.
//

#include <SOIL/SOIL.h>
#include "TextureManager.h"

TextureData TextureManager::loadTexture(const char *path) {
    TextureData t;
    int width, height;
    t.data = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
    t.width = width;
    t.height = height;
    return t;
}

void TextureManager::init() {
    for (const auto &file: files) {
        textureImages.push_back(loadTexture(file));
    }
//    textureImages[0] = loadTexture("/home/airan/workspace/opengl-solar-system/assets/sun.jpg");
//    textureImages[1] = loadTexture("/home/airan/workspace/opengl-solar-system/assets/earth.jpg");
//    textureImages[2] = loadTexture("/home/airan/workspace/opengl-solar-system/assets/moon.jpg");
    glGenTextures(size(), &allTextures[0]);
    for (int i = 0; i < size(); i++) {
        glBindTexture(GL_TEXTURE_2D, allTextures[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, textureImages[i].width, textureImages[i].height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                     textureImages[i].data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    }

    for (auto & i : textureImages) {
        SOIL_free_image_data(i.data);
    }
}

int TextureManager::size() {
    return (int) files.size();
}

void TextureManager::addTexture(const char *path) {
    if (size() > 99) {
        return;
    }
    files.push_back(path);
}

GLuint TextureManager::getTexture(int idx) {
    return allTextures[idx];
}
