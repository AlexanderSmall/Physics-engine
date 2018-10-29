#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#include <windows.h>
#include <string>

/* TODO:
	create getter and setter for aspect ratio
*/
#define WIDTH 800
#define HEIGHT 600

std::string current_working_directory()
{
	char working_directory[MAX_PATH + 1];
	GetCurrentDirectoryA(sizeof(working_directory), working_directory); // **** win32 specific ****
	return working_directory;
}

int main(int argc, char** argv) 
{
	Display display(800, 600, "OpenGL graphics");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0),  glm::vec2(0.0, 0.0)), 
						  Vertex(glm::vec3(0, 0.5, 0),		glm::vec2(0.5, 1.0)), 
						  Vertex(glm::vec3(0.5, -0.5, 0),   glm::vec2(1.0, 0.0)), };

	unsigned int indices[] = { 0, 1, 2 };

	/*Create mesh*/
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh meshSphere(".\\res\\monkey3.obj");


	/*Create Shader*/
	Shader shader(".\\res\\basic");
	/*Create texture*/
	Texture texture(".\\res\\bricks.jpg");
	/*Create Camera*/
	// alter Z value of vec3 using scroll wheel
	Camera camera(glm::vec3(0, 0, -6), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	/*Create transform matrix*/
	Transform transform;

	// remove:
	float counter = 0.0f;

	while (!display.isClosed())
	{
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//display.Clear(0.0f, 0.15f, 0.3f, 1.0f);


		// remove:
		transform.GetPos().x = sinf(counter);
		//rotate arounds screen
		transform.GetRot().y = cosf(counter);
		
		shader.Bind();
		// takes transform and alters all positions in the vertex shader
		shader.Update(transform, camera);

		texture.Bind(0);

		// Draw mesh of vertices
		mesh.Draw();
		meshSphere.Draw();

		display.Update();

		// remove:
		counter += 0.001f;
	}

	return 0;
}