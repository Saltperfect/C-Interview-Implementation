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
		using namespace std;

		class bstnode{
			private:
				bstnode* left;
				bstnode* right;
		  	int data;
		  friend class tree;
		};

		class tree{
			public:
		    tree();
		    void insert(int value);
		    bstnode* utilinsert(bstnode* root, int value);
		    bstnode* getnewnode(int value);
		    int get_node_count();
		    void print_values();
		    bool is_in_tree(int value);
		    bool util_is_in_tree(bstnode* root, int value);
		    int get_height();
		    int get_min();
		    int get_max();
		    bool is_binary_search_tree();
		    void delete_value(int value);
		    int get_successor(int value);
		  private:
		  	bstnode* root;
		};

		tree::tree():root(nullptr){}

		bstnode* tree::getnewnode(int value){
			bstnode* newnode = new bstnode;
			newnode -> data = value;
			newnode -> left = nullptr;
			newnode -> right = nullptr;
			return newnode;
		}
		bstnode* tree::utilinsert(bstnode* root, int value){
			if(root == nullptr){
				root = getnewnode(value);
			}
			else if(value < root -> data){
				root -> left = utilinsert(root -> left , value);
			}
			else {
				root -> right = utilinsert(root -> right, value);
			}
			return root;
		}
		void tree::insert(int value){
			root =  utilinsert(root, value);
		}
		bool tree::util_is_in_tree(bstnode* root, int value){
			if(root == nullptr) return 0;
			if(root -> data == value) return 1;
			else if(value < root -> data) return util_is_in_tree(root -> left, value);
			else return util_is_in_tree(root -> right, value);
		}
		bool tree::is_in_tree(int value){
			return util_is_in_tree(root, value);
		}

		int main(){
			tree t1; 
			t1.insert(123);
			t1.insert(45);
			cout << t1.is_in_tree(123) << endl;
		}



