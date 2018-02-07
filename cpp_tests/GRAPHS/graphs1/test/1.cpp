#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > adj;
vector <int> par, vis;

int main(){
	int n, m;
	cin >> n >> m;
	par.resize(n+1);
	adj.resize(n+1);
	vis.resize(n+1);
	for(int x, y, i = 0; i < m; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue <pair <int, int> > qq;
	int src;
	cin >> src;
	qq.push({src, -1});
	while(!qq.empty()){
		auto x = qq.front();
		qq.pop();
		if(vis[x.first]) continue;
		par[x.first] = x.second;
		vis[x.first] = 1;
		for(auto i: adj[x.first]){
			qq.push({i, x.first});
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << i << ' ' << par[i] << endl;
	}
}