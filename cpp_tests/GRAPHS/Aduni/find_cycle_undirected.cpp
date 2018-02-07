#include <bits/stdc++.h>
using namespace std;

vector < list <int> > adj;
vector <int> parent;
vector <bool> marker;
vector <int> backedges;

void dfs(int i){
	marker[i] = 1;
	auto p = adj[i];
	list <int> :: iterator it;
	for(it = p.begin(); it != p.end(); it++){
		if(!marker[*it]){
			marker[*it] = 1;
			parent[*it] = i;
			dfs(*it);
		}
		else{

			if(parent[i] != *it && backedges[*it] == 0){
				cout << endl << i << "to " << *it << "is a back edge.";
				backedges[i] = *it;
			}

		}
	}
}

int main(){
	int m, n;
	cout << "e then v";
	cin >> m >> n;
	marker.resize(n + 1);
	adj.resize(n + 1);
	parent.resize(n + 1);
	backedges.resize(n+ 1);
	for(int i = 1, x, y; 	i <= m; ++i){
		cin >> x >> y;
		adj[x].push_front(y);
		adj[y].push_front(x);
	}

	for(int i = 1; i <= n; i++){
		if(!marker[i]){
			dfs(i);
		}
	}


	cout << "the graph" << endl;
	int f = 0;
	for(auto x: adj){
		list <int> :: iterator it;
		cout << f << " --- "; 
		for(it = x.begin(); it!= x.end(); it++){
			cout << *it << "  ";
		}
		cout << endl;
		f++;
	}

	cout << "the parent tree" << endl;
	for(int i = 1 ; i <= n; i++ ){
		cout << i << " -- " << parent[i] << endl;
	} 
	for(int i =1; i <= n ; i ++){
		if(backedges[i] != 0){
			int g = i;
			cout << endl;
			while(g != backedges[i]){
				cout << g << " -- ";
				g = parent[g];
			}
			cout << g;
		}
	}
}