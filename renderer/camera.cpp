#include "camera.hpp"
#include "../engine.hpp" // For SCREEN_WIDTH, SCREEN_HEIGHT

namespace renderer
{
  Camera::Camera()
  {
    // Get reference to current shader program
    shaderProg;
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);

    projMat = glm::perspective(glm::radians(45.0f), float(SCREEN_WIDTH)/float(SCREEN_HEIGHT), 0.1f, 100.0f);

    modelMat = glm::mat4(1.0f);

    pos = glm::vec3(0, -1, 1);

    updateViewMatrix(); // compute the original view matrix
  }

  void Camera::move(glm::vec3 delta)
  {
    pos=pos+delta;
    updateViewMatrix();
  }

  void Camera::pitch(float rads)
  {
    _pitch+=rads;
    updateViewMatrix();
  }

  void Camera::yaw(float rads)
  {
    _yaw+=rads;
    updateViewMatrix();
  }

  void Camera::useCamera()
  {

    glm::mat4 mvp = projMat*viewMat*modelMat;

    GLuint mvpID = glGetUniformLocation(shaderProg, "MVP");
    glUniformMatrix4fv(mvpID, 1, GL_FALSE, &mvp[0][0]);
  }

  void Camera::updateViewMatrix()
  {
    float cosPitch = cos(_pitch);
    float sinPitch = sin(_pitch);

    float cosYaw = cos(_yaw);
    float sinYaw = sin(_yaw);

    glm::vec3 xAxis(cosYaw, 0, -sinYaw);
    glm::vec3 yAxis(sinYaw*sinPitch, cosPitch, cosYaw);
    glm::vec3 zAxis(sinYaw*cosPitch, -sinPitch, cosPitch);

    viewMat = glm::mat4(
      glm::vec4(xAxis[0], yAxis[0], zAxis[0], 0),
      glm::vec4(xAxis[1], yAxis[1], zAxis[1], 0),
      glm::vec4(xAxis[1], yAxis[1], zAxis[1], 0),
      glm::vec4(-glm::dot(xAxis, pos), -glm::dot(yAxis, pos), -glm::dot(zAxis, pos), 1)
    );

  }
}