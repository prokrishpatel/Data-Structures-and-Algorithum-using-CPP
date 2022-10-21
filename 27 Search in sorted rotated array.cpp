/*
Given a sorted and rotated array arr[] of size N and a key, the task is to find the key in the array.

Note: Find the element in O(logN) time and assume that all the elements are distinct.

Example:

Input : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 3 Output : Found at index 8

Input : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 30 Output : Not found

Input : arr[] = {30, 40, 50, 10, 20}, key = 10
Output : Found at index 3

Input Format

First line reads the number of elements N in the array Second line reads N integers i.e. elements of the array Third line reads the key to be searched

Constraints

Time Complexity must be O(log N)

Output Format

Found at index 3

Not found

Sample Input 0

5
4 5 1 2 3
2
Sample Output 0

Found at index 3
Sample Input 1

3
5 6 3
4
Sample Output 1

Not found
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int *arr=NULL;
int n;
int check=0,l,r;
void search(int key, int start,int cur)
{
    if(arr[cur]==key)
    {
         cout<<"Found at index "<<cur;
        check=1;
        return;
    }
    else 
    {
        if(cur==start)
        {
            if(arr[cur]<key)
            {
                r = 1;
                l = 0;
            }
            else
            {
                r = 0;
                l = 1;
            }
        }
        if(arr[cur]<key && cur+1!=start && r==1)
        {
            if(cur==n-1)
                cur=0;
            else
                cur++;
            search(key,start,cur);
        }
        else if(arr[cur]>key && cur-1!=start && l==1)
        {
            if(cur==0)
                cur=n-1;
            else
                cur--;
            search(key,start,cur);
        }
    }
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin>>n;
    if(n>0)
    {
    int min,minp=0;
    arr = new int[n];
    cin>>arr[0];
    min = arr[0];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<min)
        {
            min = arr[i];
            minp=i;
        }
    }
    int key;
    cin>>key;
    search(key,minp,minp);
    if(check==0)
        cout<<"Not found";
    }
    return 0;
}
