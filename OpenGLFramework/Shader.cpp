#include "Shader.h"

Shader::Shader(const std::string& shaderFileName)
{
    //creates new shader program
    mProgram = glCreateProgram();
    mShaders[0] = CreateShader(LoadShader(shaderFileName + ".vs")
                , GL_VERTEX_SHADER); //Vertex Shader
    mShaders[1] = CreateShader(LoadShader(shaderFileName + ".fs")
                , GL_FRAGMENT_SHADER); //Frag. Shader
    //mShaders[2] = CreateShader(LoadShader(shaderFileName + ".gs")
    //            , GL_GEOMETRY_SHADER); //Geometry Shader

    for (unsigned i = 0; i < NUM_SHADERS; ++i)
    {
        glAttachShader(mProgram, mShaders[i]);
    }

    //Shader Attribute
    glBindAttribLocation(mProgram, 0, "pos");
    glBindAttribLocation(mProgram, 1, "texcoord");

    glLinkProgram(mProgram);
    checkForProgramError(mProgram, GL_LINK_STATUS, "Error: Program failed to link!");
    glValidateProgram(mProgram);
    checkForProgramError(mProgram, GL_VALIDATE_STATUS, "Error: Program is invalid!");

    mUniforms[TRANSFROM_UNIFORM] = glGetUniformLocation(mProgram, "Transform");
}

Shader::~Shader()
{
    for (unsigned i = 0; i < NUM_SHADERS; ++i)
    {
        glDetachShader(mProgram, mShaders[i]);
        glDeleteShader(mShaders[i]);
    }

    glDeleteProgram(mProgram);
}

void Shader::Bind()
{
    glUseProgram(mProgram);
}

GLuint Shader::CreateShader(const std::string& txt, GLenum type)
{
    GLuint newShader = glCreateShader(type);

    if (newShader == 0)
    {
        std::cerr << "Error: Shader could not be created!\n";
    }

    const GLchar* shaderStr[1];
    GLint shaderStrLength[1];

    shaderStr[0] = txt.c_str();
    shaderStrLength[0] = txt.length();

    glShaderSource(newShader, 1, shaderStr, shaderStrLength);
    glCompileShader(newShader);
    checkForShaderError(newShader, GL_COMPILE_STATUS, "Error: Shader failed to compile!");

    return newShader;
}

std::string Shader::LoadShader(const std::string& fileName)
{
    //Basically just loading a txt file, simple stuff
    std::ifstream file;
    file.open((fileName).c_str());

    std::string out;
    std::string line;

    if (file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            out.append(line + "\n");
        }
    }
    else //Error: could not load shader
    {
        std::cerr << "Shader: " << fileName << " could not be loaded!\n";
    }

    return out;
}

void Shader::checkForProgramError(GLuint program, GLuint flag, const std::string& errorMsg)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    glGetProgramiv(program, flag, &success);

    //If GL detects an error, print the error message
    if (success == GL_FALSE)
    {
        glGetProgramInfoLog(program, sizeof(error), NULL, error);
        std::cerr << errorMsg << ": " << error << std::endl;
    }
}

void Shader::checkForShaderError(GLuint shader, GLuint flag, const std::string& errorMsg)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    glGetShaderiv(shader, flag, &success);

    //If GL detects an error, print the error message
    if (success == GL_FALSE)
    {
        glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        std::cerr << errorMsg << ": " << error << std::endl;
    }
}

void Shader::UpdateShader(const Transformation& transformation)
{
    glm::mat4 modelMat = transformation.getModel();
    glUniformMatrix4fv(mUniforms[TRANSFROM_UNIFORM], 1, GL_FALSE, &modelMat[0][0]);
}
