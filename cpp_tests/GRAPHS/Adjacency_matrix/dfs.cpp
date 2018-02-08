#include <bits/stdc++.h>

using namespace std;

vector < vector <bool> > adj;
vector <bool> marked;
vector <int> parent;


void dfs(int p, int n){
	auto u = adj[p];
	marked[p] = 1;
	for(int i = 1; i <= n ;i++){
		if(adj[p][i] == 1){
			if(!marked[i]){
				marked[i] = 1;
				parent[i] = p;
				dfs(i, n);
			}
		}
	}
}


int main(){
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	marked.resize(n+1);
	parent.resize(n+1);
	for(int i = 1; i <=n; i++){
		adj[i].resize(n+1);
	}

	for(int i=1, x, y; i  <= m; i++){
		cin >> x >> y;
		adj[x][y] = 1;
	}
	cout << "enter the start node" << endl;

	int start;
	cin >> start;
	dfs(start, n);

	int j = 0;
	for(auto x: parent){
		cout << j << " -- " << x << endl;
		j++;
	}
}