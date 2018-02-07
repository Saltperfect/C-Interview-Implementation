#include <vector>
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
     void util(TreeNode* root, vector<int> &vect){
        if(root == nullptr) return;
        else{
            util(root -> left, vect);
            vect.push_back(root -> val);
            util(root -> right, vect);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> vect;
        if(root == nullptr) return false;
        else{
        util(root, vect);
        // if(vect.back() > k) return false;
        bool flag = 0;
        int min = 0;
        int max = vect.size() - 1;
        while(vect.at(max) > vect.at(min)){
            int sum = vect.at(max) + vect.at(min);
            if (sum == k)
                return true;
            if(sum < k)
                min++;
            else
                max--;
        }
        return false;
    }
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
        
        
        cout << "the checker" << endl;
        cout << findTarget(rt, 50) << endl;
    }
