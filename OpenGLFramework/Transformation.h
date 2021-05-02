#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transformation
{
    public:
        Transformation(const glm::vec3& pos = glm::vec3()
                , const glm::vec3& rot = glm::vec3()
                , const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
        mPos(pos),
        mRot(rot),
        mScale(scale) {}

        inline glm::vec3& getPos() { return mPos; };
        inline glm::vec3& getRot() { return mRot; };
        inline glm::vec3& getScale() { return mScale; };
        glm::mat4 getModel() const;

        inline void setPos(glm::vec3& pos) { mPos = pos; };
        inline void setRot(glm::vec3& rot) { mRot = rot; };
        inline void setScale(glm::vec3& scale) { mScale = scale; };

    protected:

    private:
    glm::vec3 mPos;
    glm::vec3 mRot;
    glm::vec3 mScale;
};

#endif // TRANSFORMATION_H
