		/*insert(int value)
		 shift_up(i) - needed for insert
		 get_max - returns the max item, without removing it
		 get_size() - return number of elements stored
		 is_empty() - returns true if heap contains no elements
		 extract_max - returns the max item, removing it
		 shift_down(i) - needed for extract_max
		 remove(i) - removes item at index x
		 heapify - create a heap from an array of elements, needed for heap_sort
		 heap_sort() - take an unsorted array and turn it into a sorted array in-place using a max heap*/
		#include <vector>
		#include <iostream>
		#include <algorithm>
		#include <climits>
		using namespace std;
		class heap{
		public:
			heap();
			heap(const heap& other);
			heap& operator=(heap src);
			~heap();
			int parent(int i);
			int right_child(int i);
			int left_child(int i);
			void insert(int value);
			void shift_up(int i);
			int get_max();
			int get_size();
			bool is_empty();
			int extract_max();
			void shift_down(int i);
			void remove(int i);
			void heapify(const vector<int>&); //Build array into a heap
			void heap_sort(const vector<int>&);
			void display();
		private:
			vector<int> v;
			int size;
		};
		// only constructer is needed as we are using a built in library so no destructor
		heap::heap():size(0),v({0}){}

		heap::heap(const heap& other){
			size = other.size;
			v = other.v;
		}

		heap& heap::operator=(heap src){
			swap(size, src.size);
			swap(v,src.v);
		}

		heap::~heap(){}

		int heap::parent(int i){
			return floor(i/2);
		}
		int heap::left_child(int i){
			return 2*i;
		}
		int heap::right_child(int i){
			return 2*i + 1;
		}
		void heap::insert(int value){
			v.push_back(value);
			size += 1;
			shift_up(size);
		}
		void heap::shift_up(int i){
			while (i > 1 && (v[parent(i)] < v[i])){
				swap(v[parent(i)], v[i]);
				i = parent(i);
			}
		}

		int heap::get_max(){
			return v[1];
		}

		int heap::get_size(){
			return size;
		}
		bool heap::is_empty(){
			bool k;
			(size>0)? k = true: k = false;
			return k;
		}
		int heap::extract_max(){

			int maxi = v[1];
			
			v[1] = v[size];
			
			size -= 1;
			
			shift_down(1);

			return maxi;
		}
		void heap::shift_down(int i){
			int maxIndex = i; 
			 
			int l = left_child(i);

			if(l <= size && v[maxIndex] < v[l])
				maxIndex = l;

			int r = right_child(i);

			if(r <= size && v[maxIndex] < v[r])
				maxIndex = r;

			if (i != maxIndex){
				swap(v[i], v[maxIndex]);
				shift_down(maxIndex);
			}
		}
		void heap::remove(int value){
		int i = 0;
		int focus;
			while(i <= size){
				if(v.at(i) == value){
					focus = i;
					break;
				}
				i += 1;
			}
			v[focus] = INT_MAX;
			shift_up(focus);
			extract_max();
		}
		void heap::heapify(const vector<int>& A){
			v.resize(A.size()+1);
			size = A.size();
			int j = 1;
			for(auto x: A){
				v[j] = x;
				j++;
			}
			for(int i = parent(size) ; i >= 1 ; i--){  //running time n	
				shift_down(i);
			}
		}
		void heap::heap_sort(const vector<int> &A){
			heapify(A);

			while(size > 1){
				swap(v[1],v[size]);
				size -= 1;
				shift_down(1);
			}
		}
		void heap::display(){
			for(auto x: v)
				cout << x << " ";
		}
int main(){
	heap h1;
	

	// cout << h1.v[0] << endl;
	/*h1.insert(23);
	h1.insert(43);
	cout << h1.get_max() << endl;
	h1.remove(43);
	cout << h1.get_max() << endl;
	h1.insert(34);
	h1.insert(93);
	h1.insert(31);
	h1.insert(21);
	h1.insert(78);
	cout << h1.get_max() << endl;
	h1.extract_max();
	cout << h1.get_max() << endl;
	cout << h1.get_size() << endl;*/
	vector<int> k = {2,3,7,8,10,3,9,12,15};
	heap h2;
	h2.heapify(k);
	h2.display();
	cout << endl;
	h2.heap_sort(k);
	h2.display();
}