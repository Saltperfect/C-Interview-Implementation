#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Shellsort{
	public:
	Shellsort();
	void sorter(vector<int>&, int size);
};
Shellsort::Shellsort(){}
void Shellsort::sorter(vector<int>& a, int size){
	//this sort is like insertion sort but with h steps going
	//backward in one time using kanau 3n+1 series
	int h = 1;
	while(h < size/3) h = 3*h +1;

	while(h>=1){
	  for(int i = h; i < size; i++){
	  	for(int j = i; j>= h; j -= h){
	  		if(a[j] < a[j-h]) swap(a[j-h], a[j]);	
	  	}
	  }
		h = h/3;
	}
}
int main(){
  Shellsort s1;
  vector<int>k = {12,45,65,89,74,32,45};
  int s = 7;
  // cout << "poo" << endl;
  s1.sorter(k,s);
  for(auto x: k)
  	cout << x << " ";}