#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
    public:
        Vertex(const glm::vec3& pos, const glm::vec2& texcoord);
        ~Vertex();

        inline glm::vec3* getPos() { return &mPos; };
        inline glm::vec2* getTexcoord() { return &mTexcoord; };

    private:
        glm::vec3 mPos;
        glm::vec2 mTexcoord;

};

#endif // VERTEX_H
