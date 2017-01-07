#include "DjMap.h"
#include <fstream>

using namespace std;

DjMap::DjMap()
{
}


DjMap::~DjMap()
{
}

DjMap::DjMap(unsigned int num_nodes, unsigned int num_edges)
{
	this->node_count = num_nodes;
	this->edge_count = num_edges;
}

node * DjMap::getNode(unsigned int id)
{
	return nullptr;
}

void DjMap::addNode(node * newNode)
{
	nodeMap[newNode->getId()]=newNode;
}




unsigned int DjMap::getEdgeCount(void)
{
	return edge_count;
}

void DjMap::addConnection(unsigned int A, unsigned int B)
{
	node* nodeA = nodeMap[A];
	node* nodeB = nodeMap[B];
	float distance = sqrt(pow(nodeA->getXpos()-nodeB->getXpos(),2)+pow(nodeA->getYpos() - nodeB->getYpos(),2));
	nodeA->addNbr(nodeB,distance);
	nodeB->addNbr(nodeA,distance);
}

bool DjMap::isValidRequest(request r1)
{
	if ((nodeMap.find(r1.root) == nodeMap.end())
		|| (nodeMap.find(r1.dest) == nodeMap.end()))
		return false;
	else
		return true;
}

