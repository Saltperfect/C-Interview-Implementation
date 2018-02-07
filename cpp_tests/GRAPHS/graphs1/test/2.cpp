#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > adj;
vector <int> stp, vis;

bool this_is_uncool = 0;

void dfs(int i, int cnt){
	if(vis[i]){
		int len = cnt - stp[i];
		if(len % 2 == 1){
			this_is_uncool = 1;
		}
		return;
	}
	vis[i] = 1;
	stp[i] = cnt;
	for(auto j: adj[i]){
		dfs(j, cnt+1);
	}
}

main(){
	int n, m;
	cin >> n >> m;
	adj.resize(n+1);
	vis.resize(n+1);
	stp.resize(n+1);
	for(int i = 0, x, y; i < m; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	if(this_is_uncool) puts("no");
	else puts("yes");
}