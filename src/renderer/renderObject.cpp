#include "RenderObject.hpp"
#include "../util/textureLoader.hpp"

namespace render
{
  RenderObject::RenderObject()
  {
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);
    vbo=1;
    transformMat.translate(glm::vec3(0,1,1));

    GLfloat texCoord[] =
    {
      0.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0,
      1.0f, 1.0f
    };

    loadBitmap("res/test.bmp");

    GLuint tex;
    glGenBuffers(1, &tex);
    glBindBuffer(GL_ARRAY_BUFFER, tex);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoord), texCoord, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, tex);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  }

  void RenderObject::render()
  {

    GLuint transID = glGetUniformLocation(shaderProg, "model");
    glUniformMatrix4fv(transID, 1, GL_FALSE, &transformMat.matrix[0][0]);

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    //glDisableVertexAttribArray(0);
  }

}
