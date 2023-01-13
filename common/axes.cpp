
#include <GL/glew.h>

#include <common/axes.hpp>
#include <common/shader.hpp>

GLuint programIDAxes;
GLuint MatrixIDAxes;
GLuint vertexbufferAxes;
GLuint colorbufferAxes;

void initAxes() {
	GLuint VertexArrayIDAxes;
	glGenVertexArrays(1, &VertexArrayIDAxes);
	glBindVertexArray(VertexArrayIDAxes);

	programIDAxes = LoadShaders("../common/AxesShader.vs", "../common/AxesShader.fs");
	MatrixIDAxes = glGetUniformLocation(programIDAxes, "MVP");

	static const GLfloat g_vertex_buffer_data[] = {
		// +X axis
		0.0f,0.0f,0.0f,
		9.0f,0.0f,0.0f,
		// -X axis
		0.0f,0.0f,0.0f,
		-9.0f,0.0f,0.0f,
		// +Y axis
		0.0f,0.0f,0.0f,
		0.0f,9.0f,0.0f,
		//- Y axis
		0.0f,0.0f,0.0f,
		0.0f,-9.0f,0.0f,
		// +Z axis
		0.0f,0.0f,0.0f,
		0.0f,0.0f,9.0f,
		// -Z axis
		0.0f,0.0f,0.0f,
		0.0f,0.0f,-9.0f,
	};
	static const GLfloat g_color_buffer_data[] = {
		// R
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		// 0.5R
		0.5f,0.0f,0.0f,
		0.5f,0.0f,0.0f,
		// G
		0.0f,1.0f,0.0f,
		0.0f,1.0f,0.0f,
		// 0.5G
		0.0f,0.5f,0.0f,
		0.0f,0.5f,0.0f,
		// B
		0.0f,0.0f,1.0f,
		0.0f,0.0f,1.0f,
		// 0.5B
		0.0f,0.0f,0.5f,
		0.0f,0.0f,0.5f,
	};

	glGenBuffers(1, &vertexbufferAxes);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferAxes);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &colorbufferAxes);
	glBindBuffer(GL_ARRAY_BUFFER, colorbufferAxes);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}

void drawAxes(glm::mat4& MVP) {
	glUseProgram(programIDAxes);

	// use the same MVP
	glUniformMatrix4fv(MatrixIDAxes, 1, GL_FALSE, &MVP[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferAxes);
	glVertexAttribPointer(
		0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbufferAxes);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	glDrawArrays(GL_LINES, 0, 12);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}