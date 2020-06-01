#include "RenderObject.hpp"

namespace render
{
  RenderObject::RenderObject()
  {
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);
    vbo=1;
    transformMat.translate(glm::vec3(0,1,1));
  }

  void RenderObject::render()
  {

    GLuint transID = glGetUniformLocation(shaderProg, "model");
    glUniformMatrix4fv(transID, 1, GL_FALSE, &transformMat.matrix[0][0]);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
  }

}
