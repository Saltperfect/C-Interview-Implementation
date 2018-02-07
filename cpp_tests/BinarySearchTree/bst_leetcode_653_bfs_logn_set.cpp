#include <set>
#include <queue>
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
    bool find(TreeNode* root, int target, set <int> &s){
    	if(root == nullptr) return false;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(s.find(target - (node -> val)) != s.end()){
                return true;
            }
            s.insert(node -> val);
            if(node-> right != nullptr)
                q.push(node -> right);
            if(node -> left != nullptr)
                q.push(node -> left);
            q.pop();
        }
        return false;
    }
    bool findTarget(TreeNode* root, int target){
    	set <int> s;
    	return find(root, target, s);
    }
    
    int main(){
        TreeNode* rt = nullptr;
        rt = insu(rt,5);
        rt = insu(rt,3);
        rt = insu(rt,6);
        rt = insu(rt,2);
        rt = insu(rt,4);
        rt = insu(rt,7);
        // rt = insert(rt,20);
        
        cout << rt -> val << endl;
        cout << "the checker" << endl;
        cout << findTarget(rt,5) << endl;
    }
