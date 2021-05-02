#ifndef CAMERA_H
#define CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
    public:
        Camera(const glm::vec3& pos, float FOV, float aspect
                , float zNear, float zFar);

        glm::mat4 getVeiwProjection() const;

    private:
        glm::mat4 mPerspective;
        glm::vec3 mPos;
        glm::vec3 mForward;
        glm::vec3 mUp;
};

#endif // CAMERA_H
