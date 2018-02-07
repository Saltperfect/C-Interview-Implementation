#include <bits/stdc++.h>

using namespace std;

vector < list <int> > adj;
vector < list <int> > adjr;
vector < pair <int, int > > counter1;
vector <bool> mark;
vector <bool> mark2;
vector <int> parent;
vector <int> parent2;

int c1 = 0;


void dfs(int i){
	mark[i] = 1;
	auto k = adj[i];
	list <int> :: iterator it;
	for(it = k.begin(); it != k.end(); it++){
		if(!mark[*it]){
			mark[*it] = 1;
			parent[*it] = i;
			dfs(*it);
		}
	}
	c1++;

	counter1[i].first = i;
	counter1[i].second = c1; // the i is completely processed
}

void dfs2(int i){
	mark2[i] = 1;
	auto k = adjr[i];

	list <int> :: iterator it;
	for(it = k.begin(); it != k.end(); it++){
		if(!mark2[*it]){
			mark2[*it] = 1;
			parent2[*it] = i;
			dfs2(*it);
		}
	}
}

int main(){
	int m,n;
	cout << "Edges then Verticies";
	cin >> m >> n;
	mark.resize(n + 1);
	mark2.resize(n + 1);
	adj.resize(n + 1);
	adjr.resize(n + 1);
	parent.resize(n + 1);
	parent2.resize(n + 1);
	counter1.resize(n + 1);
	for(int i = 1, x, y; 	i <= m; ++i){
		cin >> x >> y;
		adj[x].push_front(y);
	}

	cout << "the graph" << endl;
	int s = 0;
	for(auto x: adj){
		list <int> :: iterator it;
		cout << s << " --- "; 
		for(it = x.begin(); it!= x.end(); it++){
			cout << *it << "  ";
		}
		cout << endl;
		s++;
	}


	for(int i = 1; i <= n ; i ++){
		if(!mark[i]){
			dfs(i);
		}
	}

	cout << "the parent tree after 1st dfs" << endl;
	for(int i = 1 ; i <= n; i++ ){
		cout << i << " -- " << parent[i] << endl;
	} 


	for(int i = 1; i <= n; i ++){
		auto l = adj[i];
		while(!l.empty()){
			int p = l.front();
			adjr[p].push_front(i);
			l.pop_front(); 
		}
	}

	cout << "the graph" << endl;
	int f = 0;
	for(auto x: adjr){
		list <int> :: iterator it;
		cout << f << " --- "; 
		for(it = x.begin(); it!= x.end(); it++){
			cout << *it << "  ";
		}
		cout << endl;
		f++;
	}

	std::sort(counter1.begin(), counter1.end(), [](auto &a, auto &b){return a.second > b.second;});

	auto it = counter1.begin();
	counter1.insert(it, {0, 0});
	for(auto x: counter1){
		cout << x.first << " -- " << x.second << endl;
	}

	for(int i = 1; i <= n; i++){
		int t = counter1[i].first;
		if(!mark2[t]){
			dfs2(t);
		}
	}

	cout << "the parent tree after 2st dfs" << endl;
	for(int i = 1 ; i <= n; i++){
		cout << i << " -- " << parent2[i] << endl;
	} 
	vector <bool> marku(n+1, 0);
	for(int i = 1; i<= n ; i++){
		if(!marku[i]){
			while(i != 0){
				cout << i << " -- ";
				marku[i] = 1;
				i = parent2[i];
			}
			cout << endl;
		}
	}
}
