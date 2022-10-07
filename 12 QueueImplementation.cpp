/*
Write a program to create the queue of N elements in increasing order. Size of the queue should be greater than 2 and less than equal to 10. All the elements of the queue should be in increasing order. Element will not inserted in the queue if it will not follow the above condition.

Input Format

Your program should take the 2 types of inputs. First will represent the number of elements in the queue and second should insert the elements. If the entered element will not be in the increasing order then it will not inserted. If the size of the queue will not be in the mentioned range then it should display the message “Invalid size” with taking any elements for input.

Constraints

Size (N) of the queue should be 2 < N <= 10.
All the elements should be in increasing order.
Output Format

Your program should display the elements of the queue from front to rear. But if the size will be invalid then display the mentioned message.

Sample Input 0

3
2
1
3
4
Sample Output 0

2
3
4
Sample Input 1

2
Sample Output 1

Invalid size
*/

#include <iostream>
#include<queue>
using namespace std;
queue<int>task ;
int main()
{
    int n;
    cin>>n;
    int count=0;
    if(n>2 && n<=10)
    {
        int data;
        cin>>data;
        count++;
        task.push(data);
  
        for(int i=1;i<10;i++)
        {
            if(count==n)
            {
                break;
            }
            cin>>data;
            if(data>task.front())
            {
                task.push(data);
                count++;
              }
        }
        while(!task.empty())
        {
            cout<<task.front()<<endl;
            task.pop();
        }
    }
    else
    {
        cout<<"Invalid size";
    }
    return 0;
}
