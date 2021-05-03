# animal3D-SDK-202101SP
animal3D SDK and related course frameworks for spring 2021.

---------------------------------------------------------

Final Project for GPR300 by Dianna Cornett and Alex Jaeger.

Published under the Apache license in April-May 2021.

--------------------------------------------------------

CODE IS PRESENTED "AS-IS" WITH NO WARRANTY.

--------------------------------------------------------

Intent of this project is for development of a graphics rendering machine to be run in Linux.
Development is being done in the Debian operating system (version: Debian Stretch), 
and for best results should be run in that operating system.

----

Dependencies: 

There are several Linux packages you will need to install before this program runs properly. These packages include:

codeblocks
codeblocks-dev
codeblocks-common

libglew2.1
libglew-dev
glew-utils
libglewmx1.12
libglewmx-dev

libglm-dev
libglm-doc

libsdl2-2.0-0
libsld2-dev
libsdl-image-2.0-0

----

List of Files:

In main repository directory:
LICENSE  OpenGLFramework/  README.md

in OpenGlFramework/
bin/         Mesh.h                  Shader.cpp     Texture.h
Camera.cpp   monkey3.obj             Shader.h       textureFolder/
Camera.h     obj_loader.cpp          shaderFolder/  Transformation.cpp
Display.cpp  obj_loader.h            stb_image.c    Transformation.h
Display.h    OpenGLFramework.cbp     stb_image.h    Vertex.cpp
main.cpp     OpenGLFramework.depend  teapot.obj     Vertex.h
Mesh.cpp     OpenGLFramework.layout  Texture.cpp


in OpenGLFramework/shaderFolder/
basicShader.fs  basicShader.vs

in OpenGLFramework/textureFolder/
bricks.jpg dan.jpg

in OpenGLFramework/bin/
Debug

in OpenGLFramework/bin/Debug/
OpenGLFramework

in OpenGLFramework/.vscode/
launch.json  tasks.json

-------

Instructions:

To run this project, open the file "OpenGLFramework.cbp" in Code::Blocks via the IDE's "open project" button. Once the project is open, make sure every single file in the project directory, shaderFolder/ and textureFolder/ is included in the hierarchy in the project sidebar. If the shader files, textures, and obj files do not show in the editor hierarchy
they may not load properly.

If you attempt to run this project from the command line, which we do not recommend,
you will need to change the asset filepaths from main.cpp, as Code::Blocks sets its
filepaths to relative from where the .cpb file is, instead of where the executable is located.
