#include <iostream>
#include <vector>
#include "graph.h"
#include <ctime>

#define MAX_INT 2147483647

using namespace std;


int main() {
	int n;
	cout<<"Number of vertexes>>";
	cin>>n;
	adjacencyMatrix graph;
//	graph.fillManual();
	graph.fillRandom(n);
	graph.showMatrix();

	cout<<"\nEnter index of vertex: ";
	cin>>n;
	int* paths_arr = new int[graph.vertex];
	for (int i=0; i<graph.vertex; i++)
	{
		if (i==n)
			paths_arr[i]=0;
		else 
			paths_arr[i]=MAX_INT;
	}
	int index=0;
	vector<int>queue;
	vector<int>neig;
	vector< vector<int> >paths;
	for (int i=0; i<graph.vertex; i++)
	{
		paths.push_back(queue);
	}
	queue.push_back(n);
	clock_t t = clock();
	do
	{
	
		neig = graph.adjacents(queue[index]);
		
		for (int i=0; i<neig.size(); i++)
		{
			if  (paths_arr[neig[i]] > (paths_arr[queue[index]]+graph.relation[queue[index]][neig[i]]) )
			{
				paths[neig[i]]=paths[queue[index]];
				paths[neig[i]].push_back(queue[index]); 
				queue.push_back(neig[i]);
				
				paths_arr[neig[i]] = paths_arr[queue[index]] + graph.relation[queue[index]][neig[i]];
			} 
		}
		index++;
	}while(index<queue.size());

	cout<<"\nspent time: "<<clock()-t<<endl;
	for (int i=0; i<graph.vertex; i++)
	{
		cout<<endl;
		printf("%5i to %5i has %5i weigt: %i", n, i, paths_arr[i], n);
		for (int j=1; j<paths[i].size(); j++)
		{
			cout<<" -> ";
			cout<<paths[i][j];
		}
		cout<<" -> "<<i;
	}
	
	delete[] paths_arr;
	

	return 0;
}

