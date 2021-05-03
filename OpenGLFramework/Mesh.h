#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include <vector>
#include <GL/glew.h>
#include <obj_loader.h> //link to file

class Mesh
{
    public:
        Mesh(Vertex* vertices, unsigned numVert, unsigned* index
            , unsigned numIndex);
        Mesh(const std::string& filename);

        virtual ~Mesh();

        void drawMesh();

    private:
        Mesh(const Mesh& other) {};
        void operator=(const Mesh& other) {};

        void InitMesh(const IndexedModel& model);

        enum vertexBufferEnum
        {
            POSITION_VB,
            TEXCOORD_VB,
            INDEX_VB,
            NUM_BUFFER
        };

        GLuint mVertexArray;
        GLuint mVertexBuffer[NUM_BUFFER];
        unsigned mDrawCount;
};

#endif // MESH_H
