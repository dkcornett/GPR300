#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <assert.h>
#include <iostream>
#include "stb_image.h"

class Texture
{
    public:
        Texture(const std::string filename);
        virtual ~Texture();

        void BindTexture(int texUnit);

    private:
        Texture(const Texture& other) {};
        void operator=(const Texture& other) {};

        GLuint mTexture;
};

#endif // TEXTURE_H
