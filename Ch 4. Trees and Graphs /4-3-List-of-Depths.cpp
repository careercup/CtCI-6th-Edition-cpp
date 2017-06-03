#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 };

void findLevelLinkListHelper
        (TreeNode *root,int level,vector< list<TreeNode*> > &lists)
{
    if (root != NULL)
    {
        if (level == lists.size()) { //New level found
            lists.push_back( list<TreeNode*>() );
        }

        lists[level].push_back(root);
        findLevelLinkListHelper(root->left,  level + 1, lists);
        findLevelLinkListHelper(root->right, level + 1, lists);
    }
}

vector< list<TreeNode*> > findLevelLinkList(TreeNode *root) {
    vector< list<TreeNode*> > lists;
    findLevelLinkListHelper(root,0,lists);
    return lists;
}

void printResult(vector< list<TreeNode*> > result){
		int depth = 0;
		for(int i=0; i<result.size(); i++)
		{
			cout<<"LinkList at depth "<< depth << " : ";
			list<TreeNode*> temp  = result[i];

			for (list<TreeNode*>::iterator it = temp.begin(); it != temp.end(); it++)
                cout << (*it)->data <<" ";

			cout<<endl;
			depth++;
		}
}

int main()
{
    /*
        Binary Tree to List
                         4
                      /     \
                    2         6
                  /   \         \
                 1     3         7

                 List 1: 4
                 List 2: 2 -> 6
                 List 3: 1 -> 3 -> 7
    */
    TreeNode *root    = new TreeNode(4);
    root->left        = new TreeNode(2);
    root->right       = new TreeNode(6);
    root->left->left  = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right  = new TreeNode(7);

    vector< list<TreeNode*> > lists;

    lists = findLevelLinkList(root);

    printResult(lists);

    return 0;
}
