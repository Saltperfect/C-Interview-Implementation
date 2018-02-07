#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

#include <iostream>
#include <vector>

using namespace std;

namespace rupank{

class edgenode{
public:
	int y;
	edgenode* next;
	int weight;

	friend class graph;
	friend class bfs;
};
class graph{
public:  
	vector <edgenode*> edges;
	vector <int> degree;
	int nvertices;
	int nedges;
	bool directed;
public:
	graph();
	void read_graph();
	void insert_egde(int x, int y);
	void print_graph();
	void details();

	friend class bfs;
};

graph::graph():nvertices(0),nedges(0){
	cout << "What graph do you wanna make today? \n Type 1 for directed or otherwise \n";
	cin >> directed;
}

void graph::read_graph(){
	int x, y;
	cout << "How many vertices are you going to have - ";
	cin >> nvertices;
	edges.reserve(nvertices+4);
	degree.reserve(nvertices+4);
	cout << "How many edges are you going to have in " << nvertices << " 	vertex graph - ";
	cin >> nedges;
	for(int i = 1; i <= nedges; i ++){
		cout << "Type the edges you want to add(Please relax with the labeling and use lowest natural numbers for distict labels)";
		cin >> x;
		cout << "to";
		cin >> y;
		insert_egde(x,y);
		cout << "edge added \n";
	}
}

void graph::insert_egde(int x, int y){
	edgenode* p = new edgenode;
	p -> y = y;
	p -> weight = 0;
	p->next = edges[x];  //attached to the head
	edges[x] = p;  // attached to the head
	degree[x] ++;
	if(!directed){
		edgenode *q = new edgenode;
		q -> y = x;
		q->next = edges[y];
		edges[y] = q;
		degree [y] ++;
	}
}
void graph::print_graph(){
	for(int i = 1; i <= nvertices ; i++)
	{
		edgenode* p = edges[i];

		if(p != NULL){
			cout << i << "--";
		
			while(p != NULL){
				cout << p -> y << " +";
				p = p -> next;
			}
			cout << endl;
		}
	}
}

void graph::details(){
	cout << "Number of vertices - " << nvertices << "\nNumber of edges - " << nedges << "\nIs directed ?" << directed << endl;
	cout << "degree list: \n";
	
	for(int i = 1; i <= nvertices; i++){
		if(edges[i]!= NULL){
			cout << i << " degree is " << degree[i] << endl;
		}
	}
}


}
#endif
