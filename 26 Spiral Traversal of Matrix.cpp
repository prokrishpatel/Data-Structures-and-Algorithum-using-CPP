/*
Given a M X N matrix, traverse the matrix in spiral form in clock-wise.

Input:
M = 4, N = 3
matrix[][] = {{1, 2, 3},
{4, 5, 6},
{7, 8, 9},
{10, 11, 12}}
Output:
1 2 3 6 9 12 11 10 7 4 5 8

Input Format

first line reads the M and N
Next M lines reads the elemnts of the matrix

Example:
2 3
1 2 3
4 5 6

Constraints

1 <= M < 100
1 <= N <100

Output Format

prints the spiral traversal of Matrix in 1 line

Example:

1 2 3 6 5 4

Sample Input 0

3 4
1 2 3 4
5 6 7 8
9 10 11 12
Sample Output 0

1 2 3 4 8 12 11 10 9 5 6 7
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int m;
int n;
int **matrix;
void spiral(int top,int down,int right,int left,int dir)
{
    if(top<=down && left<=right)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
                cout<<matrix[top][i]<<" ";
            top++;
        }
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
                cout<<matrix[i][right]<<" ";
            right--;
        }
        else if(dir==2)
        { 
            for(int i=right;i>=left;i--)
                cout<<matrix[down][i]<<" ";
            down--;
        }
        else if(dir==3)
        {
            for(int i=down;i>=top;i--)
                cout<<matrix[i][left]<<" ";
            left++;
        }
        dir = (dir+1)%4;
        spiral(top,down,right,left,dir);
        
    }
}
/*void spiral(int top,int down,int right,int left)
{
    int dir=0;
    while(top<=down && left<=right)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
                cout<<matrix[top][i]<<" ";
            top++;
        }
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
                cout<<matrix[i][right]<<" ";
            right--;
        }
        else if(dir==2)
        { 
            for(int i=right;i>=left;i--)
                cout<<matrix[down][i]<<" ";
            down--;
        }
        else if(dir==3)
        {
            for(int i=down;i>=top;i--)
                cout<<matrix[i][left]<<" ";
            left++;
        }
        dir = (dir+1)%4;
        
    }
}*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    cin>>m>>n;
    matrix = new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    spiral(0,m-1,n-1,0,0);
    return 0;
}
