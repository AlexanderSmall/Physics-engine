#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos) 
	{
		this->pos = pos;
	}
protected:
private:
	glm::vec3 pos;

};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	virtual ~Mesh();

	void Draw();

protected:
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	enum
	{
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;	// version dependant may not work
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned m_drawCount;

};