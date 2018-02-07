#include <iostream>
#include <vector>
#include <random>

using namespace std;
class QuickSort{
public:

	void sort(vector<int> &);
	QuickSort();

private:

	vector<int>& shuffle(vector<int> &);
	int partition(vector<int> &, int lo, int hi);
	void sort(vector<int> &, int lo, int hi);

};

QuickSort::QuickSort(){} //constructor


vector<int>& QuickSort::shuffle(vector<int>& a){
	random_device rd;     //obtain random number from hardware
	mt19937 eng(rd());    // seed the generator

	for(int i = 0; i < a.size() - 1; i++){
		uniform_int_distribution<> distr(0,i);  //define range
		int random = distr(eng);  //generate the number
		swap(a[i], a[random]);
	}
	return a;

}


int QuickSort::partition(vector<int> & a, int lo, int hi){
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


void QuickSort::sort(vector<int> &a, int lo, int hi){


	if(hi <= lo) return;

	int m = a.size()/2;
	
	swap(a[lo], a[m]);

	int j = partition(a, lo, hi);


	sort(a, lo, j-1);

	sort(a, j+1, hi);
}


void QuickSort::sort(vector<int> & a){
	a = shuffle(a); //suffle needed
  cout << a[0] << endl;
	sort(a,0,a.size()-1);
}

int main(){
  QuickSort q1;

  vector<int>k = {12,35,12,45,65,89,74,32,78};
 
  q1.sort(k);


  for(auto x: k)
    cout << x << " ";
}