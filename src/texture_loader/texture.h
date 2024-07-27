#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

class Texture2D
{
public:
    unsigned int ID;
    unsigned int Width, Height;
    unsigned int Internal_Format; //format of texture
    unsigned int Image_Format; //format of img

    unsigned int Wrap_S; //wrapping on S axis
    unsigned int Wrap_T; //wrapping on S axis
    unsigned int Filter_Min;
    unsigned int Filter_Max;

    Texture2D();
    void Generate(unsigned int width, unsigned int height, unsigned char *data);
    void Bind() const;
};


#endif