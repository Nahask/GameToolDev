#include "ObjectHandler.h"
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\string_cast.hpp>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#include <rapidxml.hpp>
using namespace rapidxml;
using namespace std;



ObjectHandler::ObjectHandler()
	:objectList()
{
}


ObjectHandler::~ObjectHandler()
{

}

void ObjectHandler::initObject()
{



	xml_document<> doc;
	xml_node<> *root_node;

	std::ifstream theFile("map.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node("Objects");

	int i = 0;
	Cube *cubes = new Cube[20];


	

	for (xml_node<> *cube_node = root_node->first_node("Cube"); cube_node; cube_node = cube_node->next_sibling())
	{
		printf("Cube %s \n", cube_node->value());
	
		xml_node<> *pos_node = cube_node->first_node("size");
	
		cubes[i].setSize(atof(pos_node->value()));
		printf("%s\n", pos_node->value());
		pos_node = pos_node->next_sibling();
		
		cubes[i].setPosX(atof(pos_node->value()));
		printf("%s\n", pos_node->value());
		pos_node = pos_node->next_sibling();

		cubes[i].setPosY(atof(pos_node->value()));
		printf("%s\n", pos_node->value());
		pos_node = pos_node->next_sibling();

		cubes[i].setPosZ(atof(pos_node->value()));
		printf("%s\n", pos_node->value());
		pos_node = pos_node->next_sibling();
		
		cubes[i].setColor(pos_node->value());
		printf("%s\n", pos_node->value());
		pos_node = pos_node->next_sibling();
		
		cubes[i].setShaderFragment("Shaders/couleur3D.frag");	
		cubes[i].setShaderVertex("Shaders/couleur3D.vert");
		cubes[i].initCube();

		//objectList.push_back(cubes[0]);
		objectList.push_back(cubes[i]);
		i++;
	}
}

void ObjectHandler::updateObject(glm::mat4 projection,glm::mat4 modelview)
{

	glm::mat4 tmp = modelview;


	modelview = tmp;
	for (Cube test : objectList)
	{
		test.display(projection, modelview);
		modelview = tmp;
	}

}
