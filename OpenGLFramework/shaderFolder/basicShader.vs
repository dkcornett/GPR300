#version 120

attribute vec3 pos;

void main()
{
     gl_position = vec4(pos, 1.0);
}
