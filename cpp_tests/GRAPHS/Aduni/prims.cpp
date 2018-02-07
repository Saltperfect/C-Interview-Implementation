// prims algorithm the main error which I was commiting was to mark the node when seen but remember every time don't just follow the 
//convention. Here we have completed visiting the node if the edge is drawn...
//Written on 7th Feb 2018 with love and care and sweat by rupank and edited by Aditya

#include <bits/stdc++.h>

 struct compr  
 {  
   bool operator()(const std::pair <int, int> & l, const std::pair <int, int> & r)  
   {  
       return l.second > r.second;  
   }  
 };

std::vector< std::list < std::pair < int, int > > > adj;
std::priority_queue < std::pair <int, int>, std::vector < std::pair <int, int> > , compr > mpq;
std::priority_queue < std::pair <int, int>, std::vector < std::pair <int, int> > , compr > mpq1;
std::vector <bool> marked; 



int main(){
	int n, m;
	std::cin >> n >> m;
	adj.resize(n + 1);
	marked.resize(n+ 1, 0);
	for(int i = 0, x, y, l; i < m; ++i){
		std::cin >> x >> y >> l;
		adj[x].push_front({y,l});
		adj[y].push_front({x,l});
	}
	int s; // start node to scan from
	std::cin >> s;
	mpq.push({s,0});

/*	std::cout << "the graph";
	int u = 0;
	for(auto x: adj){
	std::cout << u << std::endl;
		for(auto &l : x){
			std::cout << l.first << " -- " << l.second << std::endl;
		}
	u++;
	} */

	int su = 0; // sum of the boolean marked array
	int len = 0;
	int lop = 1;
	while(!mpq.empty()){
		auto f = mpq.top();
		std::cout << "lop" << lop << std::endl;
		std::cout << f.first << " top element " << f.second << std::endl;
		mpq.pop();
		if(marked[f.first]) continue; 
		marked[f.first] = 1;

		mpq1 = mpq;
		while(!mpq1.empty()){
			auto ds = mpq1.top();
			std::cout << ds.first  << " all elements " << ds.second << std::endl;
			mpq1.pop();
		}
		std::cout << "markers" << std::endl;
		for(auto x: marked){
			std::cout << x << std::endl;
		}
		std::cout << "markere" << std::endl;

		len += f.second;
		int curr = f.first;
		auto d = adj[curr];  // list of all the adjacent vertices from curr the top element of min heap
		for(const auto &itpair: d){
			if(!marked[itpair.first]){
				mpq.push(itpair);
			}
		}

		std::cout << su << std::endl; 
		lop++;
	}
	
	std::cout << len;

}