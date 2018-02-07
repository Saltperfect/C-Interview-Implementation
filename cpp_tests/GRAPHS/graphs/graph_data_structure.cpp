#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

# define MAXV  1000

class edgenode{
private:
	int y; // adjacency info
	int weight; // weight if any
	edgenode* next; // pointer to the next node

	friend class graph;
};

class graph{
private:
	vector <edgenode*> edges;
	vector <int> degree;
	int nvertices;
	int nedges;
	bool directed;
public:
	graph(bool directed);
	void read_graph(bool directed);
	void insert_edge(int x, int y, bool directed);
	void print_graph();
	void detail();
};


graph::graph(bool directed):nvertices(0),nedges(0),directed(directed){
	edges.reserve(MAXV);
	degree.reserve(MAXV);
}

void graph::read_graph(bool directed){
	int m; //number of edges
	int x, y;
	cout << "number of vertices" << "number of edges";

	cin >> nvertices >> m;
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		insert_edge(x,y,directed);
	}

}
void graph::insert_edge(int x, int y, bool directed){
	edgenode* p = new edgenode; //temperory edgenode
	p -> y = y;
	p->weight = 0;
	p -> next = edges[x];

	edges[x] = p;  //p attached to the head

	degree[x] ++;

	if(directed == false){
		edgenode * q = new edgenode;
		q -> y = x;
		q -> weight = 0;
		q -> next = edges[y];

		edges[y] = q;

		degree[y] ++;

		nedges ++;
		}

	else{
		nedges ++;
	}
}
void graph::detail(){
	cout << "Is directed ?" << directed << endl;
	cout << "number of vertices" << nvertices << endl;
	cout << "number of edges" << nedges << endl;
	cout << "degree list:";
	
	for(int i = 1; i <= MAXV; i++){
		if(edges[i]!= NULL){
			cout << i << " degree is " << degree[i] << endl;
		}
	}
}

void graph::print_graph(){

	for(int i = 1; i <= MAXV ; i++)
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


int main(){
/*	graph g1(true);
	g1.read_graph(true);
	g1.print_graph();*/
	graph g2(true);
	g2.read_graph(true);
	g2.print_graph();
	g2.detail();
}
