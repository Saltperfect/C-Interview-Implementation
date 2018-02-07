#include <bits/stdc++.h>
using namespace std;

vector < list <int> >adj;
vector <bool> marked;
vector < pair <int, int> > t; // the vector to store the node and finish time.

int c = 0; // time to finish processing the node
void dfs(int i){
	marked[i] = 1;
	auto k = adj[i];
	list <int> :: iterator it;

	for(it = k.begin(); it != k.end(); it++){
		if(!marked[*it]){
			marked[*it] = 1;
			dfs(*it);
		}
	}
	c++;
	t[i].first = i;
	t[i].second = c;
}

int main(){
	int m , n;
	cout << " e then v ";
	cin >> m >> n;
	adj.resize(n + 1);
	marked.resize(n + 1, 0);
	t.resize(n + 1);
	for(int i=1, x, y; i <=m ; ++i){
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

	for(int i = 1; i <= n; ++i){
		if(!marked[i]){
			dfs(i);
		}
	}
	cout << "seg after dfs";
	
	std::sort(t.begin(), t.end(), [](auto &left, auto &right) {return left.second < right.second;});

	for(auto x: t){
		cout << x.first << " -- " << x.second << endl;
	}


}