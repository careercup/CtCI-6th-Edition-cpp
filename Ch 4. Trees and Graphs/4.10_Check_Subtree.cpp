bool containTree(TreeNode* T1, TreeNode* T2) {
	string s1 = "", s2 = "";
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
