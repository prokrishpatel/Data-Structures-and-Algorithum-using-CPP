/*
Radha asked to her friend can you verify that given expression have balanced parenthesis or not, So her decided to write a code to examine that the given an string expression whether have the pairs of parenthesis are balanced or not. The orders of “(“, “)”, “[“, “]” ,“{“, “}”,are correct in the given expression.


Sample 1: Line 1: Enter the expression : {}{[()]} Line 2: Balanced
Sample 2: Line 1 : Enter the expression : [(]) Line 2 : Not Balanced

Input Format

User enter the paris of parentheses without any operand.

Constraints

String expression length should > 0

Output Format

The result will display as parenthesis is balanced or not.

Sample Input 0

(){}[][{()()}]{()}
Sample Output 0

Balanced
Explanation 0

1: Enter the expression : (){}[][{()()}]{()} Balanced

Enter the expression : ({}[]}] Not Balanced
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;

stack<char> bracket;
void check(string s)
{
    int n= s.length();
    for(int i=0;i<n;i++)
    {
        if(bracket.empty())
        {
            bracket.push(s[i]);
        }
        else if((bracket.top()=='{' && s[i]=='}')||(bracket.top()=='(' && s[i]==')')||(bracket.top()=='[' && s[i]==']'))
        {
            bracket.pop();
        }
        else{
            bracket.push(s[i]);
        }
    }
    if(bracket.empty())
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    string br;
    cin>>br;
    check(br);
    return 0;
}
