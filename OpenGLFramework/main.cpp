#include "Display.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include <GL/glew.h>

int main()
{
    Display testDisplay(800, 600, "Hello World :)");
    Vertex testVertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0))
                           , Vertex(glm::vec3(0, 0.5, 0))
                           , Vertex(glm::vec3(0.5, -0.5, 0)), };

    Mesh testMesh(testVertices, sizeof(testVertices) / sizeof(testVertices[0]));
    Shader testShader("../shaderFolder/basicShader");

    while (!testDisplay.isClosed())
    {
        testDisplay.clearDisplay(1.0, 1.0, 1.0, 1.0);
        testShader.Bind();
        testMesh.drawMesh();
        testDisplay.updateDisplay();
    }

    return 0;
}
