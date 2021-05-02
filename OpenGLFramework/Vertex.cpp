#include "Vertex.h"

Vertex::Vertex(const glm::vec3& pos, const glm::vec2& texcoord)
{
    mPos = pos;
    mTexcoord = texcoord;
}

Vertex::~Vertex()
{

}
