#include "Cube.h"
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\string_cast.hpp>


Cube::Cube()
{

}

Cube::Cube(float size, std::string const shaderVertex, std::string const shaderFragment, float posX, float posY, float posZ)
	: m_size(size), m_shader(shaderVertex, shaderFragment), m_posX(posX), m_posY(posY), m_posZ(posZ), m_color("red")
{
	m_shader.load();

	size /= 2;

	float verticesTmp[] = { -size, -size, -size,   size, -size, -size,   size, size, -size,
		-size, -size, -size,   -size, size, -size,   size, size, -size, 

		size, -size, size,   size, -size, -size,   size, size, -size,
		size, -size, size,   size, size, size,   size, size, -size,
		
		-size, -size, size,   size, -size, size,   size, -size, -size,
		-size, -size, size,   -size, -size, -size,   size, -size, -size,
		
		-size, -size, size,   size, -size, size,   size, size, size,
		-size, -size, size,   -size, size, size,   size, size, size,

		-size, -size, -size,   -size, -size, size,   -size, size, size,
		-size, -size, -size,   -size, size, -size,   -size, size, size,

		-size, size, size,   size, size, size,   size, size, -size,
		-size, size, size,   -size, size, -size,   size, size, -size };

																			 
	// Couleurs temporaires

	float colorsTmp[] = { 1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0, 

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0

	/*	0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0, 
		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0, 

		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0, 
		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,

		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0*/
	
	};


	for (int i(0); i < 108; i++)
	{
		m_vertices[i] = verticesTmp[i];
		m_colors[i] = colorsTmp[i];
	}
}


Cube::~Cube()
{

}


void Cube::initCube()
{
	m_shader.setShaderFragment(m_shaderFragment);
	m_shader.setShaderVertex(m_shaderVertex);
	m_shader.load();

	m_size /= 2;

	float verticesTmp[] = { -m_size, -m_size, -m_size,   m_size, -m_size, -m_size,   m_size, m_size, -m_size,
		-m_size, -m_size, -m_size,   -m_size, m_size, -m_size,   m_size, m_size, -m_size,

		m_size, -m_size, m_size,   m_size, -m_size, -m_size,   m_size, m_size, -m_size,
		m_size, -m_size, m_size,   m_size, m_size, m_size,   m_size, m_size, -m_size,

		-m_size, -m_size, m_size,   m_size, -m_size, m_size,   m_size, -m_size, -m_size,
		-m_size, -m_size, m_size,   -m_size, -m_size, -m_size,   m_size, -m_size, -m_size,

		-m_size, -m_size, m_size,   m_size, -m_size, m_size,   m_size, m_size, m_size,
		-m_size, -m_size, m_size,   -m_size, m_size, m_size,   m_size, m_size, m_size,

		-m_size, -m_size, -m_size,   -m_size, -m_size, m_size,   -m_size, m_size, m_size,
		-m_size, -m_size, -m_size,   -m_size, m_size, -m_size,   -m_size, m_size, m_size,

		-m_size, m_size, m_size,   m_size, m_size, m_size,   m_size, m_size, -m_size,
		-m_size, m_size, m_size,   -m_size, m_size, -m_size,   m_size, m_size, -m_size };


	// Couleurs temporaires

	float colorsTmp[] = { 1.0,  1.0,  1.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0,  1.0,  1.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0
	};
	if (m_color == "red")
	{ 
		float colorsTmp[] = { 1.0,  1.0,  1.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0,  1.0,  1.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0
		};
	}
	else if (m_color == "green")
	{
		float colorsTmp[] = { 1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,

			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,

			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,

			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,

			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,

			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
			1.0,  1.0,  0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,
		};
	}




	for (int i(0); i < 108; i++)
	{
		m_vertices[i] = verticesTmp[i];
		m_colors[i] = colorsTmp[i];
	}
}

void Cube::display(glm::mat4 &projection, glm::mat4 &modelview)
{

	
	modelview = translate(modelview, glm::vec3(m_posX, m_posY, m_posZ));


	glUseProgram(m_shader.getProgramID());

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, m_colors);
	glEnableVertexAttribArray(1);

	glUniformMatrix4fv(glGetUniformLocation(m_shader.getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(m_shader.getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));


	glDrawArrays(GL_TRIANGLES, 0, 36);


	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glUseProgram(0);
}

void Cube::setSize(float size)
{
	m_size = size;
}

float Cube::getSize()
{
	return(m_size);
}

void Cube::setShaderFragment(std::string Fragment)
{
	m_shaderFragment = Fragment;
}

std::string Cube::getShadertFragment()
{
	return m_shaderFragment;
}

void Cube::setShaderVertex(std::string ShaderVertex)
{
	m_shaderVertex = ShaderVertex;
}

std::string Cube::getShaderVertex()
{
	return m_shaderVertex;
}

void Cube::setPosX(float posX)
{
	m_posX = posX;
}

float Cube::getposX()
{
	return m_posX;
}

void Cube::setPosY(float posY)
{
	m_posY = posY;
}

float Cube::getPosY()
{
	return m_posY;
}

void Cube::setPosZ(float posZ)
{
	m_posZ = posZ;
}

float Cube::getPosZ()
{
	return m_posZ;
}

void Cube::setColor(std::string color)
{
	m_color = color;
}

std::string Cube::getColor()
{
	return m_color;
}
