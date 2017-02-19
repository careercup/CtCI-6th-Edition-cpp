#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
 };

void preOrder(Node *node)
{
	if (node == NULL)
		return;
	cout<< node->data <<" ";
	preOrder(node->left);
	preOrder(node->right);
}

Node* createMinimalBST(vector<int> arr, int low, int high)
{
    if (low > high) {
        return NULL;
    }
    int mid = (low + high) / 2;
    Node* node = new Node(arr[mid]);
    node->left = createMinimalBST(arr, low, mid - 1);
    node->right = createMinimalBST(arr, mid + 1, high);
    return node;
}

Node *createMinimalBST(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;
    return createMinimalBST( arr, 0, ((int)arr.size()) - 1 );
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */
    Node *root = createMinimalBST(arr);
    cout<<"\nPreOrder Traversal of constructed BST : ";
    preOrder(root);

    return 0;
}
