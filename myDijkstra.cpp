#include "myDijkstra.h"
#include "node.h"


myDijkstra::myDijkstra()
{
}

myDijkstra::myDijkstra(DjMap * djptr, request * r1)
{
	this->graph = djptr;
	this->startID = r1->root;
	this->destID = r1->dest;
}


myDijkstra::~myDijkstra()
{
}

void myDijkstra::PerformDijkstra()
{
	DjNode rootNode = {graph->getNode(startID),NULL,0};
	makeNbrAvailable(&rootNode);
}

void myDijkstra::makeNbrAvailable(DjNode * closest)
{
	unsigned int tempID;
	for (vector<node*>::iterator iter = closest->N->nbrList.begin(); iter != closest->N->nbrList.end(); ++iter) {
		tempID = (*iter)->getId();
		DjNode* tmpDN;
		if (available.find(tempID) == available.end()) {
			tmpDN = new DjNode;
			tmpDN->N = *iter;
			tmpDN->prevHop = closest;
			tmpDN->total_dist = closest->total_dist + (closest->N->nbrDist[tempID]);
		}
	}
}
