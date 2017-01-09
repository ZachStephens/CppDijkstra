#pragma once
#include <vector>
#include <queue>
#include "node.h"
#include "types.h"
#include <iostream>
#include <fstream>
#include <map>



class DjMap
{
public:
	DjMap();
	~DjMap();
	DjMap(unsigned int num_nodes, unsigned int num_edges);
	node * getNode(unsigned int id);
	void addNode(node * newNode);
	unsigned int getNodeCount(void) { return nodeMap.size(); };
	unsigned int getEdgeCount(void);
	void addConnection(unsigned int A, unsigned int B);
	bool isValidRequest(request r1);
private:
	unsigned int node_count;
	unsigned int edge_count;
	std::map<unsigned int, node*> nodeMap;
};

