#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

 bool isBSTHelper(TreeNode* A,int minimum,int maximum) {
    if(A==NULL)
        return true;

    int data = A->data;
    if(minimum>=data||data>=maximum)
        return false;

    if( isBSTHelper(A->left,minimum,data)==true && isBSTHelper(A->right,data,maximum)==true )
        return true;

    return false;
}

bool isBST(TreeNode* A) {
    return isBSTHelper(A,INT_MIN,INT_MAX);
}

int main()
{
    /*
        Check BST
                         3
                      /     \
                    2         6
                  /   \         \
                 1     4         7
        Result : False

    */
    TreeNode *root    = new TreeNode(3);
    root->left        = new TreeNode(2);
    root->right       = new TreeNode(6);
    root->left->left  = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right  = new TreeNode(7);

    bool check = isBST(root);
    cout<<"\nBST (root) : "<<(check==1?"True":"False");

      /*
        Check BST
                        4
                      /
                    2
                  /
                 1
        Result : True

    */
    TreeNode *root2    = new TreeNode(4);
    root2->left        = new TreeNode(2);
    root2->left->left  = new TreeNode(1);

    check = isBST(root2);
    cout<<"\nBST (root2) : "<<(check==1?"True":"False");

    return 0;
}
