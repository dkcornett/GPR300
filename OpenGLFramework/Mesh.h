#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include <GL/glew.h>

class Mesh
{
    public:
        Mesh(Vertex* vertices, unsigned numVert);
        virtual ~Mesh();

        void drawMesh();

    protected:

    private:
        Mesh(const Mesh& other) {};
        void operator=(const Mesh& other) {};

        enum
        {
            POSITION_VB,
            NUM_BUFFER
        };

        GLuint mVertexArray;
        GLuint mVertexBuffer[NUM_BUFFER];
        unsigned mDrawCount;
};

#endif // MESH_H
