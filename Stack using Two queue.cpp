/*
Construct a stack using two queues (q1, q2), you need to simulate the stack operations by using queue operations. You are required to complete the three methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack, pop() which poped out from the stack and display() which display the resultant stack(-1 if the stack is empty).

Input Format

Enter the sequence of stack operation, 1 for push(), 2 for pop() and 3 for display().

Constraints

Maximum size of stack in 20

Output Format

Display result according to sequence of operations

Sample Input 0

1
2
1
3
2
1
4
2
1
5
3
Sample Output 0

2 5
Sample Input 1

1
2
2
3
Sample Output 1

-1
*/
#include<iostream>
#include<queue>
using namespace std;
int *arr;
queue<int> q1;
queue<int> q2;
void push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}
void pop()
{
    q1.pop();
}
void display()
{
    if(q1.empty())
    {
        cout<<"-1"<<" ";
    }
    else
    {
        q2=q1;
        arr = new int[q1.size()];
        int j=0;
        while(!q2.empty())
        {
           arr[j]=q2.front();
            q2.pop();
            j++;
        }
        for (int i=q1.size()-1;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
    }
}
int main()
{
    int choice;
    do
    {
        cin>>choice;
        switch(choice)
        {
            case 1:
                int x;
                cin>>x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();    
            default:
                exit(0);        
        }
    }
    while(true);
}
