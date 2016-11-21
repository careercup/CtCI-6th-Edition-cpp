#include<iostream>
#include<climits>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

/*We just use the code from last problem, created a binary search tree with minimum height. Then we check if the tree is balanced search tree.*/

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
/*The check is performed recursively. The min/max solution. We proceed through the tree with this approach. When we branch left, the max gets updated to the data of current node. When we
branch right, the min gets updated to the data of current node. If anything fails these checks, we stop and return false.*/
bool isBST(node* root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data<=min || root->data>max){
        return false;
    }
    if (!isBST(root->left, min, root->data) || !isBST(root->right, root->data, max)){
        return false;
    }
    return true;
}

int main(){
    int arr[] = {1, 2, 3, 4, 15, 6, 7, 8, 9};    //NOT a BST since we assume a sorted   array is provided before we create the BST
 //   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    //is a BST
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    cout<<boolalpha<<isBST(root, INT_MIN, INT_MAX);
}
