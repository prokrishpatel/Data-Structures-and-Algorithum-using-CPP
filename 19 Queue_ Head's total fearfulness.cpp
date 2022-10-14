/*
All the employee (except the Head ) are standing in queue to submit their bills. The employee have different seniority. In all there are N employee of K different seniority levels. These are given to you in an array, where A1, A2, ..., AN denote the seniority of employees in the queue. AN denotes front of the queue and A1 denotes end of the queue. Head gets an interesting thought past his head. He begins to think what if every employee starting from the end of the queue begins to delegate his job of submitting bills to a employee least ahead of him in the queue but junior to him. The Head’s fearfulness of this scenario is f = i2 - i1 + 1, where i1 is the index of employee in queue and i2 is the index of the junior employee. Head's total fearfulness of chaos is the product of all the fearfulness in Head’s mind. Note if a employee has no junior ahead of him/her in the queue then Head’s fearfulness for this employee is 1. You are required to find the Head's total fearfulness given an arrangement of employees in a queue. Since this number can be quite large output it modulo 1000000007.

Input Format

•The first line contains two integers N and K denoting the number of employees and the number of seniority levels. •The second line contains N space-separated integers A1, A2, ..., AN denoting the seniority of employees in the queue. AN denotes front of the queue and A1 denotes end of the queue.

Constraints

•1 ≤ N ≤ 1000000
•1 ≤ a_i ≤ 1000000
•2 ≤ K ≤ 100000

Output Format

•Output a single integer denoting the total fearfulness of the Head.

Sample Input 0

4 2
1 2 1 2
Sample Output 0

2
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int *queue=NULL;
int n,k;
int front =-1,rear=-1;
void push(int x)
{
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==n-1)
        rear=0;
    else
        rear++;
    
    queue[rear]=x;
}
void pop()
{
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==n-1)
    {
        front=0;
    }
    else
        front++;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int f=1;
    cin>>n>>k;
    queue = new int[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        push(x);
    }
    int min=queue[0];
    for(int i=1;i<n;i++)
    {
        if(queue[i]<min)
        min = queue[i];
    }
    for(int i=0;i<n-1;i++)
    {
       if(queue[i]==min)
       {
       f=f*1;
       }
       else
       {
           int newf;
           int j=i+1;
           while(queue[j]>=queue[i])
               j++;
           newf = j - i + 1;
           f = f*newf;
       }
    }
    cout<<f;
    return 0;
}
