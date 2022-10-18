/*
Krishna has shown one magic to reverse the given string. He asked his friend that can you write a code to check the given string is palindrome or not.

Sample 1: Line 1: Enter the string : amma Line 2: Palindrome

Sample 1: Line 1 : Enter the expression : papa Line 2 : Not Palindrome

Input Format

User should pass the input in formate of string

Constraints

String expression length should > 0

Output Format

The result will display as Palindrome or Not Palindrome.

Sample Input 0

malayalam
Sample Output 0

Palindrome 
Explanation 0

Line 1 : Enter the expression : malayalam Line 2 : Palindrome
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char *stack=NULL;
int n,top=-1;

void push(char x)
{
    stack[++top]=x;
}
void pop()
{
    if(top!=-1)
        top--;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    n = s.length();
    stack = new char[n];
    for(int i=0;i<n;i++)
        push(s[i]);
    
    for(int i=0;i<n;i++)
    {
        if(s[i]!=stack[top])
        {
            cout<<"Not Palindrome";
            exit(0);
        }
        pop();
    }
    cout<<"Palindrome";
    return 0;
}
