#ifndef RENDEROBJECT_H_INCLUDED
#define RENDEROBJECT_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <GLM/GLM.hpp>
#include "transformMatrix.hpp"

namespace render{

  class RenderObject
  {
  public:
    RenderObject();

    virtual void render();
  private:
    GLint shaderProg;
    GLuint vbo;
    GLuint vao;

    float yaw, pitch;
    glm::vec3 position;

    TransformMatrix transformMat;
  };

}

#endif // RENDEROBJECT_H_INCLUDED
