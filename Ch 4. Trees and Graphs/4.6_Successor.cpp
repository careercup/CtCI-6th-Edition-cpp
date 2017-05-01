TreeNode* mostLeft(TreeNode* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

TreeNode* findSuccessor(TreeNode* root) {
	if (root->right != nullptr) {
		return mostLeft(root->right);
	}
	TreeNode* child = root;
	TreeNode* ancestor = root->parent;
	while(ancestor != nullptr && ancestor->right == child) {
		child = ancestor;
		ancestor = child->parent;
	}
	return ancestor;
}
