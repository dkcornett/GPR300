#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
    public:
        Vertex(glm::vec3& pos);
        virtual ~Vertex();

    protected:

    private:
        Vertex(const Vertex& other) {};
        void operator=(const Vertex& other) {};

        glm::vec3 mPos;
};

#endif // VERTEX_H
