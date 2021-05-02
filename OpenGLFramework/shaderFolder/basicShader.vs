#version 120

attribute vec3 coord;
attribute vec2 texCoord;

varying vec2 UV;

uniform mat4 transform;
//uniform mat4 MVP;

void main()
{
    gl_TexCoord[0] = gl_MultiTexCoord0;
    vec4 texPos= gl_Vertex;
    gl_Position = transform * texPos;
    UV = texCoord;


   // texcoord0 = texCoord;
}
