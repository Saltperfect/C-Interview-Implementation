#include <vector>
#include <iostream>

using namespace std;

class MergeSort{
	private:
		void merge(vector<int> &, vector<int> &, int lo, int mid, int hi);
		void sort(vector<int> &,vector<int> &, int lo, int  hi);
	public:
		MergeSort();
		void sort(vector<int> &);
};

MergeSort::MergeSort(){}
void MergeSort::merge(vector<int> & a, vector <int> & aux, int lo, int mid, int hi){
	if(a[mid] < a[mid+1]) return;
	for(int k = lo; k<= hi; k++)
		aux[k] = a[k];
	int i = lo; int j = mid + 1; int k = lo;
	while(k <= hi){
		if(i > mid) a[k++] = aux[j++];
		else if (j > hi) a[k++] = aux[i++];
		else if(aux[i] < aux[j]) a[k++] = aux[i++];
		else a[k++] = aux[j++];
	}
}
void MergeSort::sort(vector<int> & a, vector<int>& aux, int lo, int hi){
	if(hi <= lo) return;
	int mid = lo + (hi-lo)/2;
	sort(a,aux,lo,mid);
	sort(a,aux, mid+1,hi);
	merge(a,aux,lo,mid,hi);
}
void MergeSort::sort(vector<int>& a){
	vector<int> aux(a.size()); //initialize vector of size a.size() and 0 as contents
	sort(a,aux,0, a.size()-1);
}

int main(){
  MergeSort m1;
  vector<int>k = {12,45,65,89,74,32,45};
  int s = 7;
  m1.sort(k);
  for(auto x: k)
  	cout << x << " ";
}