#include<iostream>
#include <iomanip>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

void createBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createBst(root->left, arr, start, ind-1);
        createBst(root->right, arr, ind+1, end);
    }
}

void postorder(node* p, int indent=0)
{
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createBst(root, arr, 0, 8);
    printf("Postorder Traversal of constructed BST \n");
    postorder(root);
}
