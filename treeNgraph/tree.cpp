#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode *root){
	if(!root) return;
	cout << root->val << ' ';
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root){
	if(!root) return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

void postorder(TreeNode *root){
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << ' ';
}

TreeNode *construct(vector<int> &preorder, int i, int j,
					vector<int> &inorder, int ii, int jj){
	if(i >= j || ii >= jj) return nullptr;
	int mid = preorder[i];
	auto f = find(inorder.begin()+ii, inorder.begin()+jj, mid);
	int dis = f - inorder.begin() - ii;
	TreeNode *root = new TreeNode(mid);
	root->left = construct(preorder, i+1, i+1+dis, inorder, ii, ii+dis);
	root->right = construct(preorder, i+1+dis, j, inorder, ii+dis+1, jj);
	return root;
}

TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder){ 
	return construct(preorder, 0, preorder.size(), inorder, 0, inorder.size());	
}

int main(){
	vector<int> vPreorder = {3,9,20,15,7};
	vector<int> vInorder = {9,3,15,20,7};
	TreeNode *root = constructTree(vPreorder, vInorder);

	cout << "preorder: ";
	preorder(root);
	cout << endl;

	cout << "inorder: ";
	inorder(root);
	cout << endl;

	cout << "postorder: ";
	postorder(root);
	cout << endl;
}
