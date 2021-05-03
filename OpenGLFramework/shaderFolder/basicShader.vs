#version 120

attribute vec3 pos;
attribute vec2 texcoord;
attribute vec3 normal;

varying vec2 vTexcoord;
varying vec3 vNormal;

uniform mat4 transform;
//uniform mat4 MVP;

void main()
{
    //gl_TexCoord[0] = gl_MultiTexCoord0;


    gl_Position = transform * vec4(pos, 1.0);
    vTexcoord = texcoord;
    vNormal = (transform * vec4(normal, 0.0)).xyz;
}
