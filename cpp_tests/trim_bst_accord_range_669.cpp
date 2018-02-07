#include <queue>
#include <iterator>
#include <iostream>

using namespace  std;
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
    TreeNode* trimBST(TreeNode* root, int L, int R){
        if(root == nullptr) return nullptr;
        queue<TreeNode*> q;
        vector<int> v;
        TreeNode* result = nullptr;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node -> val <= R && node -> val >= L){
                result = insu(result, node -> val);         
            }
            if(node -> left != nullptr)
                q.push(node -> left);
            if(node -> right != nullptr)
                q.push(node -> right);
            q.pop();
        }
        return result;
    }
        int main(){
        TreeNode* rt = nullptr;
        rt = insu(rt,1);
        rt = insu(rt,3);
        // rt = insu(rt,6);
        rt = insu(rt,2);
        // rt = insu(rt,4);
        // rt = insu(rt,7);
        TreeNode* rot = trimBST(rt, 1, 3);
        cout << rot -> val << rot -> right -> val<<  rot -> right -> left ->val;  
    }