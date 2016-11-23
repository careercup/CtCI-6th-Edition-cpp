#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

/*Build a BST first, and searching for in-order successor of a given node.*/
void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createMinimalBst(root->left, arr, start, ind-1);
        createMinimalBst(root->right, arr, ind+1, end);
    }
}




struct node * leftmost(struct node* node) {
  struct node* current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    // if right subtree is non-empty, then inorder successor is in the right subtree
    if( n->right != NULL )
        return leftmost(n->right);

    struct node *succ = NULL;

    // if there is no right subtree, start from root and search for successor down the tree.
    // travel down the tree, if the node¡¯s data is greater than root¡¯s data then go right side, otherwise go to left side.
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
    if (succ != NULL)
    return succ;
    else printf("No inorder successor!");
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    node* searchedNode1 = inOrderSuccessor(root, root->left);
    cout<<"Successor found: "<<searchedNode1->data<<'\n';
    node* searchedNode2 = inOrderSuccessor(root, root->right->right->right);
    cout<<"Successor found: "<<searchedNode2->data<<'\n';
}
