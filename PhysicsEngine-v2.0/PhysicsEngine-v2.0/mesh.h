#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord) 
	{
		this->pos = pos;
		this->texCoord = texCoord;
	}

	// getters for pos and texCoord
	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }

protected:
private:
	glm::vec3 pos;
	glm::vec2 texCoord;

};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(const std::string& filename);

	virtual ~Mesh();

	void Draw();

protected:
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	void InitMesh(const IndexedModel& model);

	enum
	{
		POSITION_VB,
		TEXCOORD_VB,

		INDEX_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;	// version dependant may not work
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned m_drawCount;

};