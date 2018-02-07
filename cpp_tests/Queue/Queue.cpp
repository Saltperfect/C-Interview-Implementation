#include <iostream>
#include <algorithm>
using namespace std;
class node{
  private:
  	int data;
  	node* next;
  	friend class queue;
};
class queue{
  public: 
  	queue();
  	queue(const queue& that);
  	queue& operator=(queue src);
  	~queue();
  	void enqueue(int val);
  	void dequeue();
  	bool empty();
  	void display();
  private:
  	node* head;
  	node* tail;
};
queue::queue():head(),tail(){}

queue::queue(const queue& that){
  node* kode = that.head;
  while(kode != tail){
  	node* newnode = new node;
  	newnode -> data = kode -> data;
  }
  tail = that.tail;
  head = that.head;  
}
queue& queue::operator=(queue src){
  std::swap(head, src.head);
  std::swap(tail, src.tail);
}
queue::~queue(){
  while(head != nullptr){
    dequeue();
  }
}
void queue::enqueue(int val){
  node* newnode = new node;
  newnode -> data = val;
  if(empty()) {tail = newnode;
  	head = newnode;
  	tail -> next = nullptr;}
  else{tail -> next = newnode;
  tail = newnode;
  newnode -> next = nullptr;}
}
void queue::dequeue(){
	head = head -> next;
}
bool queue::empty(){
	return head == nullptr; //if 1 means empty, 0 means not
}
void queue::display(){
	node* loki = head;
	while(loki != nullptr){
		cout << loki -> data << " ";
		loki = loki -> next;
	}
	cout << endl;
}
int main(){
  queue q1;
  q1.enqueue(2);
  q1.enqueue(3);
  q1.dequeue();
  cout << q1.empty() << endl;
  q1.display();

}