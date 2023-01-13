HEADER_DIR := -I".." \
              -I"../dean/glfw-3.3.8.bin.WIN64/include" \
              -I"../dean/glew-2.1.0/include" \
              -I"../external/glm-0.9.7.1"

LIB_DIR    := -L../dean/glfw-3.3.8.bin.WIN64/lib-mingw-w64 \
              -L../dean/glew-2.1.0/bin/Release/x64

LIBS       := -lglfw3 \
              -lglew32

CFLAGS     += -Wall \
              -Werror \
              -Wno-unused-variable \
              -g \
              -lopengl32 \
              ${HEADER_DIR} \
              ${LIB_DIR} \
              ${LIBS}

SRC_FILES  := tutorial12.cpp \
              ../common/shader.cpp \
              ../common/texture.cpp \
              ../common/controls.cpp \
              ../common/objloader.cpp \
              ../common/vboindexer.cpp \
              ../common/axes.cpp

program :
	g++ $(SRC_FILES) $(CFLAGS) -o program

clean :
	rm program

# run cmd:
#put the 2 paths to the PATH of Windows for WAR.
#D:\ogl\dean\glfw-3.3.8.bin.WIN64\lib-mingw-w64
#D:\ogl\dean\glew-2.1.0\bin\Release\x64
#./program.exe
#or
#PATH=${PATH}:/d/ogl/dean/glfw-3.3.8.bin.WIN64/lib-mingw-w64:/d/ogl/dean/glew-2.1.0/bin/Release/x64 ./program.exe
