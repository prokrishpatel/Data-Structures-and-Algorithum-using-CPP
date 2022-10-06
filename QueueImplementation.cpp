/*
Write a program to implement the queue of characters in the array of size 7 in circular order. Take 2 variables ‘front’ and ‘rear’ contains the indexed of the first and last elements of the queue. Where the ‘-1’ in front and rear will represent the empty queue. Your program should be user interactive where 1 will be for insertion and 2 will be for deletion of elements. When the user will enter any other option, it should display the value of the front and rear.

Input Format

Your program should take the two types of inputs. First will represent the operation and second will represent the value in case of insertion. In case of deletion it can only delete the first element. If the user will insert more than 7 values, it should display “OVERFLOW” message.

Constraints

If the size of the queue will be full, display “OVERFLOW”.

Output Format

Your program should display the first and last values in the queue.

Sample Input 0

1
A
1
B
1
C
1
G
5
Sample Output 0

A
G
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char queue[7];
int front =-1, rear=-1;
int c=1;
void enqueue(char x)
{
    if((front==0 && rear==6) || front==rear+1)
       { cout<<"OVERFLOW\n";
          c=0;
       }
        
    else
    {
        if(front==-1)
        {
            front =0;
            rear =0;
        }
        else if(rear==6)
            rear=0;
        else
            rear++;
        
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front!=-1)
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==6)
            front=0;
        else
            front++;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int choice;
    do
    {
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    char x;
                    cin>>x;
                    enqueue(x);
                   
                    break;
                }
            case 2:
                {
                    dequeue();
                    break;
                }
            default:
                {
                    cout<<queue[front]<<endl;
                    cout<<queue[rear];
                    exit(0);
                }
        }
        if(c==0)
        {
            exit(0);
        }
    }
    while(true);
    return 0;
}
