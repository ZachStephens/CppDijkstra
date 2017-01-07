#pragma once
#include <vector>
class node
{	
public:
	node();
	node(unsigned int id, float xpos, float ypos);
	~node();
	float magnitudeFrom(node* const other);
	void addNbr(node* newNbr);
	void addNbr(node * newNbr,float dist);
	float getYpos(void) { return ypos; }
	float getXpos(void) { return xpos; }
	unsigned int getId(void) { return id; }
private:
	unsigned int id;
	float xpos;
	float ypos;
	std::vector<float> nbrDist;
	std::vector<node*> nbrList;
};

