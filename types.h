#pragma once
#include <iostream>

typedef struct djnode {
	node* N;
	struct djnode * prevHop;
	float total_dist;
}DjNode;

typedef struct {
	unsigned int root;
	unsigned dest;
}request;

