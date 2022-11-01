/*
Implement a function to print all the internal nodes of a binary search tree in ascending order.

Input Format

First line reads the number of nodes N and second line reads the N elements of the tree

Example:

5

20 30 10 15 25

Constraints

N > 0

Output Format

Prints all the internal nodes of the Tree in ascending order

Example:

10 20 30

Sample Input 0

5
10 20 5 15 30
Sample Output 0

10 20
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
    node *curp=root;
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            locp = curp;
            loc=cur;
            break;
        }
        else if(cur->data>x)
        {
            curp=cur;
            cur=cur->left;
        }
        else{
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
void insert(int x)
{
    find(x);
    if(loc==NULL)
    {
        node *n = new node;
        n->data=x;
        if(locp==NULL)
            root=n;
        else if(locp->data>n->data)
            locp->left=n;
        else
            locp->right=n;            
    }
}
void printinternal(node *head)
{
    if(head==NULL)
        return;
    if(head->left==NULL && head->right==NULL)
        return;
    printinternal(head->left);
    cout<<head->data<<" ";
    printinternal(head->right);
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
    printinternal(root);
    return 0;
}
