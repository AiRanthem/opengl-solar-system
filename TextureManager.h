//
// Created by AiRanthem on 2022/1/13.
//

#ifndef OPENGL_SOLAR_SYSTEM_TEXTUREMANAGER_H
#define OPENGL_SOLAR_SYSTEM_TEXTUREMANAGER_H

#include <GL/gl.h>
#include "vector"

typedef struct texture_data {
    unsigned char *data;
    int width, height;
} TextureData;

class TextureManager {
private:
    std::vector<const char*> files;
    GLuint allTextures[99];
    std::vector<TextureData> textureImages;
    static TextureData loadTexture(const char* path);
public:
    int size();
    void addTexture(const char * path);
    GLuint getTexture(int idx);
    void init();
};


#endif //OPENGL_SOLAR_SYSTEM_TEXTUREMANAGER_H
