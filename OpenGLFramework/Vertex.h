#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
    public:
        Vertex(const glm::vec3& pos, const glm::vec2& texcoord
            , const glm::vec3& normal = glm::vec3(0, 0, 0));
        ~Vertex() {};

        inline glm::vec3* getPos() { return &mPos; };
        inline glm::vec2* getTexcoord() { return &mTexcoord; };
        inline glm::vec3* getNormal() { return &mNormal; };

    private:
        glm::vec3 mPos;
        glm::vec2 mTexcoord;
        glm::vec3 mNormal;

};

#endif // VERTEX_H
