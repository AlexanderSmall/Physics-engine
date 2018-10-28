#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		
		// TODO: pass m_forward and m_up as parameters
		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
	}

	inline glm::mat4 GetViewProjection() const
	{
		// glm function that make rortation easy
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}

protected:
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position; // position of camera
	// representing camera rotation
	glm::vec3 m_forward;
	glm::vec3 m_up;
};