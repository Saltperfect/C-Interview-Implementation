#include <bits/stdc++.h>

std::vector < std::tuple <int,int,int> > adj; // the first is the vertex and the second is the distance
std::vector <int> unindat;
std::vector <int> h;

int find(int i){
	int p = i;
	while(unindat[p] != 0){
		p = unindat[p];
	}
	return p;
}
void unn(int x, int y){
	unindat[x] = y;
	h[y] = h[x] + 1;
}

int main(){
	int n, m;
	std::cout << "e then v";
	std::cin >> m >> n;
	unindat.resize(n+1);
	h.resize(n+1);
	for (int i = 1, x, y, l; i <= m; ++i){
		std::cin >> x >> y >> l;
		auto tu =	std::make_tuple(x,y,l);
		// std::make_tuple(y,x,l);
		adj.push_back(tu);
	}
	std::sort(adj.begin(), adj.end(), [](auto &a, auto &b){return std::get<2>(a) < std::get<2>(b);});

	for(auto x: adj){
		std::cout << std::get<0>(x) << " -- " << std::get<1>(x) << " -- " << std::get<2>(x) << std::endl;
	}

	for(auto x: adj){
		auto vertex1 = std::get<0>(x);
		auto vertex2 = std::get<1>(x);
		int vertex1_parent = find(std::get<0>(x));
		int vertex2_parent = find(std::get<1>(x));

		std::cout << "vertex  " << vertex1 << "--" <<  vertex2 << std::endl;
		std::cout << "vertex 1 & 2 parent" <<vertex1_parent << "--" <<vertex2_parent << std::endl;


		if(vertex1_parent != vertex2_parent){
			if(h[vertex1_parent] <= h[vertex2_parent]){
				unn(vertex1_parent, vertex2_parent);  //vert 1 ---> vert 2
				std::cout << vertex1 << " -- " << vertex2 << std::endl;
			}
			else{
				unn(vertex2_parent, vertex1_parent);  //vert 2 ---> vert1
				std::cout << vertex2 << " ++ " << vertex1 << std::endl;
			}
		}
	}
	std::cout << "The parent tree" << std::endl;
	int k = 0;
	for(auto x : unindat){
		std::cout << k  << " -- " << x << std::endl;
		k++;
	}
	std::cout << "The height" << std::endl;
	
	k = 0;
	for(auto x : h){
		std::cout << k  << " -- " << x << std::endl;
		k++;
	}

}