#include<iostream>
#include<random>
#include <stack>
#include <ctime>
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

/*We use the Reservoir sampling to get a node uniformly at random,
WITHOUT knowing the total number of nodes.
The idea is, do a whatever order of traversal,
if it is the kth node we are traveling,
then replace the previously selected node with probability 1/k.

(1) Initialize result as first node
   result = node
(2) Initialize n = 2
(3) Now one by one consider all nodes from 2nd node onward.
    (3.a) Generate a random number from 0 to n-1.
         Let the generated random number be j.
    (3.b) If j is equal to 0 (we could choose other fixed number
          between 0 to n-1), then replace result with current node.
    (3.c) n = n+1
    (3.d) node = node->left OR node->right determined by the traversal scheme.
*/
node* randomSelect(node* input_node) {
	node* selectedNode = input_node;
    stack<node *> nodeStack;
    nodeStack.push(input_node);
    srand(time(0));
	int count = 1, j = 1;
	while(!nodeStack.empty()){
		node* temp = nodeStack.top();
		nodeStack.pop();
		j = rand();
        cout << "Random number generated: " << j % count <<"\n";
		if(j % count == 0){
			selectedNode = temp;
		}
		if(temp->left != nullptr)
			nodeStack.push(temp->left);
		if(temp->right != nullptr)
			nodeStack.push(temp->right);
		count++;
	}
	return selectedNode;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    node* root;
    root = nullptr;
    createMinimalBst(root, arr, 0, 10);
    node *random_node = randomSelect(root);
    cout<<"A random node is obtained: "<<random_node->data;
}
