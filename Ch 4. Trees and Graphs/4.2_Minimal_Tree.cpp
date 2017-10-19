TreeNode* createMinBST(vector<int> arr) {
	return createMinBST(arr, 0, arr.length() - 1);
}

TreeNode* createMinBST(vector<int> arr, int start, int end) {
	if (start > end) {
		return null;
	}
	int mid = start + (end - start) / 2;
	TreeNode* newNode = new TreeNode(arr[mid]);
	newNode.left = createMinBST(arr, start, mid - 1);
	newNode.right = createMinBST(arr, mid + 1, end);
	return newNode;
}
