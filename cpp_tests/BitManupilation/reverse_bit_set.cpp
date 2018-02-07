		#include <iostream>
    #include <bitset>
		using namespace std;

		int main(){
			int k = 45;
			int v = 45;
			int r = 0;
			for(int s = 0; s <= 30 ; s++){
				int vbit = v & 1;
				v >>= 1;
				r |= vbit;
				r <<= 1;
			}
			int vbit = v & 1;
			r |= vbit;
			cout << bitset<32>(k) << "  " << bitset<32>(r) << endl;
		}