#include "Display.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transformation.h"
#include "Camera.h"
#include <GL/glew.h>

const int WINDOW_W = 800;
const int WINDOW_H = 600;

int main()
{
    Display testDisplay(WINDOW_W, WINDOW_H, "Linux OpenGL Demo");
    Vertex testVertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0))
                           , Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0))
                           , Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)), };

    unsigned index[] = { 0, 1, 2};

    Mesh testMesh(testVertices, sizeof(testVertices) / sizeof(testVertices[0])
                , index, sizeof(index) / sizeof(index[0]));
    Mesh testMesh2("modelFolder/monkey3.obj");
    Shader testShader("shaderFolder/basicShader");
    Texture testTexture("textureFolder/bricks.jpg");
    Camera testCamera(glm::vec3(0, 0, -7), 70.0f
                      , (float)WINDOW_W / (float)WINDOW_H, 0.01f, 1000.0f);
    Transformation testTransform;

    float counter = 0.0f;

    while (!testDisplay.isClosed())
    {
        testDisplay.clearDisplay(0.0, 0.0, 1.0, 1.0);

        testTransform.getPos().x = sinf(counter) * 2.5; //move left and right
        testTransform.getPos().z = cosf(counter) * 2.5; //move closer and farther from cam
        testTransform.getRot().x = counter * 2.5; //rotate x
        testTransform.getRot().y = counter * 2.5; //rotate y
        testTransform.getRot().z = counter * 2.5; //rotate z
        //testTransform.setScale(glm::vec3(cosf(counter)
        //                        , cosf(counter), cosf(counter))); //scale up and down

        testShader.Bind();
        testTexture.BindTexture(0);
        testShader.UpdateShader(testTransform, testCamera);
        testMesh2.drawMesh();
        testDisplay.updateDisplay();
        counter += 0.0015f;
    }

    return 0;
}
