GLFW_FLAGS := -I"../dean/glfw-3.3.8.bin.WIN64/include" \
              -L../dean/glfw-3.3.8.bin.WIN64/lib-mingw-w64 \
              -lglfw3

GLEW_FLAGS := -I"../dean/glew-2.1.0/include" \
              -L../dean/glew-2.1.0/bin/Release/x64 \
              -lglew32

GLM_FLAGS  := -I"../external/glm-0.9.7.1"

CFLAGS     += -Wall \
              -g \
              -lopengl32 \
              ${GLFW_FLAGS} \
              ${GLEW_FLAGS} \
              ${GLM_FLAGS}

program :
	g++ *.cpp $(CFLAGS) -o program

clean :
	rm program

# run cmd:
#put the 2 paths to the PATH of Windows for WAR.
#D:\ogl\dean\glfw-3.3.8.bin.WIN64\lib-mingw-w64
#D:\ogl\dean\glew-2.1.0\bin\Release\x64
#./program.exe
#or
#PATH=${PATH}:/d/ogl/dean/glfw-3.3.8.bin.WIN64/lib-mingw-w64:/d/ogl/dean/glew-2.1.0/bin/Release/x64 ./program.exe
