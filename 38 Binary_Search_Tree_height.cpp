/*
Calculate the height of binary search tree .The height of a binary search tree is the number of edges between the tree's root and its furthest leaf. You are given a pointer, named as root , pointing to the root of a binary search tree. Create a function named CalculateHeight function which will return the height of the binary search tree. Note n (number of nodes ) should be between 3 to 10 ,If entering other value display message NOT IN RANGE

Input Format

The first line contains an integer,n , denoting the number of nodes in the tree.
Each of the n subsequent lines contains an integer, data, denoting the value of an element that must be added to the BST.

Constraints

Number of nodes n must lies between 3 to 10.

Output Format

Print the integer returned by your CalculateHeight function denoting the height of the BST.

Sample Input 0

7
3
5
2
1
4
6
7
Sample Output 0

3
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
    
int height(node *head)
{
    if(head==NULL)
        return 0;
    return max(height(head->left),height(head->right))+1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    if(n>=3 && n<=10)
    {for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }
    cout<<height(root)-1;}
    else
    {
        cout<<"NOT IN RANGE";
    }
    return 0;
}

