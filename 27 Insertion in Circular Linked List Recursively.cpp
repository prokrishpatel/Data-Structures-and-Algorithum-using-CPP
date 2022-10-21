/*
Ajay got a new problem in his subject. He has given a Circular Singly Linklist in which every node contains a pointer ‘next’ which points to the next node in the list. Last node ‘next’ pointer points to the first node in the linked list. Every node has a ‘data’ part that contains some integer positive. You have to insert an integer Z in the linked list at the given position N.

Note:

Assume all the indexing starts from Zero. N will be always less or equal to the nos. of node in the linked list.
You need to create the circular linklist first and then perform operation.
Input Format

First line will contain N.
Second Line will contain Z.
Third Line will contain total nos. of element in the linklist before the operation.
Fourth line will contain space separated integer that depicts the data part from Linked List
Constraints

N>0 & N<50
Z>0 & Z<100
Output Format

Space separated integer that depicts the data part from Linked List after inserting Z at N.

Sample Input 0

3
10
7
2 5 7 8 9 10 12
Sample Output 0

2 5 7 10 8 9 10 12
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
    node *next=NULL;
};
void insert(node *cur,int pos,int info,int count)
{
    if(pos==count)
    {
        node *p =new node;
        p->data=info;
        node *x = cur;
        while(x->next!=cur)
            x=x->next;
        x->next=p;
        p->next=cur;
    }
    else{
        insert(cur->next,pos,info,count+1);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    node *head=NULL;
    int pos;
    cin>>pos;
    int info;
    cin>>info;
    //input for intial list
    int n;
    cin>>n;
    node *cur=NULL,*pre=NULL;
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
            head = new node;
            cin>>head->data;
            pre = head; 
            pre->next=pre;
        }
        else
        {
            cur = new node;
            cin>>cur->data;
            pre->next=cur;
            pre=cur;
            cur->next=head;
        }
    }
    insert(head,pos,info,0);
    cur=head;
    if(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
        while(cur!=head)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }
    
    return 0;
}
