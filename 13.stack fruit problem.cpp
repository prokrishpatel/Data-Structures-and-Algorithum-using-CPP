/*2 Ridhima visited super market to purchase fruits, and there all the fruits were displayed,then she got confused that which among the all fruit she should select or reject. All the fruits are fresh hence she decided to purchase more than one fruit but not all of them because that may reach her out of budget. So let’s help Ridhima by creating one application which execute as per her choice for example when she enter 1 then she should be allowed to purchase any fruit, when she enter 2 then only recent fruit which is added that will be removed and display the remaining fruits and after that application will close. Note:-Ridhima can enter her choice repeatedly.

Input Format

In First Line , enter choice as 1 In second line, Enter number of elements which user wants to insert Third line will contain the values which is to be inserted. Fourth line , enter choice as 2.

Constraints

User can enter String type of value only

Output Format

Display the deleted fruit which is recently added and show the remaining fruits left and then application close.

Sample Input 0

1
2
apple orange
2
Sample Output 0

orange
apple
Explanation 0

Deleted fruit will display first and then all the remaining fruit
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct stack
{
  string fruit;
    stack *next=NULL;
    stack *pre=NULL;
};
stack *top=NULL;

void push()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(top==NULL)
        {
            top= new stack;
            cin>>top->fruit;
        }
        else
        {
            stack *p = top;
            top= new stack;
            cin>>top->fruit;
            top->pre = p;
            p->next=top;
        }
    }
}
void pop()
{
    cout<<top->fruit<<endl;
    top=top->pre;
    top->next=NULL;
    stack *p=top;
    while(p!=NULL)
    {
        cout<<p->fruit<<" ";
        p=p->pre;
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
            case 1: push();break;
            case 2: pop();exit(0);
        }
    }
    while(true);
    return 0;
}
