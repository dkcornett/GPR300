#version 120


uniform sampler2D textureSampler;

varying vec2 texcoord0;

void main()
{
//referenced this for texture conversion in version 120:
//https://stackoverflow.com/questions/58063564/send-a-big-matrix-to-a-fragment-shader-in-glsl-version-120
//and here
//http://www.lighthouse3d.com/tutorials/glsl-12-tutorial/simple-texture/


  vec4 texColors = texture2D(textureSampler, texcoord0);

  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
  gl_FragColor = texColors;
}
