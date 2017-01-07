#include "node.h"



node::node()
{
}


node::node(unsigned int id, float xpos, float ypos)
{
	this->id = id;
	this->xpos = xpos;
	this->ypos = ypos;
}

node::~node()
{
}

float node::magnitudeFrom(node * const other)
{
		
	return 0.0f;
}

void node::addNbr(node * newNbr)
{
}

void node::addNbr(node * newNbr, float dist)
{
}
