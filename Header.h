#pragma once
#include <iostream>
#include <list>
namespace grpahc {
	struct Graph {
	private:
		int v;
		std::list<int>* adj;
	public:
		Graph(int v);
		~Graph();
		void connected_components();
		void dfs_func(int n, bool visited[]);
		void addEdge(int n, int w);
	};
	void startprog();
}
