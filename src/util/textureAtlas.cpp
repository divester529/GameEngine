#include "textureAtlas.hpp"
#include <glm/glm.hpp>

TextureAtlas::TextureAtlas(std::string path)
{
    texture = loadBitmap(path);
    numRows=1;
}

TextureAtlas::TextureAtlas(std::string path, int _numRows)
{
  texture = loadBitmap(path);
  numRows=_numRows;
}

void TextureAtlas::useTexture()
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture.id);
}

void TextureAtlas::setFrame(int index)
{
  int frameSize=texture.width/numRows;
  float offsetX=index%numRows;
  float offsetY=index/numRows;
  printf("Framesize %i\n", frameSize);
  printf("%f, %f\n", offsetX, offsetY);

  glm::vec2 offset((float)offsetX, (float)offsetY);

  GLint shaderProg;
  glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProg);

  GLuint offsetLoc = glGetUniformLocation(shaderProg, "offset");
  glUniform2f(offsetLoc, offset[0], offset[1]);

  GLuint numRowsLoc = glGetUniformLocation(shaderProg, "numRows");
  glUniform1f(numRowsLoc, numRows);
}
