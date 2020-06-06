#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec2 offset;
out vec2 UV;

uniform mat4 camera;
uniform mat4 model;

uniform float numRows;

void main(){
  gl_Position = camera*vec4(vertexPosition_modelspace,1);

  //UV = vertexUV;
  UV = (vertexUV/numRows)+(offset/numRows);
}
