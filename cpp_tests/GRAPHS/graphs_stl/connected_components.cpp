#include <bits/stdc++.h>
using namespace std;

vector < list <int> > adj;
vector <bool> mark;
vector <int> parent;
stack <int> stk;


void dfs(int i){
	mark[i] = 1;
	auto k = adj[i];

	list <int> :: iterator it;
	stk.push(i);                                 // push the elements in one partof graph in undirected graph in one stack to be recognized as one component 
	for(it = k.begin(); it != k.end(); it++){   // it is not necessary that the elements of components are cyclic
		if(!mark[*it]){
			mark[*it] = 1;
			parent[*it] = i;
			dfs(*it);
		}
	}

}

int main(){
	int m,n;
	cout << "Edges then Verticies";
	cin >> m >> n;
	mark.resize(n + 1);
	adj.resize(n + 1);
	parent.resize(n + 1);
	for(int i = 1, x, y; 	i <= m; ++i){
		cin >> x >> y;
		adj[x].push_front(y);
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

	int compr = 0;
	for(int i = 1; i <= n ; i ++){

		
		if(!mark[i]){
			dfs(i);
			compr++;
			cout  << endl << "component number--" << compr << "is";
			while(!stk.empty()){           // empty the stack here and the resulting is the one component.
				cout << " -- " << stk.top();
				stk.pop();
			}
			
		}
	}

	cout << endl << "the parent tree" << endl;
	for(int i = 1 ; i <= n; i++ ){
		cout << i << " -- " << parent[i] << endl;
	} 

}