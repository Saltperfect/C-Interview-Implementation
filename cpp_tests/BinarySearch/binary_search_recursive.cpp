		#include <iostream>

		using namespace std;
		int bin_search(int (& arr)[10], int low, int hi, int target){
			if(low > hi)
				return -1;
			else{
				int mid = low + (hi-low)/2;
				if(arr[mid] < target)
					bin_search(arr, mid + 1, hi, target);
				else if(target < arr[mid])
					bin_search(arr, low, mid - 1, target);
				else
					return mid;
			}
		}
		int main(){
			int array[10] = {3,12,23,45,56,78,89,123,456,899};
			cout << bin_search(array, 0, 9, 123) << endl;
		}