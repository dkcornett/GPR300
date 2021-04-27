#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

class Shader
{
    public:
        Shader(const std::string& shaderFileName);
        virtual ~Shader();

        void Bind();

    private:

    Shader(const Shader& other) {};
    void operator=(const Shader& other) {};

    std::string LoadShader(const std::string& FileName);
    GLuint CreateShader(const std::string& txt, GLenum type);

    //Error Handlers
    void checkForProgramError(GLuint program, GLuint flag, const std::string& errorMsg);
    void checkForShaderError(GLuint shader, GLuint flag, const std::string& errorMsg);

    static const unsigned NUM_SHADERS = 2; //vertex, frag., geometry shaders
    GLuint mProgram; //for GL Keeping track of the shader program
    GLuint mShaders[NUM_SHADERS];
};

#endif // SHADER_H
