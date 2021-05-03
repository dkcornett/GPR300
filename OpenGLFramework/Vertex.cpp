#include "Vertex.h"

Vertex::Vertex(const glm::vec3& pos, const glm::vec2& texcoord
            , const glm::vec3& normal)
{
    mPos = pos;
    mTexcoord = texcoord;
    mNormal = normal;
}
