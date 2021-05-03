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
    //Create Display
    Display display(WINDOW_W, WINDOW_H, "Linux OpenGL Demo");

    //Load in resources from files
    Mesh mesh("modelFolder/monkey3.obj");
    Shader shader("shaderFolder/basicShader");
    Texture texture("textureFolder/bricks.jpg");

    //Create the camera and transform
    Camera cam(glm::vec3(0, 0, -7), 70.0f
            , (float)WINDOW_W / (float)WINDOW_H, 0.01f, 1000.0f);
    Transformation Transform;

    //Rendering Loop
    float counter = 0.0f;
    while (!display.isClosed())
    {
        //Clear the display
        display.clearDisplay(0.0, 0.0, 1.0, 1.0);

        //Animate the model
        Transform.getPos().x = sinf(counter) * 2.5; //move left and right
        Transform.getPos().z = cosf(counter) * 2.5; //move closer and farther from cam
        Transform.getRot().x = counter * 2.5; //rotate x
        Transform.getRot().y = counter * 2.5; //rotate y
        Transform.getRot().z = counter * 2.5; //rotate z

        //Bind the shader and texture
        shader.Bind();
        texture.BindTexture(0);

        //Update and draw
        shader.UpdateShader(Transform, cam);
        mesh.drawMesh();
        display.updateDisplay();
        counter += 0.0015f;
    }

    return 0;
}
