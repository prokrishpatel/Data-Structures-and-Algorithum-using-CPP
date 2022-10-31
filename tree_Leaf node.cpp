/*
Given a binary search tree with N nodes, implement a function print_leaf(node* root) to print all the leaf nodes in descending order.

Input Format

First line reads the number of nodes and second line reads the elements of the tree.

Example:

5

10 5 20 30 15

Constraints

N > 0

Output Format

Prints all the nodes of BST in descending order

Example:

30 15 5

Sample Input 0

5
10 5 20 30 15
Sample Output 0

30 15 5
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
void leaf_node(node *head)
{
    if(head==NULL)
        return;
    leaf_node(head->right);
    if(head->left==NULL&&head->right==NULL)
    {
        cout<<head->data<<" ";
        return;
    }
    leaf_node(head->left);
    
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
    leaf_node(root);
    return 0;
}
