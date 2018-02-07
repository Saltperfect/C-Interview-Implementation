#include <iostream>
using namespace std;
class TreeNode{
    int val;
    *
};

bool isValidBST(TreeNode* root) {
        TreeNode rt = TreeNode(-INT_MIN);
        TreeNode* prev = &rt;
        if(root){
            if(!isValidBST(root->left))
                return false;
            if(prev != nullptr && prev-> val >= root -> val)
                return false;
            prev = root;
            if(!isValidBST(root-> right))
                return false;
        }
        return true;
}
int main(){

}