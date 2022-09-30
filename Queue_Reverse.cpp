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
int n=0;
int x=0;
int front=-1,rear=-1;

int enque(int item)
{
    if((front == 0 && rear == 4) || (front == rear+1))
        return -1;    //queur is full
    else {

        if(front == -1)
          {
            front = 0; rear = 0;
          }
        else if(rear == 4) rear = 0;
        
        else rear = rear +1;
        
        //insert the item
        queue[rear] = item;
        return 1;
        }
}

int deque()
{
    if(front == -1)
        return -1;//Queue is EMPTY
    else
    {
        int item = queue[front];    //store the item to be deleted
        if(front == rear)
        {
            front = -1; rear = -1;
        }
        else if(front == 4) front = 0;
        else front = front +1;
        return item;
    }
}


void task()
{
   cin>>x;
    int j=front;
    for(int i=x-1;i>=j;i--)
    {
        swap(queue[j],queue[i]);
        j++;
    }    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    queue = new int[n];
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        enque(data);
    }
    task();
    
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    return 0;
}
