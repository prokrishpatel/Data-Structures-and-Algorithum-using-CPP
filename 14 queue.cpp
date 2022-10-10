/*
Implement a Queue as mentioned:

An operation Z is of 2 Types.

1 p (operation of this type means you need to add p in queue)
0 (operation of this type means you need to pop in queue and print the popped element)
Input Format

First line tell the nos. of operation
Second line depicts the operation
Constraints

Explanation:

n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2 poped element will be 2 the queue will be {3}
1 4 the queue will be {3 4}
2 poped element will be 3
Output Format

Print popped elements

Sample Input 0

5
1 2 1 3 0 1 4 0
Sample Output 0

2 3
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
queue<int> task;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,choice;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>choice;
        if(choice==1)
        {
            int x;
            cin>>x;
            task.push(x);
        }
        else if(choice==0)
        {
            
            
                int y = task.front();
                cout<<y<<" ";
            
            task.pop();
        }
    }
    return 0;
}
