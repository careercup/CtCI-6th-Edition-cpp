#include<iostream>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

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

/*Implemented the alternative approach described in the book.*/
bool MatchTree(node* root, node* subRoot){
    if(root == NULL && subRoot == NULL)
        return true;
    else if(root == NULL || subRoot == NULL)
        return false;
    else if(root->data != subRoot->data)
        return false;
    else
        return MatchTree(root->left, subRoot->left) && MatchTree(root->right, subRoot->right);
}

bool isSubTree(node* root, node* subRoot){
    if(root == NULL)
        return false;
    else if(root->data == subRoot->data && MatchTree(root, subRoot))
        return true;
    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

bool  constainsTree(node* root, node* subRoot){
    if(subRoot == NULL) return true;
    return isSubTree(root, subRoot);
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    // Bigger Tree
    int arr1[] = {1, 2, 3, 4};                  // Subtree
    node *root, *subRoot;
    root = subRoot = NULL;
    createMinimalBst(root, arr, 0, 8);
    createMinimalBst(subRoot, arr1, 0, 3);
    cout<<"Is it a subtree? "<<isSubTree(root, subRoot);
    return 0;
}
