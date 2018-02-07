/*size() - returns number of data elements in list
 empty() - bool returns true if empty
 value_at(index) - returns the value of the nth item (starting at 0 for first)
 push_front(value) - adds an item to the front of the list
 pop_front() - remove front item and return its value
 push_back(value) - adds an item at the end
 pop_back() - removes end item and returns its value
 front() - get value of front item
 back() - get value of end item
 insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
 erase(index) - removes node at given index
 value_n_from_end(n) - returns the value of the node at nth position from the end of the list
 reverse() - reverses the list
 remove_value(value) - removes the first item in the list with this value*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class node{
  private:
    int data;
    node* next;
  friend class sLinkList;
};

class sLinkList{
  public:
  	sLinkList();
  	sLinkList(const sLinkList& that);
  	~sLinkList();
  	int size();
  	bool empty();
  	int value_at(int index);
  	void push_front(int value);
  	void push_back(int value);
  	int pop_back();
  	void remove_front();
  	int front();
  	int back();
  	void insert(int index, int value);
  	void erase(int index);
  	int value_n_from_end(int n);
  	void reverse();
  	void remove_value(int value);
  	void remove_entry(int entry);
  	sLinkList& operator=(sLinkList other);
  private:
  	node* head;
};

sLinkList::sLinkList()
  : head(NULL)
  {}

sLinkList::sLinkList(const sLinkList& that):head(NULL){
  node* kode = that.head;
  while(kode != NULL){
  	push_front(kode -> data);
  	kode = kode -> next;
  }
  head = that.head;
}
sLinkList & sLinkList::operator=(sLinkList src){
	std::swap(head, src.head);
	return *this;
}
sLinkList::~sLinkList(){
  while(head != NULL){
    remove_front();
  }
}
int sLinkList::size(){
	int count = 0;
	node* finger = head;
	while(finger->next != NULL){
		count++;
		finger = finger -> next;
	}
	return count + 1;
}
void sLinkList::remove_front(){
  node* old = head;
  head = old -> next;
  delete old;
}

void sLinkList::push_front(int value){
  node* newNode = new node;
  newNode->data = value;
  newNode -> next = head;
  head = newNode;  
}
void sLinkList::insert(int index, int value){
  if(index == 0) push_front(value);
  else{
    node* finger = head;
    for(int i=0; i<= index-2; i++){
  	  finger = finger -> next;
    }
    node* newNode = new node;
    newNode->data = value;
    newNode -> next = finger -> next;
    finger -> next = newNode;
  }
}
bool sLinkList::empty(){
	return head == NULL;
}
int sLinkList::value_at(int index){
  node* finger = head;
  for(int i= 0; i <= index-1; i++){
    finger = finger -> next;
  }
  return finger -> data;
}
void sLinkList::push_back(int value){
  node* finger = head;
  while(finger->next != NULL){
  	finger = finger -> next;
  }
  node* newNode = new node;
  newNode->data = value;
  finger -> next = newNode;
  newNode -> next = NULL;
}
int sLinkList::pop_back(){
	if(head -> next == NULL){
		node* old = head;
		head = NULL;
		delete old;
	}
	else{
	node* finger = head;
	while(finger->next->next != NULL){
		finger = finger ->next;
	}
	node* old = finger->next;
	finger -> next = NULL;
	delete old;
    }
}
int sLinkList::front(){
	return head -> data;
}
int sLinkList::back(){
	node* finger = head;
	while(finger->next != NULL){
		finger = finger -> next;
	}
	return finger -> data;
}
void sLinkList::remove_entry(int num){
  node** indirect = &head;
  while((*indirect) -> data != num){
  	indirect = &(*indirect) -> next;
  }
  *indirect = (*indirect) -> next;
}

void sLinkList::erase(int index){
  node* finger = head;
  if(index == 0){
  	head = head -> next;
  	delete finger;
  }
  else{
  	for(int i=0; i <= index - 2; i ++){
  		node* old = finger -> next;
  		finger -> next = finger -> next -> next;
  		delete old;
  	}
  }
}
void sLinkList::reverse(){
  node* ptr1; node* ptr2; node* crawl;
  ptr1 = head;
  ptr2 = head -> next;
  crawl = ptr2;
  while(ptr2 != NULL){
  	crawl = ptr2 -> next;
  	ptr2 -> next = ptr1;
  	ptr1 = ptr2;
  	ptr2 = crawl;
  }
  head -> next = NULL;
  head = ptr1; 
}
  

int sLinkList::value_n_from_end(int n){
  auto from = this->size() - n ;
  return value_at(from);
}
void sLinkList::remove_value(int value){
  node* finger = head;
  int count=0;
  while(finger-> next != NULL && finger -> data != value){
    finger = finger -> next;
    count++;
  }
  if(finger->next == NULL){
  	cout << "Value not found";
  }
  erase(count);
}

int main(){
  sLinkList s1;
  s1.push_front(10);
  s1.push_front(20);
  s1.push_back(30);
  s1.insert(0,90); 
  s1.remove_entry(90); 
   //90 ,10,30
  //s1.remove_value(20);
  //cout << s1.value_at(0) << endl;// 90
  // cout << s1.value_n_from_end(1) << endl; //30
for (int i = 0; i < s1.size(); ++i)
  {
     cout << s1.value_at(i) << "  " ;	  
  }	
  cout << endl;
  sLinkList s2(s1);    // s2: 10
  //s2.push_front(30);
  //s1.insert(1,50);     // s1: 10,50
  //s2.push_front(70);    // 70,10
  //s1.push_back(30);   // s1: 10,50,30
  //s1.remove_front();  // s1: 50,10,30
  //s1.pop_back();       // s1: 10,50
  for (int i = 0; i < s2.size(); ++i)
  {
     cout << s2.value_at(i) << "  " ;	  
  }

}