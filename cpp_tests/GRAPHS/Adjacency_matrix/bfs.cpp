#include <bits/stdc++.h>

using namespace std;

vector < vector <bool> > adj;
vector <bool> marked;
vector <int> parent;
queue <int> qq;

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
	qq.push(start);
	parent[start] = -1;
	marked[start] = 1;

	while(!qq.empty()){

		int u = qq.front();
		qq.pop();
		auto adju = adj[u];
		
		for(int i = 1; i<= n; i++){
			if(adju[i] == 1){
				if(marked[i] != 1){
					qq.push(i);
					marked[i] = 1;
					parent[i] = u;
				}
			}
		}
	}
	int j = 0;
	for(auto x: parent){
		cout << j << " -- " << x << endl;
		j++;
	}

} 