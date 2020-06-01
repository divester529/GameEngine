#include "transformMatrix.hpp"

namespace render
{
  TransformMatrix::TransformMatrix()
  {
    matrix = glm::mat4(1.0f);
  }

  void TransformMatrix::translate(glm::vec3 delta)
  {
    translation=translation+delta;
    updateMatrix();
  }

  void TransformMatrix::yaw(float rads)
  {
    _yaw+=rads;
    updateMatrix();
  }

  void TransformMatrix::pitch(float rads)
  {
    _pitch+=rads;
    updateMatrix();
  }

  void TransformMatrix::updateMatrix()
  {
    float cosPitch = cos(_pitch);
    float sinPitch = sin(_pitch);

    float cosYaw = cos(_yaw);
    float sinYaw = sin(_yaw);

    glm::vec3 xAxis(cosYaw, 0, -sinYaw);
    glm::vec3 yAxis(sinYaw*sinPitch, cosPitch, cosYaw);
    glm::vec3 zAxis(sinYaw*cosPitch, -sinPitch, cosPitch);

    matrix = glm::mat4(
      glm::vec4(xAxis[0], yAxis[0], zAxis[0], 0),
      glm::vec4(xAxis[1], yAxis[1], zAxis[1], 0),
      glm::vec4(xAxis[1], yAxis[1], zAxis[1], 0),
      glm::vec4(-glm::dot(xAxis, translation), -glm::dot(yAxis, translation), -glm::dot(zAxis, translation), 1)
    );
  }
}
