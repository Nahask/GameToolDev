#pragma once
#include "Cube.h"
#include <list>
#include <vector>

class ObjectHandler
{
public:
	ObjectHandler();
	~ObjectHandler();

	void initObject();
	void updateObject(glm::mat4 projection,	glm::mat4 modelview);

	//void allObj();



private:
	std::list<Cube> objectList;



};
