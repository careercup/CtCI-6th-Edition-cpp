/*Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an
algorithm to create a binary search tree with minimal height.
*/

// Assume our tree is defined like this
struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(int a) {
		data = a;
	}
};

// Algorithm wise is:
// 1. Insert into tree middle element of array
// 2. Insert into left subtree left subarray element
// 3. Insert into right subtree right subarray elements
// 4. Recurse

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