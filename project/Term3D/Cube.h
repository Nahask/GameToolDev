#ifndef _CUBE
#define _CUBE

#include <GL\glew.h>

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\transform.hpp>

#include "Shader.h"

class Cube
{
public:
	Cube();
	Cube(float size, std::string const shaderVertex, std::string const shaderFragment, float posX, float posY, float posZ);
	~Cube();

	void initCube();

	void display(glm::mat4 &projection, glm::mat4 &modelview);

	void setSize(float size);
	float getSize();
	void setShaderFragment(std::string Fragment);
	std::string getShadertFragment();
	void setShaderVertex(std::string Vertex);
	std::string getShaderVertex();
	void setPosX(float posX);
	float getposX();
	void setPosY(float posY);
	float getPosY();
	void setPosZ(float posZ);
	float getPosZ();
	void setColor(std::string color);
	std::string getColor();


private:
	float m_size;
	std::string m_shaderFragment;
	std::string m_shaderVertex;
	std::string m_color;
	Shader m_shader;
	float m_vertices[108];
	float m_colors[108];
	float m_posX;
	float m_posY;
	float m_posZ;



};

#endif // !_CUBE
