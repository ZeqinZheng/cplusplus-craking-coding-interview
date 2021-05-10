#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
	TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

TreeNode *constructBST(vector<int> v, int i, int j){
	if(i > j) return nullptr;
	int mid = i + (j-i)/2;
	//int mid = (i+j)/2;
	TreeNode *parent = new TreeNode(v[mid]);
	parent->left = constructBST(v, i, mid-1);
	parent->right = constructBST(v, mid+1, j);
	return parent;
}

void preorder(TreeNode *root){
	if(!root) return;
	cout << root->val << ' ';
	preorder(root->left);
	preorder(root->right);
}

int main(){
	vector<int> v = {1,2,3,4,5,6};
	TreeNode *root = constructBST(v, 0, v.size()-1);
	preorder(root);
	cout << endl;
}
