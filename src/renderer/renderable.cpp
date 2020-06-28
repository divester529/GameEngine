#include "Renderable.hpp"
#include "../util/textureAtlas.hpp"

namespace render
{
  Renderable::Renderable()
  {
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);
    vbo=1;
    transformMat.translate(glm::vec3(0,1,1));

    GLfloat texCoord[] =
    {
      0.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 0.0f,
      1.0f, 1.0f,

      0.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0,
      1.0f, 1.0f,
    };

    indicies = new std::vector<GLuint>();
    indicies->push_back(0);
    indicies->push_back(1);
    indicies->push_back(2);
    indicies->push_back(2);
    indicies->push_back(1);
    indicies->push_back(3);
    printf("indicies.size = %i\n", indicies->size());

    TextureAtlas tl("res/tileset1.bmp", 3);
    tl.useTexture();
    tl.setFrame(0);

    GLuint texCoordArray;
    glGenBuffers(1, &texCoordArray);
    glBindBuffer(GL_ARRAY_BUFFER, texCoordArray);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoord), texCoord, GL_STATIC_DRAW);

    GLuint elementBuffer;
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies->size()*sizeof(unsigned int), &(*indicies)[0], GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Vertex coords
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // UV coords
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, texCoordArray);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  }

  void Renderable::render()
  {
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);
    GLuint transLoc = glGetUniformLocation(shaderProg, "model");
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transformMat.matrix[0][0]);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
    //glDrawArrays(GL_TRIANGLES, 0, 12);
    //glDisableVertexAttribArray(0);
  }

}
