#version 120

attribute vec3 pos;

uniform mat4 MVP;

void main()
{
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_Position = vec4(pos, 1.0);
}
