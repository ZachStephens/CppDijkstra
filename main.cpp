#include "dijkstraRedo.h"



int main(int argc, char** argv) {
	/*handle input
		read in map
			-nodes
			-edges
		build map
	*/
	//input filename of 
	request pathRequest;

	if (argc < 2) {
		cout << "Too few Arguents"<< endl;
		return -1;
	}
	else {
		cout << "Attempting to open "<<argv[1] << " " << endl;
	}
	DjMap* djptr = handleGraphInput(argv[1]);

	pathRequest = getQuery(djptr);
	
	//perform dijkstra
	//path closestRoute(map,request)



	//handle output
	return 0;
}