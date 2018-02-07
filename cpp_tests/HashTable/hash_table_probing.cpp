	#include <iostream>
	#include <string>
	#include <algorithm>
	using namespace std;
	class data{
	  private:
   	  	int key;
	  	int value;
	  	bool deleteme;
	  friend class hashtable;
	};
	class hashtable{
	  public:
	  	hashtable(int m);
	  	hashtable(const hashtable& that);
	  	hashtable & operator= (hashtable src);
	  	~hashtable();
	  	void add(int key, int value);
	  	bool exists(int key);
	  	int get(int key);
	  	void remove(int key);
	  	void display();
	  private:
	  	int size;
	  	data* array;
	};
	hashtable::hashtable(int m):size(m){
		array = new data[m]();
		// data array[] = {NULL};
	}
	hashtable::hashtable(const hashtable& that){
	  size = that.size;
	  array = new data[that.size];
	  for(int i = 0; i < that.size ; ++i){
	  	array[i] = that.array[i];
	  }
	}
	hashtable & hashtable::operator=(hashtable src){
		std::swap(array, src.array);
		std::swap(size, src.size);
	    return *this;
	}
	hashtable::~hashtable(){
		delete [] array;
	}
	void hashtable::add(int k, int val){
	  int index = k % size;
	  while(array[index].key != 0 || array[index].deleteme == 1){
	    if(array[index].key == k)
	      break;
	    index += 1;
	  }
	  array[index].key = k;
	  array[index].value = val;
	}
	bool hashtable::exists(int key){
	  int index = key % size;
	  while((array[index].key != key && index < size ) || (array[index].deleteme == 1 && index < size)){
	  	index += 1;
	  }
	  return index < size;
	}
	int hashtable::get(int key){
	  int index = key % size;
	  while((array[index].key != key && index < size) || (array[index].deleteme == 1 && index < size)){
	  	index += 1;
	  }
	  if(index < size)
	  	return array[index].value;
	}
	void hashtable::remove(int key){
	  int index = key % size;
	  while((array[index].key != key && index < size)|| (array[index].deleteme == 1 && index < size)){
	  	index += 1;
	  }
	  array[index].key = 0;
	  array[index].value = 0;
	  array[index].deleteme = 1;
	}
	void hashtable::display(){
		for (int i = 0; i < size; ++i)
		{
			cout << array[i].key << " " << array[i].value  << " " << array[i].deleteme << endl;
		}
	}

	int main(){
	  hashtable h1(11);
	  h1.add(3,134);
	  h1.add(14,139);
	  h1.add(742,963);
	  h1.add(11,456);
	  h1.add(22,635);
	  h1.add(33,852);
	  h1.add(44,968);
	  h1.add(9,589);
	  h1.add(9,7890);
	  h1.remove(14);
	  h1.remove(33);
	  h1.add(55,786);
	  h1.add(10,56);
	  cout << h1.get(44) << endl;
	  // cout << h1.(43) << endl;
	  h1.display();
	}