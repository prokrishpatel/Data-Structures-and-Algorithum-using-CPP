/*
given a singly linked list, find the middle of the linked list. For example, if the given linked list is A->B->C->D->E then the output should be C. If there are even nodes, then there would be two middle nodes, we need to print the first middle element. For example, if the given linked list is A->B->C->D->E->F then the output should be C.

Input Format

first line reads the number of elements N and
second line reads N elements of linked list

Example
5
A B C D E

Constraints

1<= N <= 20

Output Format

Prints the middle element of the linked list

Example:

C

Sample Input 0

5
A B C D E
Sample Output 0

C
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct llist
{
    char data;
    llist *next=NULL;
};

void middle(llist *slow, llist *fast)
{
    if(slow==NULL)
    {
        return;
    }
    if(fast->next==NULL)
    {
        cout<<slow->data;
        return;
    }
    if(fast->next->next==NULL)
    {
        cout<<slow->data;
        return;
    }
    if(slow!=NULL || fast->next!=NULL || fast->next->next!=NULL)
    {
        middle(slow->next,fast->next->next);
    }
    
}
llist *head=NULL;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n;//number of elements
    cin>>n;
    llist *temp=NULL;
    for(int i=0;i<n;i++)//for input of n elements
    {
        if(head==NULL)//first node
        {
            head = new llist;
            cin>>head->data;
            temp = head;
        }
        else
        {
            llist *p = new llist;
            cin>>p->data;
            temp->next=p;
            temp = p;
        }
    }
    middle(head,head);
    return 0;
}
