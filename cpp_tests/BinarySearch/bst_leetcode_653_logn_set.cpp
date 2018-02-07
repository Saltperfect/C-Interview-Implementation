#include <set>
#include <iostream>
using namespace std;
  	
    class TreeNode {
        public:
            int val;
            TreeNode *left;
            TreeNode *right;
    };
    TreeNode* getnewnode(int value){
            TreeNode* newnode = new TreeNode;
            newnode -> val = value;
            newnode -> left = nullptr;
            newnode -> right = nullptr;
            return newnode;
    }
    TreeNode* insu(TreeNode* root, int value){
            if(root == nullptr){
                root = getnewnode(value);
            }
            else if(value < root -> val){
                root-> left = insu(root -> left, value);
            }
            else{
                root -> right = insu(root -> right, value);
            }
            return root;
        }
    bool find(TreeNode* root, int target, set <int>& s){
    	if(root == nullptr) return false;
    	if(s.find(target - (root -> val)) != s.end()) //target - (root -> val) exist return true
    		return true;
    	s.insert(root -> val);
  
    	return (find(root -> left, target,s) || find(root -> right, target,s));
    }
    bool findTarget(TreeNode* root, int target){
    	set <int> s;
    	return find(root, target,s);
    }
    
    int main(){
        TreeNode* rt = nullptr;
        rt = insu(rt,5);
        rt = insu(rt,3);
        rt = insu(rt,6);
        rt = insu(rt,2);
        rt = insu(rt,4);
        rt = insu(rt,7);
        rt = insu(rt,20);
        cout << "the checker" << endl;
        cout << findTarget(rt, 27) << endl;		
    }
