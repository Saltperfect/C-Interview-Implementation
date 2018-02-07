#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums){
	if(nums == nullptr || nums.size() == 0) return nullptr;
	/*while(nums.size() != 1){
		vector<int>::const_iterator first = nums.begin();
		vector<int>::const_iterator mid = nums.begin() + nums.size()/2;
		vector<int>::const_iterator end = nums.end();
		vector<int> left_part(first, mid);         //[leftpart][midnumber][rightpart]
		vector<int> mid_number(mid, mid +1);
		vector<int> right_part(mid+1, end);
		root = insert(root,mid_number.at(0));
		root = sortedArrayToBST(left_part);
		root = sortedArrayToBST(right_part);
	}*/
	return utilarrbast(nums, 0, nums.size() - 1);
} 
TreeNode* utilarrbast(vector<int>& nums, int left, int right){
	if(left > right) return nullptr;
	int mid = (left + right)/2;
	TreeNode* root = new TreeNode(nums.at(mid));
	root -> left = utilarrbast(nums, left, mid - 1);
	root -> right = utilarrbast(nums, mid+1, right);
	return root;
}
int main(){
	std::vector<int> v{-3,-1,3,5,8,9,10,14};
	TreeNode* output;
	output = sortedArrayToBST(v);
}