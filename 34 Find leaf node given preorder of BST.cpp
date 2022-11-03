//*This code is partially working some test case are still under_reviews


/*
Terminal node is the node , which is not having any child node. Programmer is going to enter Preorder traversal of Binary Search tree as an input, find the terminal nodes without building tree.

Input Format

In first line , enter total number of nodes In second line , enter Preorder tree traversal

Constraints

All the numeric input data can be entered.

Output Format

Print Terminal node

Sample Input 0

3
6 2 10
Sample Output 0

2 10
Explanation 0

2 and 10 are the terminal nodes
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int *pre=NULL;
int find(int key,int start,int stop)
{
    int small=0,large=0;
    for(int i=start;i<=stop;i++)
    {
        
        if(key<pre[i])
            large=1;
        else
            small=1;
        if(small==1 && large==1)
            return 1;      
    }
    return 0;    
}
void leaf(int key,int start,int stop)
{
    if(start>stop)
    {
        cout<<key<<" ";
        return;
    }
    int check = find(key,start,stop);
    if(check==0)
        cout<<key<<" ";
    leaf(pre[start],start+1,stop);
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    pre = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    leaf(pre[0],0,n-1);
    return 0;
}
