#include "Display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int w, int h, const std::string& title)
{
    SDL_Init(SDL_INIT_EVERYTHING); //Change if we want display to do more than windowing

    //Set GL Attributes
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Create window and context
    mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED
                ,SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
    mGLContext = SDL_GL_CreateContext(mWindow);

    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
       std::cerr << "Error: Glew failed to init!\n";
    }

    mIsDisplayClosed = false;
}

void Display::updateDisplay()
{
    SDL_GL_SwapWindow(mWindow);

    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            mIsDisplayClosed = true;
        }
    }
}

void Display::clearDisplay(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

Display::~Display()
{
    SDL_GL_DeleteContext(mGLContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
