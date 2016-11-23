#include<iostream>
#include <algorithm>
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

/*The crucial point is that root must come before all its children.
We do it recursivley, at each level:
    We first compute all permutations of left sub-tree sequence,
    and then do it for right sub-tree sequence.

    The critical part is then merge these two sequences.
    So called weaving in the book.

    Let m be the number of nodes in the left sub-tree
    and n be the number of nodes in the right sub-tree.
    Then the number of all possible sequences after merging step is (m+n)!/(m!n!) (binomial coefficient).
*/
vector<vector<int> > findAllSeq(node *ptr)
{
    //Base Case 1:
    //If ptr is NULL, then return a vector with an empty sequence.
    if (ptr == NULL) {
        vector<int> seq;
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }

    //Base Case 2:
    //If ptr is a leaf node, then return a vector with a single sequence.
    //Its trivial that this sequence will contain only a single element, i.e. value of that node.
    if (ptr -> left == NULL && ptr -> right == NULL) {
        vector<int> seq;
        seq.push_back(ptr -> data);
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }

    //Divide Part (this part is very simple.)
    //We assume that we have a function that can solve this problem,
    //and thus we solve it for left sub tree and right sub tree.
    vector<vector<int> > results, left, right;
    left  = findAllSeq(ptr -> left);
    right = findAllSeq(ptr -> right);
    int size = left[0].size() + right[0].size() + 1;

    //Merging the two solution.(The crux is in this step.)
    //Now we have two set containg distinct sequences:
    //i. left  - all sequences in this set will generate left subtree.
    //ii. right - all sequences in this set will generate right subtree.

    vector<bool> flags(left[0].size(), 0);
    for (int k = 0; k < right[0].size(); k++)
        flags.push_back(1);

    //vector<vector<int> > results
    //for all sequences L in left
    //    for all sequences R in right
    //        create a vector flag with l.size() 0's and R.size() 1's
    //        for all permutations of flag
    //            generate the corresponding merged sequence.
    //            append the current node's value in beginning
    //            add this sequence to the results.
    //
    //return results.
    //Say, L={1, 2, 3} R={4, 5}, then we enumerate all possible permutations of {0,0,0,1,1},
    //which yield (3+2)!/(3!2!) sequences. Then we put back {1, 2, 3} at positions of 0s and
    //{4, 5} at positions of 1s.
    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            do {
                vector<int> tmp(size);
                tmp[0] = ptr -> data;
                int l = 0, r = 0;
                for (int k = 0; k < flags.size(); k++) {
                    tmp[k+1] = (flags[k]) ? right[j][r++] : left[i][l++];
                }
                results.push_back(tmp);
            } while (next_permutation(flags.begin(), flags.end()));
        }
    }

    return results;
}

void printAllSeq(vector<vector<int> > &AllSeq){
    int i = 1;
    for (vector<vector<int> >::iterator iter = AllSeq.begin() ; iter != AllSeq.end(); ++iter){
        vector<int> seq = *iter;
        cout<<"The " <<i <<"th sequence is: ";
        i++;
        for (vector<int>::iterator it = seq.begin() ; it != seq.end(); ++it){
            cout << ' ' << *it;
            }
        cout << '\n';
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    node* root;
    root = nullptr;
    createMinimalBst(root, arr, 0, 6);
    vector<vector<int> > all_sequences = findAllSeq(root);
    printAllSeq(all_sequences);
}
