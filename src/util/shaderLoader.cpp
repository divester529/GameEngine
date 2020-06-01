#include "shaderLoader.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

namespace renderer{

GLuint loadShaders(const char* vert_shader_path, const char* frag_shader_path)
{
  // Create shader pointers
  GLuint vertShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

  // Load shader code from source
  std::string vertShaderCode;
  std::ifstream vertShaderStream(vert_shader_path);

  if(vertShaderStream.is_open()){
    std::stringstream stream;
    stream << vertShaderStream.rdbuf();
    vertShaderCode = stream.str();
    vertShaderStream.close();
  }
  else{
    printf("Could not open file %s\n", vert_shader_path);
    return 0;
  }

  std::string fragShaderCode;
  std::ifstream fragShaderStream(frag_shader_path, std::ios::in);

  if(fragShaderStream.is_open()){
    std::stringstream stream;
    stream << fragShaderStream.rdbuf();
    fragShaderCode = stream.str();
    fragShaderStream.close();
  }
  else{
    printf("Could not open file %s\n", frag_shader_path);
    return 0;
  }

  // Compile shaders

  char const * vertSourcePointer = vertShaderCode.c_str();
  glShaderSource(vertShaderID, 1, &vertSourcePointer, NULL);
  glCompileShader(vertShaderID);

  char const * fragSourcePointer = fragShaderCode.c_str();
  glShaderSource(fragShaderID, 1, &fragSourcePointer, NULL);
  glCompileShader(fragShaderID);

  // Check shaders compilation status
  GLint result = GL_FALSE;
  int infoLogLength;

  glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(vertShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

  if(infoLogLength>0){
    std::vector<char> vertShaderErrMsg(infoLogLength+1);
    glGetShaderInfoLog(vertShaderID, infoLogLength, NULL, &vertShaderErrMsg[0]);
    printf("Error compiling vertex shader: %s\n", &vertShaderErrMsg);

    return 0;
  }

  glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(fragShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

  if(infoLogLength>0){
    std::vector<char> fragShaderErrMsg(infoLogLength+1);
    glGetShaderInfoLog(fragShaderID, infoLogLength, NULL, &fragShaderErrMsg[0]);
    printf("Error compiling fragment shader: %s\n", &fragShaderErrMsg);

    return 0;
  }

  // Create & link program
  GLuint sProgramID = glCreateProgram();
  glAttachShader(sProgramID, vertShaderID);
  glAttachShader(sProgramID, fragShaderID);
  glLinkProgram(sProgramID);

  glGetProgramiv(sProgramID, GL_LINK_STATUS, &result);
  glGetProgramiv(sProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);
  if(infoLogLength>0)
  {
      std::vector<char> progErrMsg(infoLogLength+1);
      glGetProgramInfoLog(sProgramID, infoLogLength, NULL, &progErrMsg[0]);
      printf("Error linking shader program %s\n", &progErrMsg);

      return 0;
  }

  // Delete shaders
  glDetachShader(sProgramID, vertShaderID);
  glDetachShader(sProgramID, fragShaderID);

  glDeleteShader(vertShaderID);
  glDeleteShader(fragShaderID);

  // Return the compiled shader
  return sProgramID;
}

}
