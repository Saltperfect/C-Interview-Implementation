#include <bits/stdc++.h>
using namespace std;

vector < list <int> > adj;
vector < pair <int , int > > counter;
vector <bool> mark;
vector <int> parent;

int c = 0;
int c2 = 0;

void dfs(int i){
	mark[i] = 1;
	auto k = adj[i];

	c++;

	counter[i].first = c; //the i has been started to be processed

	list <int> :: iterator it;
	for(it = k.begin(); it != k.end(); it++){
		if(!mark[*it]){
			mark[*it] = 1;
			parent[*it] = i;
			dfs(*it);
		}
	}
	c2++;

	counter[i].second = c2; // the i is completely processed
}

int main(){
	int m,n;
	cout << "Edges then Verticies";
	cin >> m >> n;
	mark.resize(n + 1);
	adj.resize(n + 1);
	parent.resize(n + 1);
	counter.resize(n + 1);
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


	for(int i = 1; i <= n ; i ++){
		if(!mark[i]){
			dfs(i);
		}
	}

	cout << "the parent tree" << endl;
	for(int i = 1 ; i <= n; i++ ){
		cout << i << " -- " << parent[i] << endl;
	} 
	cout << "the final show:- the times" << endl;
	int i = 1; 
	for(auto x : counter){
		cout << i << " -- " << x.first << " -- " << x.second << endl;
		i++;
	} 
}