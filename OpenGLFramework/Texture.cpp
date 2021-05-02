#include "Texture.h"

Texture::Texture(const std::string filename)
{
    int imageW;         //unsigned imageW;
    int imageH;         //unsigned imageH;
    int numImageComp;   //unsigned numImageComp;
    unsigned char* imageData = stbi_load(filename.c_str(), &imageW, &imageH
                                , &numImageComp, 4); //begin

    if (imageData)
    {
        std::cerr << "Error: Texture " << filename << " failed to load!\n";
    }



    //Generate and bind new texture
    glGenTextures(1, &mTexture);
    glBindTexture(GL_TEXTURE_2D, mTexture);

    //Controls Texture Wrapping
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //Control interpolating and extrapolating the texture
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    //Create Texture image
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageW, imageH, 0
                , GL_RGBA, GL_UNSIGNED_BYTE, imageData);
    stbi_image_free(imageData); //end
}

Texture::~Texture()
{
    glDeleteTextures(1, &mTexture);
}

void Texture::BindTexture(int texUnit)
{
    //Range is 0 to 31, make sure we aren't outside
    assert(texUnit >= 0 && texUnit <= 31);
    glActiveTexture(GL_TEXTURE0 + texUnit);
    glBindTexture(GL_TEXTURE_2D, mTexture);
}
