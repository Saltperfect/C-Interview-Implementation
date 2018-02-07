#include <iostream>
#include <queue>
using namespace std;
class TreeNode{
	public:
	int val;
	TreeNode* left;
	TreeNode* right;
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
void BFSTraversal(TreeNode* root){
	if(root == nullptr) return;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		
		cout << q.front() -> val << endl;
		if(q.front() -> left != nullptr)
			q.push(q.front() -> left);
		if(q.front() -> right != nullptr)
			q.push(q.front() -> right);

		q.pop();
	}
}
TreeNode* sortedArrayToBST(vector<int>& nums){
	TreeNode* root = nullptr;
	for(int x: nums){
		root = insert(root, x);
	}
	BFSTraversal(root);
}

int main(){
	vector<int> v {10,20,5,25,7,-5,18,9};
	sortedArrayToBST(v);
}