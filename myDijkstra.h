#pragma once
#include "types.h"
#include "Djmap.h"
#include "node.h"
#include <map>
#include <vector>
#include <list>
using namespace std;

typedef struct djnode{
	node* N;
	struct djnode * prevHop;
	float total_dist;
}DjNode;

class myDijkstra
{
public:

	myDijkstra();
	myDijkstra(DjMap* djptr,request* r1);
	~myDijkstra();
	void PerformDijkstra();
	void findClosestAvailable();
	void makeNbrAvailable(DjNode* closest);
	//bool isAvailable(unsigned int id);
private:
	unsigned int startID;
	unsigned int destID;
	DjMap * graph;
	map<unsigned int,DjNode*> available;
	vector<DjNode *> path;
	vector<DjNode *> finished;	
};

