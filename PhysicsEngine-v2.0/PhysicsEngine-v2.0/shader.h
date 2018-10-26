#pragma once

#include <string>
#include <GL/glew.h>

#include "transform.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	
	void Bind();

	void Update(const Transform& transform);

	//static std::string LoadShader(const std::string& fileName);
	//static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	//static GLuint CreateShader(const std::string& text, GLenum shaderType);

	virtual ~Shader();

protected:
private:
	static const unsigned int NUM_SHADERS = 2;

	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

};