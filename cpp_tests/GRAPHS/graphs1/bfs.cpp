#ifndef BFS
#define BFS

#include <iostream>
#include <queue>
#include "adjacency_list.h"

using namespace rupank;

namespace rupank{


class bfs{
private:
	std::vector <bool> discovered;
	std::vector <bool> processed;
	std::vector <int> parent;
	std::queue <int> q;
public:
	bfs(graph* g);
	void process_vertex_early(int v);
	void process_vertex_late(int v);
	void process_edge(int x, int y);
	void the_bfs(graph * g, int start);
	void find_path(int start, int end);
};

bfs::bfs(graph * g){
	discovered.reserve(g -> nvertices + 1);
	processed.reserve(g -> nvertices + 1);
	parent.reserve(g-> nvertices + 1);
}

void bfs::the_bfs(graph * g, int start){
	q.push(start);
	discovered[start] = true;
	
	while(!q.empty()){
		int v = q.front();
		q.pop();
		process_vertex_early(v);
		edgenode * p = g -> edges[v];

		while(p != NULL){

			int y = p -> y;

			if(processed[y] == false || g -> directed){
				process_edge(v,y);
			}

			if(discovered[y] == false){
				q.push(y);
				discovered[y] = true;
				parent[y] = v;
			}

			p = p-> next;
		}

	process_vertex_late(v);
	processed[v] = true;

	}
}

void bfs::process_vertex_early(int v){
	cout << "Vertex"  << v << "is now being processed \n";
}
void bfs::process_vertex_late(int v){
	cout << "Vertex" << v << "has been processed \n";
}
void bfs::process_edge(int x, int y){
	cout << x << " -- " << y << "is being processed \n";
}

void bfs::find_path(int start, int end){
	if(start == end || end == -1){
		cout << start << " ";
	}
	else{
		find_path(start, parent[end]);
		cout << end << " ";
	}
}

}

#endif