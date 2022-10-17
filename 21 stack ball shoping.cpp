/*
Garima visited toy shop to purchase colored balls, when shopkeeper start displaying all the colored balls then she got confused that which ball she should select or reject. All the colored balls are so attractive hence she decided to purchase more than one color ball but not all the balls. So let’s help Garima by creating one application which execute as per her choice for example when she enter 1 then she should be allowed to purchase any color ball, when she enter 2 then only recent ball which is added that will be removed and display the remaining colored balls and after that application will close. Note:-Garima can enter her choice repeatedly.

Input Format

In First Line , enter choice as 1 In second line, Enter number of elements which user wants to insert Third line will contain the values which is to be inserted. Fourth line , enter choice as 2.

Constraints

User can enter only String type of value.

Output Format

Display the deleted color which is recently added and show the remaining colors left and then application close.

Sample Input 0

1
2
red yellow
2
Sample Output 0

yellow
red
Explanation 0

Deleted color is yellow which is recently inserted and left with red color only
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct stack
{
  string   ball;
    stack * next=NULL;
    stack * pre=NULL;
};
stack *start=NULL,*top=NULL;
void push(string s)
{
    if(start==NULL)
    {
        start = new stack;
        start->ball=s;
        top = start;
    }
    else{
        stack *cur = new stack;
        cur->ball=s;
        cur->pre=top;
        top->next=cur;
        top=cur;
    }
}
void pop()
{
    if(top!=NULL)
    {
        top = top->pre;
        top->next=NULL;
    }
        
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int choice;
    do
    {
        cin>>choice;
        switch (choice)
        {
            case 1:
                {
                    int n;
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        string x;
                        cin>>x;
                        push(x);
                    }
                }
            case 2:
                {
                    cout<<top->ball<<endl;
                    pop();
                    stack *cur=top;
                    while(cur!=NULL)
                    {
                        cout<<cur->ball<<" ";
                        cur=cur->pre;
                    }
                    exit(0);
                }
        }
    }
    while(true);
    return 0;
}
