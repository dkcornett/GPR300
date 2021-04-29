#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned numVert)
{
    mDrawCount = numVert;

    glGenVertexArrays(1, &mVertexArray);

    glBindVertexArray(mVertexArray); //Bind

    glGenBuffers(NUM_BUFFER, mVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVert * sizeof(vertices[0])
                , vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0); //Unbind
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
