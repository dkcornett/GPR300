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
    Texture testTexture("textureFolder/bricks.jpg");
    Transformation testTransform;

    float counter = 0.0f;

    while (!testDisplay.isClosed())
    {
        testDisplay.clearDisplay(0.0, 0.0, 1.0, 1.0);

        testTransform.getPos().x = sinf(counter); //move left and right
        testTransform.getRot().z = counter * 50; //rotate
        testTransform.setScale(glm::vec3(cosf(counter)
                                , cosf(counter), cosf(counter))); //scale up and down

        testShader.Bind();
        testTexture.BindTexture(0);
        testShader.UpdateShader(testTransform);
        testMesh.drawMesh();
        testDisplay.updateDisplay();
        counter += 0.0015f; //CHANGE TO DELTA TIME
    }

    return 0;
}
