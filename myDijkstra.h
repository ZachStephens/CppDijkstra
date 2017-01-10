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

struct myCompare {
	bool operator()(const DjNode* N1, const DjNode* N2) {
		return N1->total_dist > N2->total_dist;
	}
};


class myDijkstra
{
public:

	myDijkstra();
	myDijkstra(DjMap* djptr,request* r1);
	~myDijkstra();
	void PerformDijkstra();
	DjNode* findClosestAvailable();
	void makeNbrAvailable(DjNode* closest); 
	void finishNode(DjNode * currentNode);
	//bool isAvailable(unsigned int id);
private:
	unsigned int startID;
	unsigned int destID; 
	DjMap * graph;
	map<unsigned int,DjNode*> available;
	map<unsigned int, DjNode*> finished;
	vector<DjNode *> path;
	priority_queue<DjNode*, vector<DjNode*>, myCompare> pq;
};

