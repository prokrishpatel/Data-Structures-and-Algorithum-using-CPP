/*
You are given pointer to the root of the binary search tree and two values  and . You need to return the lowest common ancestor (LCA) of  and  in the binary search tree.

image
In the diagram above, the lowest common ancestor of the nodes  and  is the node . Node  is the lowest node which has nodes  and  as descendants.

Function Description

Complete the function lca in the editor below. It should return a pointer to the lowest common ancestor node of the two values given.

lca has the following parameters:
- root: a pointer to the root node of a binary search tree
- v1: a node.data value
- v2: a node.data value

Input Format

The first line contains an integer, , the number of nodes in the tree.
The second line contains  space-separated integers representing  values.
The third line contains two space-separated integers,  and .

To use the test data, you will have to create the binary search tree yourself. Here on the platform, the tree will be created for you.

Constraints




The tree will contain nodes with data equal to  and .

Output Format

Return the a pointer to the node that is the lowest common ancestor of  and .

Sample Input

6
4 2 3 1 7 6
1 7
image
 and .

Sample Output

[reference to node 4]

Explanation

LCA of  and  is , the root in this case.
Return a pointer to the node.
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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
  /*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

   
    Node *lca(Node *root, int v1,int v2) 
    {
        if(root==NULL)
            return NULL;
        if(root->data > v1 && root->data >v2)
            return lca(root->left,v1,v2);
        if(root->data <v1 && root->data <v2)
            return lca(root->right,v1,v2);
        return root;
    }
  }; //End of Solution

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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}


