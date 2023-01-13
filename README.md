# dean notes

## download code
- 直接在D盘下面clone, code里面的一些cmd都不用改.
`cd /d && git clone XXX`

## setup local Windows env with VS code.
The lib dirs above are added to Windows PATH or put the same dir with the program.exe for running. Windows除了要OpenGL的驱动, 不需要安装任何lib.

- glut https://www.transmissionzero.co.uk/computing/using-glut-with-mingw/
HelloGlut是测试程序, 用的是freeglut不是glut
`cd /d/ogl/dean/HelloGLUT && make`
`PATH=${PATH}:/d/ogl/dean/freeglut-MinGW-3.0.0-1.mp/freeglut/bin/x64 ./program.exe`

- GLFW https://www.glfw.org/download.html
.dll好像不能和.a放一起

- GLEW https://glew.sourceforge.net/

- GLM https://glm.g-truc.net/0.9.9/

- AntTweakBar
needed by T17.

## all binaries
See the makefiles added by the last commit.

## commit code
```
git add <file>
git commit --amend
git push -f
```