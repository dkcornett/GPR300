#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL2/SDL.h>

class Display
{
    public:
        Display(int w, int h, const std::string& title);
        virtual ~Display();

        void updateDisplay();
        bool isClosed() { return mIsDisplayClosed; };
        void clearDisplay(float r, float g, float b, float a);

    private:
        Display(const Display& other) {};
        void operator=(const Display& other) {};

        SDL_Window* mWindow;
        SDL_GLContext mGLContext;
        bool mIsDisplayClosed;
};

#endif // DISPLAY_H
