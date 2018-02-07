#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Selectionsort{
  public:
    Selectionsort();
    void sort(vector<int>&, int size);
};
	Selectionsort::Selectionsort(){}
  void Selectionsort::sort(vector<int>& a, int size){
      for(int i=0; i<size; i++){
        int min = i;
      	for(int j=i+1; j<size; j++){
	        if(a[j] < a[min])
	          min = j;
	      }
	      swap(a[i], a[min]);
      }
    }
int main(){
  Selectionsort s1;
  vector<int>k = {12,45,65,89,74,32,45};
  int s = 7;
  s1.sort(k,s);
  for(auto x: k)
  	cout << x << " ";
}
