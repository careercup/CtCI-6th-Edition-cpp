/*
Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one.
*/

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(int a) {
		data = a;
	}
};

int checkHeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftHeight = checkHeight(root->left);
	if (leftHeight == -1) {
		return -1;
	}
	int rightHeight = checkHeight(root->right);
	if (rightHeight == -1) {
		return -1;
	}

	if (abs(leftHeight - rightHeight) > 1) {
		return -1;
	}
	else {
		return max(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(TreeNode* root) {
	return (checkHeight == -1);
}