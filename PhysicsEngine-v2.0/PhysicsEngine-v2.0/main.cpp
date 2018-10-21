#include <iostream>
#include <GL/glew.h>
#include "display.h"

int main(int argc, char** argv) 
{
	Display display(800, 600, "hello world");

	while (!display.isClosed())
	{
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		display.Update();
	}

	return 0;
}