/*
Write a program to create the Binary Search Tree of N elements. Number of elements in the BST should be greater than 2 and less than equal to 10. If the number of elements will not be in the range then display the message “Invalid Size” and elements should not be inserted. After insertion your program should display the second element of the Preorder traversal.

Input Format

Your program should take the 2 types of inputs. First will represent the number of elements in the BST and second will be the elements of the BST. If the number of elements will not be in the range than display the message “Invalid Size” and element should not be inserted.

Constraints

Size (N) of the BST should be 2 < N <= 10

Output Format

Your program should display the second element of the Preorder traversal. But if the size will be invalid then display the mentioned message.

Sample Input 0

3
2
1
3
Sample Output 0

1
Sample Input 1

2
Sample Output 1

Invalid Size*/
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
    
void preorder(node *head)
{
    if(head==NULL)
        return;
    if(head->left!=NULL)
        cout<<head->left->data;
    else if(head->right!=NULL)
        cout<< head->right->data;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    if(n>2 && n<=10)
    {
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            insert(x);
        }  
     preorder(root);
    }
    else
    {
        cout<<"Invalid Size";
    }
    return 0;
}
