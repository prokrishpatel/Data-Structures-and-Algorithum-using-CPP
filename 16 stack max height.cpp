/*You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

Example

There are and cylinders in the three stacks, with their heights in the three arrays. Remove the top 2 cylinders from (heights = [1, 2]) and from (heights = [1, 1]) so that the three stacks all are 2 units tall. Return as the answer.

Note: An empty stack is still a stack.

Input Format

The first line contains three space-separated integers, , , and , the numbers of cylinders in stacks , , and . The subsequent lines describe the respective heights of each cylinder in a stack from top to bottom:

The second line contains space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.

The third line contains space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.

The fourth line contains space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.

Samlple Input:

STDIN Function ----- -------- 5 3 4 h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4
3 2 1 1 1 h1 = [3, 2, 1, 1, 1] 4 3 2 h2 = [4, 3, 2] 1 1 4 1 h3 = [1, 1, 4, 1]

Sample output:

5

Constraints

0 < n1,n2,n3 < 10 0 < height of Cylinder <100

Output Format

the height of the stacks when they are equalized*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class stack
{
    public:
    int *height;
    int top,max;
    stack(int n)
    {
        max=n;
        top=-1;
        height = new int[n];
    }
    void push(int x)
    {
        if(top!=max-1)
        {
           height[++top]=x; 
        }
    }
    void pop()
    {
        if(top!=-1)
            top--;
    }
    int sum ()
    {
        int x=top,result=0;
        while(x!=-1)
        {
            result = result+ height[x--];
        }
        return result;
    }
    int show()
    {
        return height[top];
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int h1,h2,h3;
    cin>>h1>>h2>>h3;
    int a[h1],b[h2],c[h3];
    stack s1(h1),s2(h2),s3(h3);
    for(int i=0;i<h1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<h2;i++)
    {
       cin>>b[i];
    }
    for(int i=0;i<h3;i++)
    {
        cin>>c[i];
    }
    for(int i=h1-1; i>=0;i--)
    {
        s1.push(a[i]);
    }
    for(int i=h2-1;i>=0;i--)
    {
        s2.push(b[i]);
    }
    for(int i=h3-1;i>=0;i--)
    {
        s3.push(c[i]);
    }
    int r1=s1.sum(),r2=s2.sum(),r3=s3.sum();
    while(r1!=r2 && r2!=r3)
    {
        int min= r1;
        if(r2<min)
        {
            min=r2;
        }
        if(r3<min)
        {
            min=r3;
        }
        if(r1!=min)
        {
            s1.pop();
        }
        if(r2!=min)
        {
            s2.pop();
        }
        if(r3!=min)
        {
            s3.pop();
        }
        r1=s1.sum();
        r2=s2.sum();
        r3=s3.sum();
    }
    cout<<r1;
    return 0;
}
