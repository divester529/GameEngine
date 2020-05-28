#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/GLew.h>
#include <GL/GL.h>
#include <GL/GLext.h>
#include <GL/GLu.h>
#include <math.h>

namespace renderer
{

  class Camera
  {
  public:
    Camera();

    void move(glm::vec3 delta);
    void yaw(float rads);
    void pitch(float rads);

    void useCamera(); // Applies MVP matrix to the shader program

  private:
    glm::mat4 projMat;
    glm::mat4 viewMat;
    glm::mat4 modelMat;

    float _yaw, _pitch;
    glm::vec3 pos;

    GLint shaderProg;

    void updateViewMatrix(); // computes new view matrix
  };

}

#endif
