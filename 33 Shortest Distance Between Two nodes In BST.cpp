/*
Write a program to create Binary Search tree for the given elements and then find the shortest distance between two elements in Binary Search tree. Elements may exist on same side of the tree or may be opposite side.

Input Format

First line will contain one integer N value representing number of elements.
Second line will contain N space separated integers.
Third line will contain two space separated integers and you have to find distance between these two values in BST.

Constraints

N>5 && N<20

Output Format

One integer value representing distance between two key values.

Sample Input 0

5
5 3 7 4 2
2 5
Sample Output 0

2
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
    node *cur=root,*curp=NULL;
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
void insert(int x)
{
    find(x);
    if(loc==NULL)
    {
        node *New = new node;
        New->data=x;
        if(locp==NULL)
            root=New;
        else if(locp->data>x)
            locp->left=New;
        else
            locp->right=New;            
    }
        
}
int main_fun(node *root ,int x ,int ans = 0)
{
    if(root->data == x)
        return ans;
    if(root->data > x)
        return main_fun(root->left,x,ans+1);
     else
         return main_fun(root->right,x,ans+1);
}
void distance(node *root ,int n ,int m)
{
    if( root->data > n && root->data > m )
        distance(root->left ,n ,m);
    else if(root->data < n && root->data < m)
        distance(root->right ,n ,m);
    else
        cout<<(main_fun(root ,n) + main_fun(root ,m));
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
    int a,b;
    cin>>a>>b;
    distance(root,a,b);
    
    return 0;
}
