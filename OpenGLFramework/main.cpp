#include "Display.h"
#include "Shader.h"
#include <GL/glew.h>

int main()
{
    Display testDisplay(800, 600, "Hello World :)");
    Shader testShader("../shaderFolder/basicShader");

    while (!testDisplay.isClosed())
    {
        testDisplay.clearDisplay(1.0, 1.0, 1.0, 1.0);
        testShader.Bind();
        testDisplay.updateDisplay();
    }

    return 0;
}
