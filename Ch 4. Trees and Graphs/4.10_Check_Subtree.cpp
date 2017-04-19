/*
Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
algorithm to determine ifT2 is a subtree of Tl.
A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2.
That is, if you cut off the tree at node n, the two trees would be identical.
*/

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(int a) {
		data = a;
	}
};

bool containTree(TreeNode* T1, TreeNode* T2) {
	string s1 = "";
	string s2 = "";

	// Build the string for s1
	inOrderString(T1, s1);
	inOrderString(T2, s2);

	return (s1.find(s2) != string::npos);
}

void inOrderString(TreeNode* root, string s) {
	if (root == nullptr) {
		s += "X";
		return;
	}

	s += root->data;
	inOrderString(root->left, s);
	inOrderString(root->right, s);
}

// All of this takes O(n + m) time and O(n + m) space where n and m are number of nodes in T1 and T2 respectively