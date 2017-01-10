#include "myDijkstra.h"
#include "node.h"
#include <map>
#include <iostream>


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

void myDijkstra::finishNode(DjNode * currentNode) {
	available.erase(currentNode->N->getId());
	finished[currentNode->N->getId()]=currentNode;
	cout << "Finishing" << currentNode->N->getId() << endl;

}

void myDijkstra::makeNbrAvailable(DjNode * closest)
{
	unsigned int tempID;
	float tempDist;
	for (vector<node*>::iterator iter = closest->N->nbrList.begin(); iter != closest->N->nbrList.end(); ++iter) {
		tempID = (*iter)->getId();
		DjNode* tmpDN;
		tempDist = closest->total_dist + (closest->N->nbrDist[tempID]);

		if (finished.find(tempID) != finished.end())continue;

		if (available.find(tempID) == available.end()) {
			tmpDN = new DjNode;
			tmpDN->N = *iter;
			tmpDN->prevHop = closest;
			tmpDN->total_dist = tempDist;
			cout << "Adding " << tempID << endl;
			available[tempID] = tmpDN;
			pq.push(tmpDN);
		}
		else if (tempDist < available[tempID]->total_dist) {
			available[tempID]->total_dist = tempDist;
			available[tempID]->prevHop = closest;
		}
	}
}


void myDijkstra::PerformDijkstra()
{
	DjNode* currentNode;
	DjNode root = {graph->getNode(startID),NULL,0};
	currentNode = &root;
	available[currentNode->N->getId()] = currentNode;


	cout <<"Available size is: "<< available.size() << endl;
	cout << currentNode->N->getId() << " " << destID << endl;
	cout << "available size: " << available.size()<< endl;


	while (((currentNode->N)->getId() != destID)
			&& (!available.empty())) {		
		//add nbrs
		makeNbrAvailable(currentNode);
		//remove closest from available to finished
		cout << "Available size is: " << available.size() << endl;
		finishNode(currentNode);
		//get closest
		currentNode = findClosestAvailable();
		cout << currentNode->N->getId() << endl;
	}	
	cout << "finished dijkstra\n";
}

DjNode * myDijkstra::findClosestAvailable()
{
	DjNode* topNode = pq.top();
	pq.pop();
	return topNode;
}
