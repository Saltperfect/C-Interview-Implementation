#include <iostream>
using namespace std;
class Insertion_sort{
  public:
  	Insertion_sort(int* arr, int n);
  	int* sort();
  private:
  	int *sortty;
  	int size;
};
Insertion_sort::Insertion_sort(int* arr, int n){
	sortty = arr;
	size = n;
}
int* Insertion_sort::sort(){
	for(int i=0; i<size; i++){
	  for(int j=i; j>=0; j--){
	    if(sortty[j]<sortty[j-1])
              swap(sortty[j], sortty[j-1]);
	  }
	}
        return sortty;
}
int main(){
  int game[6] = {9,4,6,7,3,8};
  Insertion_sort p(game,6);
  int* fp = p.sort();
  for (int i = 0; i < 6; ++i)
  {
  	cout << fp[i] << "  ";
  }
}
