/*
Create a node with a name as Node. A Node object has an integer data field, and a Node forwd pointer, pointing to forward node (i.e.: the next node in a list) and a Node back pointer ,pointing to previous node(i.e,: the previous node in a list). In this node builder is inserting N house numbers at the end of list. A node is used to store N House Numbers .Create a program to help a builder to remove the last house number from colony and then print the list in both forward and backward direction.If N>=5 && N<15 condition is not satisfied then print Invalid Input.

Input Format

First line will contain one integer value reprenting the value of N(total number of houses).
N lines each contains one integer value which is representing house number which is inserted at end of list.

Constraints

N>=5 && N<15

Output Format

After deleting last house number traverse the list in forward direction.
After deleting last house number traverse the list in backward direction.

Sample Input 0

5
4
5
6
7
8
Sample Output 0

4 5 6 7
7 6 5 4
*/

//solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct house
{
    int h_no;
    house *forward=NULL;
    house *backward=NULL;
};
house *start=NULL,*cur=NULL,*pre=NULL;
void input()
{
    if(start==NULL)
    {
        start=new house;
        cin>>start->h_no;
        pre=start;

    }
    else
    {
        cur=new house;
        cin>>cur->h_no;
        pre->forward=cur;
        cur->backward=pre;
        pre=cur;
    }
}
void delete_end()
{
  pre->backward->forward=NULL;
    pre=pre->backward;
}
void task()
{
    cur=start;
    while(cur!=NULL)
       { cout<<cur->h_no<<" ";
         cur=cur->forward;
       }
    cout<<endl;
    cur=pre;
    while(cur!=NULL)
        {cout<<cur->h_no<<" ";
         cur=cur->backward;
        }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    if(n>=5 && n<15)
    {for(int i=0;i<n;i++)
    {
        input();
    }
    delete_end();
    task();}
    else
    {
        cout<<"Invalid Input";
    }
    return 0;
}
