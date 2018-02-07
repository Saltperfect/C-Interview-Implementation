#include <iostream>
#include <vector>
#include <random>

using namespace std;
class QuickSelect{
public:
	QuickSelect();
	int partition(vector<int> & a, int lo, int hi);
	int select(vector<int> &, int k);
};

QuickSelect::QuickSelect(){} //constructor


int QuickSelect::partition(vector<int> & a, int lo, int hi){
	int i = lo; int j = hi + 1;

	while(true){

		while(a[++i] < a[lo]){

			if(i >= hi) break; //cannot be greater than or equal to instead of == because in the next step 
													// it will then compare a[hi+1] and a[lo]
		}

		while(a[--j] > a[lo]){
			if(j <= lo) break;
		}

		if(i >= j) break; //while(true) break condition
			    
		swap(a[i], a[j]);
	}

	swap(a[lo], a[j]);

	return j;

}

int QuickSelect::select(vector<int> & a, int k){
	int lo = 0; int hi = a.size() - 1;
	while(lo< hi){
		int j = partition(a, lo, hi);
		if(j < k) lo = j + 1;
		else if (j > k) hi = j - 1;
		else break;
	}
	return a[k]; 
}


int main(){
  QuickSelect q1;

  vector<int>k = {8,3,1,7,4,5};
 
  cout << q1.select(k, 4) << endl;

}