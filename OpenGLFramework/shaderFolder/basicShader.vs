#version 120

attribute vec3 pos;

void main()
{
     gl_Position = vec4(pos, 1.0);
}
