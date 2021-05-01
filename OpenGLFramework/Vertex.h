#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
    public:
        Vertex(const glm::vec3& pos);
        ~Vertex();

    private:
        glm::vec3 mPos;

};

#endif // VERTEX_H
