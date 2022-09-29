/*
On September 5,2022 Python exam was taken and it was written by 6 students, and accordingly concerned faculty member uploaded the marks of those 6 students .But one of the student was not able to attempt exam so with the request , his exam was re-conducted and later on faculty is going to upload marks ,but before this faculty must needs to enter rollno and then after his marks.

Input Format

First line consist with 6 numbers needs to be inserted Second Line consist with the position, that where to insert Third line consist with the data which is to be inserted.

Constraints

All the input which is to be inserted that will be of numeric type.

Output Format

Displayed final inserted element on its actual position which is given as input.

Sample Input 0

1 2 3 4 5 6
2
7
Sample Output 0

1 7 2 3 4 5 6
*/

//Solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
    int marks;
    student *next=NULL;
    student *pre=NULL;
};
student *start=NULL,*cur=NULL, *p=NULL;
void insert()
{
   //temp
    if(start==NULL)
    {
        start=new student;
        cin>>start->marks;
        p=start;
    }
    else
    {
        cur=new student;
        cin>>cur->marks;
        p->next=cur;
        cur->pre=p;
        p=cur;
    }
}

void task(int pos,int mark)
{
    student *p=new student;
    p->marks=mark;
    cur=NULL;
    for(int i=1;i<=pos;i++)
    {
        if(i==1)
            cur=start;
        else
            cur=cur->next;
    }
    if(cur==start)
    {
        p->next=start;
        start->pre=p;
        start=p;
    }
    else if(cur==NULL)
    {
        cur=start;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=p;
        p->pre=cur;
    }
    else
    {
        p->next=cur;
        p->pre=cur->pre;
        cur->pre->next=p;
        cur->pre=p;
    }
    cur=start;
    while(cur!=NULL)
    {
        cout<<cur->marks<<" ";
        cur=cur->next;
    }
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    for(int i=0;i<6;i++)
    {
        insert();
    }
    int pos,mark;
    cin>>pos>>mark;
    task(pos,mark);
    return 0;
}
