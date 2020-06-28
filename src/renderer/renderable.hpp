#ifndef RENDERABLE_H_INCLUDED
#define RENDERABLE_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <GLM/GLM.hpp>
#include <vector>
#include "transformMatrix.hpp"

namespace render{

  class Renderable
  {
  public:
    Renderable();

    virtual void render();

    TransformMatrix transformMat;
  private:
    GLint shaderProg;
    GLuint vbo;
    GLuint vao;

    float yaw, pitch;
    glm::vec3 position;

    std::vector<GLuint>* indicies;
  };

}

#endif // RENDERABLE_H_INCLUDED
