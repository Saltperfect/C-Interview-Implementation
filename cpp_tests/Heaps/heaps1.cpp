#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int parent(int i){
	return floor(i/2);
}
int left_child(int i){
	return 2*i;
}
int right_child(int i){
	return 2*i + 1;
}
void shift_up(vector<int>& v, int& size,int i){
	while(i > 1 && v[i] > v[parent(i)])
	{
		swap(v[parent(i)], v[i]);
		i = parent(i);
	}
}

void insert(vector<int>& v, int& size, int value){
	v.push_back(value);
	size++;
	shift_up(v,size,size);

}
void shift_down(vector<int>& v, int& size, int i){
	//the hardest code

	int maxIndex = i;
	cout << "check3 " << endl;
	cout << maxIndex << endl;
	int l = left_child(i);
	if(l <= size && v[l] > v[maxIndex])
		maxIndex = l;
	int r = right_child(i);
	if(r <= size && v[r] > v[maxIndex])
		maxIndex = r;
	if(i != maxIndex){
		swap(v[maxIndex], v[i]);
		shift_down(v, size, maxIndex);
	}
}
int extract_max(vector<int>& v, int& size){
	int maximum = v[1];
	v[1] = v[size];
	cout << "check1 v1" << endl;
	cout << v[1] << endl;
	size -= 1;
	cout << "check2 size" << endl;
	cout << size << endl;

	shift_down(v, size, 1);
	return maximum;
}
int get_max(vector<int>& v){
	return v[1];
}

int main(){
	vector<int> v;
	v.push_back(0);
	int size = 0;
	insert(v, size, 5);
	insert(v, size, 4);
	insert(v, size, 7);
	insert(v, size, 2);
	insert(v, size, 9);
	for(auto x: v)
		cout << x << endl;
		extract_max(v, size);
	cout << get_max(v) << endl;
}

