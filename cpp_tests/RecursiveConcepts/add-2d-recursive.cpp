#include <iostream>
#include <vector>
using namespace std;

int add_recursive(vector < vector<int> >, int size){
  if (size == 0) return v[0][0];
  else{
    int i,j; 
  	int rest;
    i = size-1;
    j = size-1;
    while(i == size-1 || j == size-1){
      int rest += v[i][j]
      i--;
      j--;
    }
  }
  return add_recursive(v, size-1) + rest;
}

int main(){
  int size, n;
  cin >> size;
  size = n;
  vector< vector<int> > v(n, vector<int>(n));
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		cin >> v[i][j];
  	}
  }
  add_recursive(vector< vector<int> > v(n, vector<int>(n)), size);
}