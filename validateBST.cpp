// Chapter 4
// Implementation of the function "Validate BST" in C++

bool checkBST(Node *root)
{
    static Node* prev=NULL;
    if(root)
    {
        if (!checkBST(root->left)) //keep going down
          return false;
        if(prev != NULL && root->data <= prev->data)
          return false;
        
        prev = root;
 
        return checkBST(root->right);
    }
    
    return true;
}
