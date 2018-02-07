#include <iostream>
#include <vector>
using namespace std;

int Linear_sum(const vector<int>& v,const int& n){
  if(n==1) return v[0];
  else return Linear_sum(v,n-1)+ v[n-1];
}
int main(){
  int n;
  int size;
  cin >> size;
  vector<int> v(size);
  for (int i = 0; i < size; ++i)
  {
  	cin >> n;
  	v[i] = n;
  }
  cout << Linear_sum(v,size) << endl;
}