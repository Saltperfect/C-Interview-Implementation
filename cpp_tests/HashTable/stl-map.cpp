#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  map<int, string> m1;
  map<int, string>::iterator p;
  m1.insert(pair<int, string>(3, "ram"));
  m1[3] = "kishan";
  m1[10] = "rahim";
  m1[11] = "munshi";
  p = m1.find(3);
  m1.erase(p);
  if(p == m1.end()) cout << "nonexistent\n";
  for(p = m1.begin(); p != m1.end(); p++){
  	cout << p-> first << " "  << p-> second << endl;
  }
}