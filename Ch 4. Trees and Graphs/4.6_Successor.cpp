/*
Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent.
*/

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	int data;
	TreeNode(int a) {
		data = a;
	}
};

TreeNode* mostLeft(TreeNode* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}


TreeNode* findSuccessor(TreeNode* root) {
	
	// Go to most left of right child
	if (root->right != nullptr) {
		return mostLeft(root->right);
	}

	// Go to parent until you are the left child
	TreeNode* child = root;
	TreeNode* ancestor = root->parent;
	while(ancestor != nullptr && ancestor->right == child) {
		child = ancestor;
		ancestor = child->parent;
	}
	return ancestor;
}