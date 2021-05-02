#include "Display.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transformation.h"
#include <GL/glew.h>

int main()
{
    Display testDisplay(800, 600, "Linux OpenGL Demo");
    Vertex testVertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0))
                           , Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0))
                           , Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)), };

    Mesh testMesh(testVertices, sizeof(testVertices) / sizeof(testVertices[0]));
    Shader testShader("shaderFolder/basicShader");
    Texture testTexture("textureFolder/dan.jpg");
    Transformation testTransform;

    while (!testDisplay.isClosed())
    {
        testDisplay.clearDisplay(0.0, 0.0, 1.0, 1.0);
        testShader.Bind();
        testTexture.BindTexture(0);
        testShader.UpdateShader(testTransform);
        testMesh.drawMesh();
        testDisplay.updateDisplay();
    }

    return 0;
}
