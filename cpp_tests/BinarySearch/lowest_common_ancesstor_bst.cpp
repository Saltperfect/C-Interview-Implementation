		#include <iostream>
		using namespace std;
		class TreeNode {
      public:
	      int val;
	      TreeNode *left;
	      TreeNode *right;
	      // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
		TreeNode* getnewnode(int value){
			TreeNode* newnode = new TreeNode;
			newnode -> val = value;
			newnode -> left = nullptr;
			newnode -> right = nullptr;
			return newnode;
    }
	  TreeNode* insert(TreeNode* root, int value){
			if(root == nullptr){
				root = getnewnode(value);
			}
			else if(value < root -> val){
				root-> left = insert(root -> left, value);
			}
			else{
				root -> right = insert(root -> right, value);
			}
			return root;
		}
    TreeNode* finder(TreeNode* root, int value){
	    if(root == nullptr) return nullptr;
	    if(root -> val == value) return root;
	    else if(root -> val < value) return finder(root -> right, value);
	    else return finder(root-> left, value);
    }
    bool is_there(TreeNode* root, TreeNode* other){
    	if(root == nullptr) return false;
    	if(root == other) return true;
    	else if(root -> val > other -> val) return is_there(root -> left, other);
    	else return is_there(root-> right, other);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  		if(is_there(p->right, q) || is_there(p->left, q))
  			return p;
  		else if(is_there(q->right, p) || is_there(q->left, p))
  			return q;
  		else{
  			TreeNode* LCA = root;
  			while(true){
  				if(is_there(LCA -> left, p) && is_there(LCA->left, q))
  					return lowestCommonAncestor(LCA -> left, p, q);
  				else if(is_there(LCA -> right, p) && is_there(LCA->right, q))
  					return lowestCommonAncestor(LCA -> right, p, q);
  				else if (is_there(LCA -> right, p) && is_there(LCA->left, q))
  					return LCA;
  				else if (is_there(LCA -> left, p) && is_there(LCA->right, q))
  					return LCA;
  				else 
  					return nullptr;
  			}
  		}
    }
    int main(){
    	TreeNode* rt = nullptr;
    	rt = insert(rt, 12);
    	rt = insert(rt,15);
    	rt = insert(rt,13);
    	rt = insert(rt,10);
    	rt = insert(rt,16);
    	rt = insert(rt,6);
    	rt = insert(rt,20);
    	TreeNode* p = finder(rt, 10);
    	TreeNode* q = finder(rt, 15);
    	TreeNode* result = lowestCommonAncestor(rt, p, q);
    	cout << result -> val << endl;
    }