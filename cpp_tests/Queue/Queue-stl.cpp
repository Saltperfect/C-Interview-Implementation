#include <iostream>
#include <list>
using namespace std;

class queue{
  public:
  	queue();
  	void enqueue(int num);
  	void dequeue();
  	bool empty();
  	void display();
  private:
  	list<int> q;
};
queue::queue(){}
void queue::enqueue(int num){
	q.push_back(num);
}
void queue::dequeue(){
	q.pop_front();
}
bool queue::empty(){
	return q.empty();
}
void queue::display(){
	list<int>::iterator p = q.begin();
	while(p != q.end()){
	  cout << *p << "  ";
	  p++;
	}
	cout << endl;
}
int main(){
	queue q1;
	q1.enqueue(3);
	q1.enqueue(2);
	q1.dequeue();
	cout << q1.empty() << endl;
	q1.display();
}