#pragma once
#include <vector>
#include <map>

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
	std::vector<node*> nbrList;
	std::map<unsigned int, float> nbrDist;
private:
	unsigned int id;
	float xpos;
	float ypos;
	
	
};

