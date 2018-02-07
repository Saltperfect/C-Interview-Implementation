#include <iostream>
using namespace std;

 unsigned int roundUpToNextPowerOfTwo(unsigned int x)
{ int count = 0;
	x--; //for covering x = power of 2
  while(x!=1){
  	x >>= 1;
  	count++;
  }
  return (1 << count+1);
}

int main(){
	cout << roundUpToNextPowerOfTwo(33) << endl;

}