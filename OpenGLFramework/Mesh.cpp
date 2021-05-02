#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned numVert)
{
    mDrawCount = numVert;

    glGenVertexArrays(1, &mVertexArray);

    glBindVertexArray(mVertexArray);

    std::vector<glm::vec3> posVec;
    posVec.reserve(numVert);
    std::vector<glm::vec2> texcoordVec;
    texcoordVec.reserve(numVert);

    for (int i = 0; i < numVert; ++i)
    {
        posVec.push_back(*vertices[i].getPos());
        texcoordVec.push_back(*vertices[i].getTexcoord());
    }

    glGenBuffers(NUM_BUFFER, mVertexBuffer);

    //Position Buffer
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVert * sizeof(posVec[0])
                , &posVec[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //Texcoord Buffer
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVert * sizeof(texcoordVec[0])
                , &texcoordVec[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);


    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &mVertexArray);
}

void Mesh::drawMesh()
{
    glBindVertexArray(mVertexArray); //Bind
    glDrawArrays(GL_TRIANGLES, 0, mDrawCount);
    glBindVertexArray(0); //Unbind
}
