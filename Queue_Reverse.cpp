/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Input Format

5
1 2 3 4 5
3

Constraints

Total number of integers should be 5
Complete the provided function modify Queue that takes queue and k as parameters and returns a modified queue.
Output Format

3 2 1 4 5

Sample Input 0

5
5 4 3 2 1
4
Sample Output 0

2 3 4 5 1
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int *queue=NULL;
int *stack=NULL;
int front=-1,rear=-1,top=-1,n;
void enqueue(int x)
{
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else if(rear==n-1)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        queue[rear]=x;
    }
}
int deqeue()
{
    int deleted=queue[front];
    {
        
        if(front == rear)
        {
            front = -1; rear = -1;
        }
        else if(front == 4) front = 0;
        else front = front +1;
            
    }
    return deleted;
}

void push(int x)
{
    top =top+1;
        stack[top] = x;
}
int pop()
{
    int deleted = stack[top];
    top=top-1;
    return deleted;
}

int main()
{
    
    cin>>n;
    queue = new int[n];
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        enqueue(data);
    }
    int k;
    cin>>k;
    stack = new int[k];
    while(front<k)
    {
        push(deqeue());
    }
    while(top!=-1)
    {
        enqueue(pop());
    }
    for(int i=0;i<n;i++)
    {
        cout<<queue[i]<<" ";
    }
}
