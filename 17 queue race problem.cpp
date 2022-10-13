/*
In F1 race competition, a total of 5 cars participated and they have to complete a total of 3 laps. During the end of each lap the first car is pushed to the last and finally find the winner who comes first at the end of the 3rd lap

Input Format

5
Mercedes RedBull Ferrari McLaren Alpine

Constraints

F1 car names should be in the queue of Strings
During the end of each and every lap the first car needs to Popped outside and Pushed at the end
Output Format

RedBull Ferrari McLaren Alpine Mercedes
Ferrari McLaren Alpine Mercedes RedBull
McLaren Alpine Mercedes RedBull Ferrari
McLaren

Sample Input 0

5 
Alpha Aston Williams Alfa Haas
Sample Output 0

Aston Williams Alfa Haas Alpha 
Williams Alfa Haas Alpha Aston 
Alfa Haas Alpha Aston Williams 
Alfa
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string *queue=NULL;
int front =-1, rear =-1;
int n;
void push(string s)
{
    if(front==-1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == n-1)
    {
        rear = 0;
    }
    else 
    {
        rear++;
    }
    queue[rear]=s;
}
string pop()
{
    string x = queue[front];
    if(front == rear)
    {
        front =0;
        rear = 0;
    }
    else
        front++;
    return x;
}
void show()
{
    int i=front;
    do
    {
        cout<<queue[i]<<" ";
        if(i==n-1)
            i=0;
        else
            i++;
    }
   while(i!=rear+1);

    cout<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    queue = new string[n];
    for(int i=0;i<n;i++)
    {
        string name;
        cin>>name;
        push(name);
    }
    for(int i=0;i<3;i++)
    {
        push(pop());
        show();
    }
    cout<<queue[front];
    return 0;
}
