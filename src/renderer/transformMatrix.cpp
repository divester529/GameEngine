#include "transformMatrix.hpp"
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace render
{
  TransformMatrix::TransformMatrix()
  {
    position = glm::vec3(32.0f, 32.0f, 0.0f);

    identity=glm::mat4(1.0f);
    scale = glm::scale(glm::mat4(1.0f), glm::vec3(32.0f, -32.0f, 32.0f));
    matrix = glm::mat4(1.0f);

    updateMatrix();
  }

  void TransformMatrix::translate(glm::vec3 delta)
  {
    position = position+delta;
    updateMatrix();
  }

  void TransformMatrix::updateMatrix()
  {
    translation=glm::translate(glm::mat4(), position);
    matrix = translation*scale;
  }
}
