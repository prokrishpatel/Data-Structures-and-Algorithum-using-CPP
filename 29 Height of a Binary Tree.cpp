/*
The height of a binary tree is the number of edges between the tree's root and its furthest leaf. For example, the following binary tree is of height :

image
Function Description

Complete the getHeight or height function in the editor. It must return the height of a binary tree as an integer.

getHeight or height has the following parameter(s):

root: a reference to the root of a binary tree.
Note -The Height of binary tree with single node is taken as zero.

Input Format

The first line contains an integer , the number of nodes in the tree.
Next line contains  space separated integer where th integer denotes node[i].data.

Note: Node values are inserted into a binary search tree before a reference to the tree's root node is passed to your function. In a binary search tree, all nodes on the left branch of a node are less than the node value. All values on the right branch are greater than the node value.

Constraints



Output Format

Your function should return a single integer denoting the height of the binary tree.

Sample Input

image

Sample Output

3
Explanation

The longest root-to-leaf path is shown below:

image

There are  nodes in this path that are connected by  edges, meaning our binary tree's .
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node *left=NULL;
    node *right=NULL;
};
node *root=NULL,*loc=NULL,*locp=NULL;
void find(int x)
{
    node *cur=root;
    node *curp=NULL;
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            loc = cur;
            break;
        }
        else if(cur->data>x)
        {
            curp = cur;
            cur=cur->left;
        }
        else
        {
            curp = cur;
            cur=cur->right;
        }
    }
    if(cur==NULL)
    {
        loc =cur;
        locp=curp;
    }
}
void insert(int x)
{
    find(x);
    if(loc==NULL)
    {
        node *NEW =new node;
        NEW->data=x;
        if(locp==NULL)
            root=NEW;
        else if(x<locp->data)
            locp->left=NEW;
        else
            locp->right=NEW;
    }
}
int height(node *head)
{
    if(head==NULL)
        return 0;
    int l = height(head->left);
    int r = height(head->right);
    return max(l,r)+1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }
    cout<<height(root)-1;
    return 0;
}
