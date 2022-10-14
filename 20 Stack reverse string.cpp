/*
Write a program to reverse the string using stack.

Input Format

Enter a string.

Constraints

Maximum size of string is 30 and minimum size is 5

Output Format

Display reverse of given string

Sample Input 0

Programming practice
Sample Output 0

ecitcarp gnimmargorP
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct s1
{
    char d1;
    s1 *next =NULL;
    s1 * pre=NULL;
};
s1 *top1=NULL,*p1=NULL;

void push1(char item)
{
    if(top1==NULL)
    {
        top1 = new s1;
        top1->d1=item;
    }
    else
    {
        p1 =new s1;
        p1->d1=item;
        p1->pre=top1;
        top1->next=p1;
        top1 = p1;
    }
}

int pop1()
{
    char deleted;
    {
        deleted = top1->d1;
        if(top1->pre==NULL)
            top1=NULL;
        else
        {
        top1 = top1->pre;
        top1->next=NULL;
        }
       return deleted;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s;
    getline(cin, s);
    for(int i=0;i<s.length();i++)
       {
        push1(s[i]);   
       }

    while(top1!=NULL)
    {
         cout<<top1->d1;
        pop1();
    }
    return 0;
}
