#include "camera.hpp"
#include "../engine.hpp" // For SCREEN_WIDTH, SCREEN_HEIGHT

namespace render
{
  Camera::Camera()
  {
    // Get reference to current shader program
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);

    projMat = glm::perspective(glm::radians(45.0f), float(SCREEN_WIDTH)/float(SCREEN_HEIGHT), 0.1f, 1000.0f);
    //projMat = glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, 0.0f, 100.0f);
    modelMat = glm::mat4(1.f);
    _pitch=_yaw=0;
    _pitch=-0.2;

    pos = glm::vec3(32.0f, 16.0f, 200);

    updateViewMatrix(); // compute the original view matrix
  }

  void Camera::move(glm::vec3 delta)
  {
    pos=pos+delta;
    updateViewMatrix();
  }

  void Camera::move(float delta)
  {
    float cosPitch = cos(_pitch);
    float sinPitch = sin(_pitch);

    float cosYaw = cos(_yaw);
    float sinYaw = sin(_yaw);

    pos[0]+=delta*sinYaw;
    pos[2]+=delta*cosYaw;
    updateViewMatrix();
  }

  void Camera::pitch(float rads)
  {
    _pitch+=rads;
    printf("pitch: %f\n", _pitch);
    updateViewMatrix();
  }

  void Camera::yaw(float rads)
  {
    _yaw+=rads;
    updateViewMatrix();
  }

  void Camera::useCamera()
  {
    glm::mat4 matrix = projMat*viewMat*modelMat;

    GLuint cameraID = glGetUniformLocation(shaderProg, "camera");
    glUniformMatrix4fv(cameraID, 1, GL_FALSE, &matrix[0][0]);
  }

  void Camera::onShaderUpdate()
  {
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);
  }

  void Camera::updateViewMatrix()
  {

    float cosPitch = cos(_pitch);
    float sinPitch = sin(_pitch);

    float cosYaw = cos(_yaw);
    float sinYaw = sin(_yaw);

    glm::vec3 xAxis(cosYaw, 0, -sinYaw);
    glm::vec3 yAxis(sinYaw*sinPitch, cosPitch, cosYaw*sinPitch);
    glm::vec3 zAxis(sinYaw*cosPitch, -sinPitch, cosPitch*cosYaw);

    viewMat = glm::mat4(
      glm::vec4(xAxis[0], yAxis[0], zAxis[0], 0),
      glm::vec4(xAxis[1], yAxis[1], zAxis[1], 0),
      glm::vec4(xAxis[2], yAxis[2], zAxis[2], 0),
      glm::vec4(-glm::dot(xAxis, pos), -glm::dot(yAxis, pos), -glm::dot(zAxis, pos), 1)
    );
  }
}
