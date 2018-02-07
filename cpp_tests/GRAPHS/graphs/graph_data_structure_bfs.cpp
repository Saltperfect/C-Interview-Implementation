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
	friend class bfs;
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

	friend class bfs;
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

class bfs{
// private:
public:
	vector <bool> proccesed;  //contains info if completed
	vector <bool> discovered; // contains info if discoved
	vector <int> parent; //contains the parent of all nodes
	queue <int> q; 
public:
	bfs(graph * g);
	void process_vertex_early(int v);
	void process_vertex_late(int v);
	void process_edge(int x,int y);
	void the_bfs(graph * g, int start);  //the main bfs
	void find_path(int start, int end);
};

bfs::bfs(graph *g){
	proccesed.reserve(MAXV);
	discovered.reserve(MAXV);
	parent.reserve(MAXV);
	for(int i = 1; i <= g->nvertices; i++){
		proccesed[i] = false;
		discovered[i] = false;
		parent[i] = -1;
	}
}
void bfs::process_edge(int x, int y){
	cout << x  << " -- "<< y << "is proccesed edge" << endl;
}
void bfs::process_vertex_early(int v){
	cout << v << " is being visited" << endl;
}
void bfs::process_vertex_late(int v){
	cout << v << " has been visited" << endl;
}


void bfs::the_bfs(graph * g, int start){
	int v;  //the vertex
	int y;  // the child // parent[y] = v;

	edgenode * p;

	q.push(start);
	discovered[start] = true;

	while(!q.empty()){
		v = q.front();
		q.pop();
		process_vertex_early(v);
		p = g -> edges[v];

		while(p!= NULL){
			y = p -> y;
			if(proccesed[y] == false || g -> directed){  // important point after this funtion
				process_edge(v, y);
			}
			if(discovered[y] == false){
				q.push(y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p-> next;
		}

		process_vertex_late(v);	
		proccesed[v] = true;

	}

}

void bfs::find_path(int start, int end){
	if(start == end || end == -1){
		cout << start << "-" ;
	}
	else{
		find_path(start, parent[end]);
		cout << end << "-";
	}
}

// the condition written tells if v's neighbours are not processed 


int main(){
/*	graph g1(true);
	g1.read_graph(true);
	g1.print_graph();*/
	graph g2(false);
	g2.read_graph(false);
	g2.print_graph();
	g2.detail();

	bfs b1(&g2);
	b1.the_bfs(&g2, 1);
}
