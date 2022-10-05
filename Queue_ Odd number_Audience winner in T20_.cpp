/*
Assume 9 spectators are standing in a ticket counter to take a ticket to watch a T20 match.In a queue enter n names of spectators and then some gifts will be given to odd ticket number spectators who came to watch match.Note index is ticket number and values in queues are name of spectators.Create a user interactive program where 1 will be for insertion and 2 will display names of odd ticket spectators who will get some gifts.

Input Format

First Input will represent the operation
Second Input will represent how many names to be inserted in case operation is insertion .
Third Input will be n names in a ticket counters.
Fourth Input is to call display operation

Constraints

If the size of the queue will be full, display “No other spectator is allowed”.

Output Format

Display names of spectator shortlisted for gifts.

Sample Input 0

1
3
Aryan
Piyush
Rahul
2
Sample Output 0

Piyush
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string name[9];
int n,check=1;
int front=-1,rear=-1;

void enqueue(string x)
{
    if( (front==0 && rear==8)||front==rear+1 )
    {
        cout<<"No other spectator is allowed";
        check=-1;
    }
    else
  {      
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==8)
    {
        rear=0;
    }
    else
       { rear++;}
        
    name[rear]=x;
    }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int option;
    
        
    for(int i=0;i<2;i++)
     {   cin>>option;
        if(option==1)
                       {
                    cin>>n;
                  for(int j=0;j<n;j++)
                      {
                          string iteam;
                          cin>>iteam;
                          enqueue(iteam);
                          if(check==-1)
                             exit(0);
                     }
                 }
        else if(option==2)
                {
                    int k=front;
                    while(k<=rear)
                    {
                        if(k%2!=0)
                        {
                            cout<<name[k]<<" ";
                        }
                        k++;
                    }
           }
        }
        
    return 0;
   }
    

