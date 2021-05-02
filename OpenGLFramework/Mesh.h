#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include <vector>
#include <GL/glew.h>

class Mesh
{
    public:
        Mesh(Vertex* vertices, unsigned numVert);
        virtual ~Mesh();

        void drawMesh();

    private:
        Mesh(const Mesh& other) {};
        void operator=(const Mesh& other) {};

        enum meshEnum
        {
            POSITION_VB,
            TEXCOORD_VB,
            NUM_BUFFER
        };

        GLuint mVertexArray;
        GLuint mVertexBuffer[NUM_BUFFER];
        unsigned mDrawCount;
};

#endif // MESH_H
