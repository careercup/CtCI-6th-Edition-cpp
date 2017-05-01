bool validateBST(TreeNode* root, int min, int max) {
	if (root == nullptr) {
		return true;
	}
	if (root->data < min || root->data > max) {
		return false;
	}
	return validateBST(root->left, min, root->data - 1) && validateBST(root->right, root->data + 1, max);
}

bool validateBST(TreeNode* root) {
	return validateBST(root, -2e9, 2e9);
}
