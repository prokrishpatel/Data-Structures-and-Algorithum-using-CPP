//https://www.hackerrank.com/contests/cse205-16920-day24
/*
A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
Input Format

The first line contains a single integer, , denoting the number of queries.
Each line  of the  subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query , but only query  is followed by an additional space-separated value, , denoting the value to be enqueued.

Constraints

It is guaranteed that a valid answer always exists for each query of type .
Output Format

For each query of type , print the value of the element at the front of the queue on a new line.

Sample Input

STDIN   Function
-----   --------
10      q = 10 (number of queries)
1 42    1st query, enqueue 42
2       dequeue front element
1 14    enqueue 42
3       print the front element
1 28    enqueue 28
3       print the front element
1 60    enqueue 60
1 78    enqueue 78
2       dequeue front element
2       dequeue front element
Sample Output

14
14
Explanation

Perform the following sequence of actions:

Enqueue ; .
Dequeue the value at the head of the queue, ; .
Enqueue ; .
Print the value at the head of the queue, ; .
Enqueue ; .
Print the value at the head of the queue, ; .
Enqueue ; .
Enqueue ; .
Dequeue the value at the head of the queue, ; .
Dequeue the value at the head of the queue, ; .
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class queue
{
    int data;
    queue *next=NULL;
    queue *pre=NULL;
    public:
        queue *top=NULL;
        void push(int x)
        {    queue *p=NULL;
            if(top==NULL)
            {
                top=new queue;
                top->data=x;
            }
               else
            {
                p=new queue;
                p->data=x;
                top->next=p;
                p->pre=top;
                top=p;
        
            }
        }
        int pop()
        {
            int deleted=-1;;
            if(top!=NULL && top->pre ==NULL)
            {
                deleted = top->data;
                top=NULL;
                
            }            
            else if(top!=NULL)
            {
                deleted = top->data;
                top=top->pre;
                top->next=NULL;
                
            }
            return deleted;
        }
        void print()
        {
            if(top!=NULL)
            cout<< top->data<<endl;
        }
};
queue input,output;
void enqueue(int x)
{
    input.push(x);
}
void dequeue()
{
   if(output.top!=NULL)
   {
       output.pop();
   }
   else
   {
           while(input.top!=NULL)
           {
               output.push(input.pop());
           }
        output.pop();
   }
}
void print()
{
    if(output.top!=NULL)
    {
        output.print();
    }
    else
    {
        while(input.top!=NULL)
           {
               output.push(input.pop());
        }
        if(output.top!=NULL)
        output.print();
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int query;
    int choice;
    cin>>query;
    for(int i=0;i<query;i++)
    {
        cin>>choice;
        switch(choice)
        {
            case 1: int x;
                    cin >> x;
                    enqueue(x); break;
            case 2: dequeue(); break;
            case 3: print(); break;
        }
    }
    
    
    return 0;
}
