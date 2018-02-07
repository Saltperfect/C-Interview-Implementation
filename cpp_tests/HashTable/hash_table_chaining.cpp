		#include <iostream>
		#include <string>
		#include <vector>

		using namespace std;
		class data{
		public:
			data():key(0), value(0){}
			data(int k, int val):key(k),value(val){}
		private:
			int key;
			int value;
			friend class hashchain;
		};
		class hashchain{
		public: 
			hashchain(int size);
			void add(int k, int val);
			bool exists(int k);
		  int get(int k);
		  void remove(int k);
		  void display();
		private:
			int size;
			vector< vector<data> > v;
		};

		hashchain::hashchain(int m):size(m),v(size, vector<data>()){}
		
		void hashchain::add(int k, int val){
    	int index = k % size;
    	data d1(k,val);
    	v[index].push_back(d1);
    }
    bool hashchain::exists(int k){
    	int index = k % size;
    	for(int i=0;i< v[index].size() ; i++){
        if(v[index][i].key == k)
        	return 1;
    	}
    }

    int hashchain::get(int k){
      int index = k % size;
      	for (int i = 0; i < v[index].size(); ++i)
      	{
      		if(v[index][i].key == k)
        		return v[index][i].value;
      	}
      	
    }
     
    void hashchain::remove(int k){
 			int index = k % size;
 			data d1(0,0);
      	for (int i = 0; i < v[index].size(); ++i)
      	{
      		if(v[index][i].key == k){
        	  v[index][i] = d1;
        	  break;
          }
      	}
    }
    void hashchain::display(){
    	/*for (int i = 0; i < v.size(); ++i)
    	{
    		for (int j = 0; i < v[i].size(); ++j)
    		{
    			cout << v[i][j].key << " " << v[i][j].value ;
    		}
    		cout << endl;
    	}*/
    	cout << v.size() << " " << v[1].size() << endl;
    }


		int main(){
			hashchain h1(1);
			h1.add(3,134);
			h1.display();
		}
