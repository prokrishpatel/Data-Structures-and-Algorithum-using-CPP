/*
WAP to insert N Elements into the stack. Find the Middle element , then delete one element from the stack and again find the new middle element

Example

let 6 elements are there in stack
5
8
6
4
7
middle element is 6
deleted element is 7
new middle element is 8

Input Format

First input : N ,the number of elements in the stack
Second input : accect N elements from the user into the stack

Constraints

N must be nonzero and >=3
second input must be positive intergers

Output Format

Dispaly Middle Element
Display The New Midlle Element After Deleting One element From The Stack.

Sample Input 0

5
2 6 8 7 4
Sample Output 0

8
6
Sample Input 1

3
5 8 6
Sample Output 1

8
5
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int *stack =NULL;
int n;
int top =-1;

void push(int x)
{
    stack[++top]=x;
}
void pop()
{
    if(top>-1)
    {
        top--;
    }
}
void mid()
{
    int mid = top/2;
    if(mid!=-1)
    {
        cout<<stack[mid]<<endl;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    if(n>=3)
    {
        stack = new int[n];
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            push(x);
        }
        mid();
        pop();
        mid();
    }
    return 0;
}
