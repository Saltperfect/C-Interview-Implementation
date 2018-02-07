#include <iostream>
using namespace std;
void myFunc( const int* a, const int* b){
	cout << a << ' ' << b << endl;
	cout << *a << ' ' << *b << endl; 
	(*a)++;
	(*b)++;
	cout << *a << ' '<< *b << endl;
	
	//cout << o << k << endl;
}
int main(){
	int i = 10;
	int j = 20;
	cout << &i << ' ' << &j << endl;
 	myFunc(&i,&j);
	cout << "     " << endl;
	cout << i << ' ' << j << endl;	
}