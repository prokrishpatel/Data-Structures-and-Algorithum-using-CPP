/*
You are given a pointer to the root of a binary search tree and values to be inserted into the tree. Insert the values into their appropriate position in the binary search tree and return the root of the updated binary tree. You just have to complete the function.

Input Format

You are given a function,

Node * insert (Node * root ,int data) {

}
Constraints

No. of nodes in the tree  500
Output Format

Return the root of the binary search tree after inserting the value into the tree.

Sample Input

        4
       / \
      2   7
     / \
    1   3
The value to be inserted is 6.

Sample Output

         4
       /   \
      2     7
     / \   /
    1   3 6
    */

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }
  /*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
Node *loc=NULL, *locp=NULL;
void find(int x,Node *root)
{
    Node *cur=root,*curp=NULL;
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            loc=cur;
            break;
        }
        else if(cur->data>x)
        {
            curp=cur;
            cur=cur->left;
        }
        else
        {
            curp=cur;
            cur=cur->right;
        }
    }
    if(cur==NULL)
    {
        loc=cur;
        locp=curp;
    }
}

    Node * insert(Node * root, int data) {
        find(data,root);
        if(loc==NULL)
        {
            Node *New = new Node(data);
            if(locp==NULL)
                root=New;
            else if(locp->data>data)
                locp->left=New;
            else
                locp->right=New;
        }


        return root;
    }
  };

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
