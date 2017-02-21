#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 };

int isBalancedHelper(TreeNode* A) {
    if(A==NULL)return 0;

    int left = isBalancedHelper(A->left);
    int right = isBalancedHelper(A->right);

    if(left==INT_MIN||right==INT_MIN)return INT_MIN;
    if(abs(left-right)>1)return INT_MIN;

    return max(left,right) + 1;
}

bool isBalanced(TreeNode* A) {
    return isBalancedHelper(A) != INT_MIN ;
}

int main()
{
    /*
        Check Balanced Binary Tree
                         4
                      /     \
                    2         6
                  /   \         \
                 1     3         7
        Result : True (Balanced)

    */
    TreeNode *root    = new TreeNode(4);
    root->left        = new TreeNode(2);
    root->right       = new TreeNode(6);
    root->left->left  = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right  = new TreeNode(7);

    bool check = isBalanced(root);
    cout<<"\nTree Balanced (root) : "<<(check==1?"True":"False");

     /*
        Check Balanced Binary Tree
                         4
                      /
                    2
                  /
                 1
        Result : False (Not Balanced)

    */
    TreeNode *root2    = new TreeNode(4);
    root2->left        = new TreeNode(2);
    root2->left->left  = new TreeNode(1);

    check = isBalanced(root2);
    cout<<"\nTree Balanced (root2) : "<<(check==1?"True":"False");

    return 0;
}
