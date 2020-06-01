#ifndef TRANSFORMMATRIX_H_INCLUDED
#define TRANSFORMMATRIX_H_INCLUDED
#include <GLM/GLM.hpp>

namespace render
{

  class TransformMatrix
  {
  public:
    TransformMatrix();

    void translate(glm::vec3 delta);
    void yaw(float rads);
    void pitch(float rads);

    glm::mat4 matrix;
  private:
    void updateMatrix();

    glm::vec3 translation;
    glm::vec3 scale;
    float _yaw, _pitch;
  };

}
#endif // TRANSFORMMATRIX_H_INCLUDED
