#pragma once
#include "DjMap.h"
#include <iostream>
#include <fstream>
#include "types.h"
using namespace std;



request getQuery(DjMap* djptr) {
	request r1;
	do {
		cout << "Enter ID of starting point \n";
		cin >> r1.root;
		cout << "Enter ID of destination point \n";
		cin >> r1.dest;
	} while (!djptr->isValidRequest(r1));

	return r1;
}


DjMap* handleGraphInput(char* filename) {
	unsigned edge_num, node_num, temp_id, nodeA, nodeB;
	float temp_x, temp_y;
	DjMap * dj_ptr;


	fstream ifile(filename);

	if (!ifile.is_open()) {
		cout << filename << " could not be opened\n";
		return NULL;
	}
	ifile >> node_num;
	ifile >> edge_num;
	dj_ptr = new DjMap(node_num, edge_num);


	for (unsigned int i=0; i < node_num; i++) {
		ifile >> temp_id;
		ifile >> temp_x;
		ifile >> temp_y;
		dj_ptr->addNode(new node(temp_id,temp_x, temp_y));
	}
	cout << "finished adding nodes(" << dj_ptr->getNodeCount() << ")\n";
	for (unsigned int i=0; i < edge_num; i++) {	
		ifile >> nodeA;
		ifile >> nodeB;
		dj_ptr->addConnection(nodeA,nodeB);
	}
			
	cout << "finished adding edges \n";
	cout << "closing file: " << filename<< endl;
	ifile.close();
	return dj_ptr;
}
