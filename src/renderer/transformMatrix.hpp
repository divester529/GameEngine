#ifndef TRANSFORMMATRIX_H_INCLUDED
#define TRANSFORMMATRIX_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <GLM/GLM.hpp>
#include <GLM/ext.hpp>

namespace render
{

  class TransformMatrix
  {
  public:
    TransformMatrix();

    void translate(glm::vec3 delta);

    void setScale(GLfloat _scale);

    glm::mat4 matrix;
  private:
    void updateMatrix();

    glm::vec3 position;
    glm::vec3 rotation;

    glm::mat4 translation;
    glm::mat4 scale;
    glm::mat4 identity;
  };

}
#endif // TRANSFORMMATRIX_H_INCLUDED
