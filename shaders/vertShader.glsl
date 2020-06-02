#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 camera;
uniform mat4 model;

void main(){
  gl_Position = camera*model*vec4(vertexPosition_modelspace,1);
}
