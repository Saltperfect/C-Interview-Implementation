#include <iostream>
#include <vector>

using namespace std;
class QuickSort3way{
public:
	QuickSort3way(); 
	void sort(vector<int> & a, int lo, int hi);
};
QuickSort3way::QuickSort3way(){}

void QuickSort3way::sort(vector<int> & a, int lo, int hi){
	if(hi<= lo) return;

	int it = lo; int gt = hi;

	int v = a[lo];
	int i = lo;

	while(i <= gt ){           //if i and gt points some element than that 
														//means that elemets has to be cheacked.

		if (a[i] < v) swap(a[i++], a[it++]);
		else if (a[i] > v) swap(a[i], a[gt--]);
		else i++;

	}
	
	sort(a,lo, it-1);
	sort(a, gt+1, hi);

}

int main(){
  QuickSort3way q1;
  vector<int>k = {45,12,65,89,74,32,45};
  q1.sort(k,0,6);
  for(auto x: k)
  	cout << x << " ";
}