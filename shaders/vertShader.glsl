#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

uniform mat4 camera;
uniform mat4 model;

uniform vec2 offset;
uniform float numRows;

void main(){
  gl_Position = camera*model*vec4(vertexPosition_modelspace,1);

  //UV = vertexUV;
  UV = (vertexUV/numRows)+(offset/numRows);
}
