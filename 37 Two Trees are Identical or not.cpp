/*
Write a code to identified that the two given trees are identical or not.

Input Format

First line reads the number of nodes N for Tree_1 second line reads the N elements of the tree Example: 5 20 30 10 15 25

Third line reads the number of nodes M for Tree_2
Fourth line reads the M elements of the tree Example: 5 20 30 10 15 25

Constraints

N > 0 M > 0

Output Format

Both trees are identical or Both trees are not identical

Sample Input 0

5
1 2 3 4 5
5
1 3 2 5 4
Sample Output 0

Both trees are not identical
Explanation 0

Enter number of node for Tree_1: 5 Enter 5 node for Tree_1 : 1 2 3 4 5 Enter number of node for Tree_2: 5 Enter 5 node for Tree_2 : 1 3 2 5 4

Contest ends in 15 hours
Submissions: 8
Max Score: 5
Difficulty: Medium
Rate This Challenge:

    
More

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n1,n2;
    cin>>n1;
    int t1[n1];
    for(int i=0;i<n1;i++)
    {
        cin>>t1[i];
    }
    cin>>n2;
        if(n1!=n2)
        {
            cout<<"Both trees are not identical";
            return 0;
        }
    int t2[n2];
    for(int i=0;i<n2;i++)
    {
        cin>>t2[i];
    }
    for(int i=0;i<n1;i++)
    {
        if(t1[i]!=t2[i])
        {
            cout<<"Both trees are not identical";
            return 0;
        }
    }
    cout<<"Both trees are identical";
    return 0;
}
