#version 120

attribute vec3 pos;
attribute vec2 texcoord;

varying vec2 texcoord0;

//uniform mat4 MVP;

void main()
{
    //gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_Position = vec4(pos, 1.0);
    texcoord0 = texcoord;
}
