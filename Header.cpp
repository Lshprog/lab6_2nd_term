#include "Header.h"

void grpahc::startprog()
{
	Graph g(7);
	g.addEdge(1, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(5,6);

	std::cout << "Following are connected components \n";
	g.connected_components();

}

grpahc::Graph::Graph(int v)
{
	this->v = v;
	adj = new std::list<int>[v];
}

grpahc::Graph::~Graph()
{
	delete[] adj;
}

void grpahc::Graph::connected_components()
{
	int totalconcomp = 0;

	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) 
		visited[i] = false;
	
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			dfs_func(i,visited);
			std::cout << "\n";
			totalconcomp++;
		}
	}
	std::cout << "total num of con comp = " << totalconcomp<<"\n";
	delete[] visited;
	return;
}

void grpahc::Graph::dfs_func(int i, bool visited[])
{
	visited[i] = true;
	std::cout << i<<" ";

	std::list<int>::iterator temp;

	for (temp = adj[i].begin(); temp != adj[i].end(); ++temp) {
		if (!visited[*temp]) {
			dfs_func(*temp,visited);
		}
	}
}

void grpahc::Graph::addEdge(int n, int w)
{
	adj[n].push_back(w);
	adj[w].push_back(n);
	
}
