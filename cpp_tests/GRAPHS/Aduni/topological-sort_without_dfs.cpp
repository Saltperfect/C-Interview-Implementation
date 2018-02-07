	#include <bits/stdc++.h>
	using namespace std;

	vector< list <int> > adj;
	queue <int> qq;
	vector <int> sorted;
	vector <int> indeg;


	int main(){

		int m, n;
		cout << "edges then vertex";
		cin >> m >> n;
		adj.resize(n + 1);
		indeg.resize(n + 1,0);
		for(int i = 0, x, y; i < m; ++i ){
			cin >> x >> y;
			adj[x].push_front(y);
		}
		cout << "Hello" << endl;

		for(int i = 1; i <= n; i++){
			auto x = adj[i];
			list <int> :: iterator it;
			for(it = x.begin(); it != x.end(); it++){
				indeg[*it]++;
			}
		}

		cout << "Hello2" << endl;

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
		cout << "in degree edge list" << endl;
		for(int i = 1; i<= n; i++){
			cout << i << " -- "<< indeg[i] << endl;
		}

		int sum = 0;
		for(auto x : indeg) sum += x;
		while(sum > ((-1)*n)){

			for(int j =1; j <= n; j++){
				if(indeg[j] == 0){
					qq.push(j);
				}
			}

			while(!qq.empty()){

				int p = qq.front();
				qq.pop();
				indeg[p] = -1;
				sorted.push_back(p);

				list <int> :: iterator kt;

				for(kt = adj[p].begin(); kt != adj[p].end(); kt++){
					indeg[*kt] --;
				}
			}

			cout << "---------------------!";

			for(int i = 1; i<= n; i++){
				cout << endl << i << " -- "<< indeg[i] << endl;
			}
			
			cout << "----------------------!";
			sum = 0;
			for(auto x : indeg) sum += x;
			cout << sum << endl;

		}

		cout<< endl << "the topological sort" << endl;
		for(auto x: sorted){
			cout << x << " -- ";
		}

	}