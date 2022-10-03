/*
Write a program to create the queue of N elements . Size of the queue should be greater than 2 and less than equal to 15. If the size of the queue will not be in the mentioned range then it should display the message “Invalid Queue range" with taking any elements for input.And if there is no even element present then display "No even element is there".

Input Format

First Input will represent the number of elements in the queue
Second Input insert the elements(Enqueue operation).

Constraints

Size (N) of the queue should be 2 < N <= 15.

Output Format

Your program should display the even elements of the queue . But if the size will be invalid or if the even elements are not there then display the mentioned message

Sample Input 0

3
2
3
4
Sample Output 0

2 4
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int *queue;
int front=-1,rear=-1;
void enqueue(int x)
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
int dequeue()
{
    int deleted=queue[front];
    if(front ==n-1)
    {
        front=0;
    }
    else{
        front=front+1;
    }
    return deleted;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   
     int check=0;
    cin>>n;
    if(n>2 && n<=15)
    {
        queue=new int[n];
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            enqueue(x);
        }
        for(int i=0;i<n;i++)
        {
           
            int y=dequeue();
            if(y%2==0)
            {
                cout<<y<<" ";
                check=1;
            }
        }
        if(check==0)
        {
            cout<<"No even element is there";
        }
    }
    else
    {
        cout<<"Invalid Queue range";
    }
    return 0;
}
