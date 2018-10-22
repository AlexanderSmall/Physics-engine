#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"

#include <windows.h>
#include <string>

std::string current_working_directory()
{
	char working_directory[MAX_PATH + 1];
	GetCurrentDirectoryA(sizeof(working_directory), working_directory); // **** win32 specific ****
	return working_directory;
}

int main(int argc, char** argv) 
{
	Display display(800, 600, "OpenGL graphics");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, 0.5, 0)), 
						  Vertex(glm::vec3(0.5, 0.5, 0)), 
						  Vertex(glm::vec3(0.5, -0.5, 0)) };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	//Shader shader(current_working_directory() + "\\res\\basic");
	Shader shader(".\\res\\basic");
	//Shader shader("C:\\Users\\alexs\\source\\repos\\Physics-engine\\PhysicsEngine-v2.0\\basic.vs");

	while (!display.isClosed())
	{
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		mesh.Draw();

		shader.Bind();

		display.Update();
	}

	return 0;
}