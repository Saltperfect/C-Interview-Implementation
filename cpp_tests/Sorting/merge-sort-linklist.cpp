#include <iostream>
#include <algorithm>




class Node{
public:
	int data;
	Nodeptr next;
};
using namespace std;
using Nodeptr = Node *;
// typedef Node * Nodeptr;

Nodeptr globalhead = nullptr;

void insert(Nodeptr *head, int val){
	Nodeptr newnode = new Node;
	newnode -> data = val;
	newnode -> next = nullptr;
	if(*head == nullptr){
		*head = newnode;
		globalhead = *head;
	}
	else{
		(*head) -> next = newnode;
		*head = newnode;
	}
}
void printlist(Nodeptr head){
	Nodeptr current = head;
	while(current != nullptr){
		cout << current -> data << " ";
		current = current -> next;
	}
	cout << endl;
}

void partition(Nodeptr head, Nodeptr* front, Nodeptr* back){
	Nodeptr* fast;
	Nodeptr* slow;
	if(head == nullptr || head -> next ==nullptr){
		*front = head; //value of a
		*back = nullptr;
	}
	else{
		slow = head;
		fast = head -> next;
		while(fast != nullptr){
			fast = fast -> next;
			//if fast comes up two steps slow comes up 1 step
			if(fast != nullptr){
				fast = fast -> next;
				slow = slow -> next;
			}
		}
		*front = head;
		*back = slow -> next;
		slow -> next = nullptr;
		printlist(*front);
		printlist(*back);
	}
}

Nodeptr mergelists(Nodeptr a, Nodeptr b){
	Nodeptr result = nullptr;
	if(a == nullptr){
		return b;
	}
	else if(b==nullptr){
		return a;
	}
	//base cases
	else if(a-> data <= b-> data){
		result = a;
		result -> next = mergelists(a->next, b);
	}
	else{
		result = b;
		result -> next = mergelists(a, b->next);
	}
	return result;
}
void mergesort(Nodeptr *source){
	if(*source == nullptr || (*source)-> next == nullptr){
		return;
	}
	Nodeptr head = *source;
	Nodeptr a = nullptr;
	Nodeptr b = nullptr;
	
	partition(head, &a, &b);

	mergesort(&a);
	mergesort(&b);

	*source = mergelists(a,b);
}

int main(){
	Nodeptr head = nullptr;
	insert(&head, 12);
	insert(&head, 45);
	insert(&head, 18);
	insert(&head, 96);
	insert(&head, 132);
	insert(&head, 74);

	printlist(globalhead);
	
	mergesort(&globalhead);
	
  printlist(globalhead);

  return 0;
}