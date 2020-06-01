#ifndef SHADERLOADER_H_INCLUDED
#define SHADERLOADER_H_INCLUDED
#include <GL/GLew.H>
#include <GL/GL.H>
#include <GL/GLu.H>
#include <GL/GLext.h>

namespace renderer{

  GLuint loadShaders(const char* vert_shader_path, const char* frag_shader_path);

}

#endif //SHADERLOADER_H_INCLUDED
