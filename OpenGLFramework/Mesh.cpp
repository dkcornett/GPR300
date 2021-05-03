#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned numVert, unsigned* index
            , unsigned numIndex)
{
    IndexedModel model;

    for (int i = 0; i < numVert; ++i)
    {
        model.positions.push_back(*vertices[i].getPos());
        model.texCoords.push_back(*vertices[i].getTexcoord());
        model.normals.push_back(*vertices[i].getNormal());
    }

    for (int i = 0; i < model.indices.size(); ++i)
    {
        model.indices.push_back(index[i]);
    }

    InitMesh(model);
}

Mesh::Mesh(const std::string& filename)
{
    IndexedModel model = OBJModel(filename).ToIndexedModel();
    InitMesh(model);
}

void Mesh::InitMesh(const IndexedModel& model)
{
    mDrawCount = model.indices.size();
    glGenVertexArrays(1, &mVertexArray);

    glBindVertexArray(mVertexArray);

    glGenBuffers(NUM_BUFFER, mVertexBuffer);

    //Position Buffer
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size()
                * sizeof(model.positions[0]), &model.positions[0]
                , GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //Texcoord Buffer
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size()
                * sizeof(model.texCoords[0])
                , &model.texCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    //Normal Buffer
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.normals.size()
                * sizeof(model.normals[0]), &model.normals[0]
                , GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //Index Buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVertexBuffer[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size()
                * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &mVertexArray);
}

void Mesh::drawMesh()
{
    glBindVertexArray(mVertexArray); //Bind
    glDrawElements(GL_TRIANGLES, mDrawCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0); //Unbind
}
