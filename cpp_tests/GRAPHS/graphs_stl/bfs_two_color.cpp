#include <bits/stdc++.h>
using namespace std;

vector < vector<int> > adj;
vector <bool> discovered, processed;
vector <int> parent;
vector <int> color;
queue <int> q;

int main(){
	int nvert, nedge;
	cin >> nvert >> nedge;
	adj.resize(nvert + 1);
	discovered.resize(nvert + 1);
	color.resize(nvert + 1);
	processed.resize(nvert + 1);
	parent.resize(nvert + 1);

	for(int x, y, i = 0; i < nedge; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int src;
	cin >> src;

	q.push(src);
	discovered[src] = 1;
	parent[src] = -1;
	color[src] = 1;

	while(!q.empty()){

		auto v = q.front();
		q.pop();
		processed[v] = 1;

		//vertex early process

		auto ar = adj[v];

		for(auto h: ar){
			if(!discovered[h]){
				q.push(h);
				discovered[h] = 1;
				parent[h] = v;
				color[h] = -1 * color[v];
			}
			else{
				if(color[h] == color[v]){
					cout << "np";
					return 0;
				}
			}
		}
		// vertex late process
	}
	cout << "p";
	return 0;
}