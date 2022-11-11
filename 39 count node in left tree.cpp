/*
Write a program to create the Binary Search Tree of N elements. Number of elements in the Binary tree should be greater than 3 and less than equal to 12. If the number of elements will not be in the range then display the message “Enter correct range ” and elements should not be inserted in Binary tree. After performing insertion your program should display the total number of elements in left subtree of root.

Input Format

First Input will represent the number of elements in the Binary Search Tree.
Second Input should display the total number of elements in left subtree of rootnode. If the number of elements will not be in the range than display the message “Enter correct range”

Constraints

Number of nodes(N) of the Binary Search tree should be 3 < N <= 12

Output Format

Display the total number of elements in left subtree of root But if the size will be invalid then display the mentioned message.
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
node *root=NULL;
node *loc=NULL, *locp=NULL;

void find(int x)
{
    node *cur=root;
    node *curp=NULL;
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            loc=cur;
            locp=curp;
            break;
        }
        else if(cur->data > x)
        {
            curp = cur;
            cur = cur->left;
        }
        else
        {
            curp = cur;
            cur = cur->right;
        }
    }
    if(cur==NULL)
    {
        loc = cur;
        locp = curp;
    }
}
void insert(int x)
{
    find(x);
    if(loc==NULL)
    {
        node *p = new node;
        p->data = x;
        if(locp==NULL)
        {
            root = p ;
        }
        else if(locp->data > x)
        {
            locp->left= p ;
        }
        else
        {
            locp->right=p;
        }
    }
}
    
int count(node *head)
{
    if(head==NULL)
        return 0;
    return count(head->left)+count(head->right)+1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    if(n>3 && n<=12)
    {
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            insert(x);
        }  
        cout<<count(root->left);
    }
    else
    {
        cout<<"Enter correct range";
    }
    return 0;
}
