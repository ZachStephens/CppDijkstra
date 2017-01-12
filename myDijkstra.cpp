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
		//available
	while (!dnodes.empty()) {
		DjNode* tmp = dnodes.back();
		dnodes.pop_back();
		delete tmp;
	}
	
}

void myDijkstra::finishNode(DjNode * currentNode) {
	available.erase(currentNode->N->getId());
	finished[currentNode->N->getId()]=currentNode;
	//cout << "Finishing" << currentNode->N->getId() << endl;

}

void myDijkstra::writePath(DjNode * currentNode)
{
	DjNode* tmpNode = currentNode;
	vector<DjNode*> pathVector;
	while(tmpNode != NULL){
		pathVector.push_back(tmpNode);
		tmpNode = tmpNode->prevHop;	
	}
	while (!pathVector.empty()) {
		cout << pathVector.back()->N->getId()<< ", ";
		pathVector.pop_back();
	}
		
}

void myDijkstra::putNode(DjNode * node1)
{
	unsigned int i = 0;
	unsigned int j,k;

	if (closest.empty()){
		closest.push_front(node1);
		}	
	else
	{
		if (node1->total_dist < closest.front()->total_dist) {
			closest.push_front(node1);
			return;
		}

		j = closest.size() - 1;
		k = (j-i) / 2 + i;
		while (i<j) {
			if (node1->total_dist < closest[k]->total_dist) 
				j = k - 1;
			else 
				i = k + 1;
		
			k = ((j - i) / 2) + i;
		}
		if (node1->total_dist < closest[i]->total_dist)
		{
			closest.insert(closest.begin() + i, node1);	
		}
		else{
			if (closest.size()==(i+1)) 
				closest.push_back(node1);
			else
				closest.insert(closest.begin()+(i+1), node1);
		}
			
	}
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
			//cout << "Adding " << tempID << endl;
			available[tempID] = tmpDN;
			putNode(tmpDN);
			dnodes.push_back(tmpDN);
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


	//cout <<"Available size is: "<< available.size() << endl;
	cout << currentNode->N->getId() << " " << destID << endl;
	//cout << "available size: " << available.size()<< endl;


	while (((currentNode->N)->getId() != destID)
			&& (!available.empty())) {		
		//add nbrs
		makeNbrAvailable(currentNode);
		//remove closest from available to finished
		//cout << "Available size is: " << available.size() << endl;
		finishNode(currentNode);
		//get closest
		currentNode = findClosestAvailable();
		//cout << currentNode->N->getId() << endl;
	}
	cout << "out of while\n";
	if ((currentNode->N)->getId() == destID)
		writePath(currentNode);

	cout << "finished dijkstra\n";
}

DjNode * myDijkstra::findClosestAvailable()
{
	DjNode* tmp = closest.front();
	closest.pop_front();
	return tmp;
}
