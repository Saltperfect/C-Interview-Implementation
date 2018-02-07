/*insert // insert value into tree
 get_node_count // get count of values stored
 print_values // prints the values in the tree, from min to max
 delete_tree
 is_in_tree // returns true if given value exists in the tree
 get_height // returns the height in nodes (single node's height is 1)
 get_min // returns the minimum value stored in the tree
 get_max // returns the maximum value stored in the tree
 is_binary_search_tree
 delete_value
 get_successor // returns next-highest value in tree after given value, -1 if none
*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>  
using namespace std;
struct bstnode{
  int data;
  bstnode* right;
  bstnode* left;
};

bstnode* getnewnode(int value){
	bstnode* newnode = new bstnode;
	newnode -> data = value;
	newnode -> left = nullptr;
	newnode -> right = nullptr;
	return newnode;
}
bstnode* insert(bstnode* root, int value){
	if(root == nullptr){
		root = getnewnode(value);
	}
	else if(value <= root -> data){
		root -> left = insert(root -> left, value);
	}
	else{
		root -> right = insert(root -> right, value);
	}
	return root;
}
bool is_there(bstnode* root, int value){
	if(root == nullptr) return false;
	if(value == root -> data) return true;
	else if(value < root -> data ) is_there(root -> left , value);
	else is_there(root -> right , value);
}
bstnode* finder(bstnode* root, int value){
	if(root == nullptr) return nullptr;
	if(root -> data == value) return root;
	else if(root -> data < value) return finder(root -> right, value);
	else return finder(root-> left, value);
}
int get_node_count(bstnode* root){
	if(root == nullptr) return 0;
	return 1 + get_node_count(root -> left) + get_node_count(root -> right);
}
int height(bstnode* root){
	if(root == nullptr) return 0;
	return 1 + max(height(root -> left), height(root -> right));
}
void print_values(bstnode* root){
	if(root == nullptr) return;
	else{
		print_values(root -> left);
		cout << root -> data << " ";
		print_values(root -> right);
  }
}
bstnode* get_min(bstnode* root){
	if(root -> left == nullptr) return root;
	else
		get_min(root-> left);
}
bstnode* get_max(bstnode* root){
	if(root -> right == nullptr) return root;
	else
		get_max(root-> right);
}
bool is_binary_search_tree(bstnode* root){
	static bstnode* prev = getnewnode(0);
	if(root){
		if(!is_binary_search_tree(root->left))
			return false;
		if(root -> data < prev -> data)
			return false;
		prev = root;
		if(!is_binary_search_tree(root -> right))
			return false;
	}
	return true;
}
bstnode* delete_value(bstnode* root, int value){
	if(root == nullptr) return nullptr;
	else if(root -> data < value) root -> right = delete_value(root->right,value);
	else if(root -> data > value) root -> left = delete_value(root->left,value);
	else{       //found you // 3 cases
			if(root -> left == nullptr && root-> right == nullptr){
				delete root;
				root = nullptr;
			}
			else if(root -> left == nullptr){
				bstnode* temp = root;
				root = root -> right;
				delete temp;
			}
			else if(root -> right == nullptr){
				bstnode* temp = root;
				root = root -> left;
				delete temp;
			}
			else{
				bstnode* temp = get_min(root->right);
				root -> data = temp -> data;
				root -> right = delete_value(root-> right, temp -> data);
			}
	}
	return root;
}
bstnode* get_successor(bstnode* root, int value){
	// if(root == nullptr) return nullptr;
	bstnode* current = finder(root, value); //O(logn)

	if(current == nullptr) return nullptr;
	//Case 1:- node has a right subtree.
	if(current -> right != nullptr){
		return get_min(current -> right);
	}
	//Case 2:- node has no right subtree, in this case we have to keep track of the ancesstors.
	else{
		bstnode* successor = nullptr;
		bstnode* ancesstor = root;
		while(ancesstor != current){
			if(current-> data < ancesstor -> data){
				successor = ancesstor;
				ancesstor = ancesstor -> left;
			}
			else
				ancesstor = ancesstor -> right;
		}
		return successor;
	}
}
int main(){
	bstnode* rt = nullptr;
  	rt = insert(rt, 12);
  	rt = insert(rt,15);
  	rt = insert(rt,13);
  	rt = insert(rt,10);
  	rt = insert(rt,16);
  	rt = insert(rt,6);
  	rt = insert(rt,20);
	cout << "First print" <<endl;	
	print_values(rt);
	cout << "value 20 deleted" <<endl;	
	delete_value(rt, 20);
	print_values(rt);
	// cout << get_min(rt) << endl;
	// cout << get_max(rt) << endl;
	cout << endl;
	bstnode* r1 = nullptr;
	r1 = get_successor(rt, 15);
	cout << "successor of 6	is" << r1 -> data << endl;
	// cout << is_binary_search_tree(rt) << endl;
}