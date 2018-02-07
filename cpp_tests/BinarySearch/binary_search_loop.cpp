	#include <iostream>
	#include <string>

	using namespace std;

	class binary_search{
  	public:
  		binary_search(){};
  		int bin_search(bool* arr, int size);
	};
	int binary_search::bin_search(bool* arr, int size){
		int lo = 0; int hi = size - 1;
  	while(lo < hi){
	  	int mid = lo + (hi-lo)/2;
	  	if(arr[mid] != true)
	  		lo = mid + 1;
	  	else if(arr[mid] == true)
	  		hi = mid;
		}
		if(arr[lo] == false)
			return -1;
		else 
			return lo;
  }
	int main(){
  	bool list[10] = {0,0,0,0,0,0,0,1,1,1};
  	binary_search b1;
  	cout << b1.bin_search(list, 10) << endl;
	}