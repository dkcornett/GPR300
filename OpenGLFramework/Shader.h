#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include "Transformation.h"
#include "Camera.h"

class Shader
{
    public:
        Shader(const std::string& shaderFileName);
        virtual ~Shader();

        void Bind();
        void UpdateShader(const Transformation& transformation
                        , const Camera& camera);

    private:

    Shader(const Shader& other) {};
    void operator=(const Shader& other) {};

    std::string LoadShader(const std::string& FileName);
    GLuint CreateShader(const std::string& txt, GLenum type);

    //Error Handlers
    void checkForProgramError(GLuint program, GLuint flag, const std::string& errorMsg);
    void checkForShaderError(GLuint shader, GLuint flag, const std::string& errorMsg);

    enum uniformEnum
    {
        TRANSFROM_UNIFORM,
        UNIFORM_NUM
    };

    static const unsigned NUM_SHADERS = 2; //vertex, frag., geometry shaders
    GLuint mProgram; //for GL Keeping track of the shader program
    GLuint mShaders[NUM_SHADERS];
    GLuint mUniforms[UNIFORM_NUM];
};

#endif // SHADER_H
