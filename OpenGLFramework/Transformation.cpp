#include "Transformation.h"

glm::mat4 Transformation::getModel() const
{
    glm::mat4 posMat = glm::translate(mPos);
    glm::mat4 rotMatX = glm::rotate(mRot.x, glm::vec3(1, 0, 0));
    glm::mat4 rotMatY = glm::rotate(mRot.y, glm::vec3(0, 1, 0));
    glm::mat4 rotMatZ = glm::rotate(mRot.z, glm::vec3(0, 0, 1));
    glm::mat4 rotMat = rotMatZ * rotMatY * rotMatX;
    glm::mat4 scaleMat = glm::scale(mScale);

    return posMat * rotMat * scaleMat;
}
