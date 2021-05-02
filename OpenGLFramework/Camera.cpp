#include "Camera.h"

Camera::Camera(const glm::vec3& pos, float FOV, float aspect
                , float zNear, float zFar)
{
    mPerspective = glm::perspective(FOV, aspect, zNear, zFar);
    mPos = pos;
    mForward = glm::vec3(0, 0, 1);
    mUp = glm::vec3(0, 1, 0);
}

glm::mat4 Camera::getVeiwProjection() const
{
    return mPerspective * glm::lookAt(mPos, mPos + mForward, mUp);
}
