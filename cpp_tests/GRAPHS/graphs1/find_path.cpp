#include "adjacency_list.h"
#include "bfs.h"

using namespace rupank1;

bfs * b6 = NULL;

void find_path(int start, int end){
	if(start == end || end == -1){
		std::cout << start << " ";
	}
	else{
		find_path(start, b6 -> parent[end]);
		std::cout << end << " ";
	}
}

void find_path_util(bfs* b, int x, int y){
	b6 = b;
	find_path(x, y);
}


int main(){
	graph g1;
	g1.read_graph();
	g1.print_graph();

	bfs b1(& g1);
	b1.the_bfs(&g1 , 1);
	int x, y;
	std::cin >> x >> y;
	find_path_util(&b1 , x, y);
}