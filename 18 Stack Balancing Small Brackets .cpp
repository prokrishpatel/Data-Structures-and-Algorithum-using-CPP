/*Write a program to create a stack for characters with push, pop functions having maximum capacity of 10 then you have to create a function to check whether given expression of '(' and ')' characters is balanced or not.

Input Format

Input line can be any expression having '(' and ')' characters.

Constraints

1≤n≤10

Output Format

If the parenthesis is balanced then it will display "Balanced" otherwise it will display "Not Balanced". If expression contains more than 10 symbols then display message of "Stack Full".

Sample Input 0

(())()
Sample Output 0

Balanced
Explanation 0

Every '(' have corresponding ')' at appropriate place

Sample Input 1

(()))
Sample Output 1

Not Balanced
Explanation 1

There are only two starting '(' and three ')' so it is not balanced
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char stack[10];
int top=-1;
void push(char c)
{
    if(top==9)
    {
        cout<<"Stack Full";
        exit(0);
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
void pop()
{
    if(top!=-1)
    {
        top--;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s;
    cin>>s;
    if(s.length()>10)
    {
        cout<<"Stack Full";
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if(stack[top]==-1)
            push(s[i]);
        else if(stack[top]=='(' && s[i]==')')
            pop();
        else
            push(s[i]);
    }
    if(top==-1)
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}
