// A C++ program to count number of ways to reach n't stair when
// A person can climb 1, 2, ..m stairs at a time
// We use the dynamical programming.
#include<stdio.h>

// A recursive function used by countWays
int countWays(int n, int m)
{
    int res[n+1];
    res[0] = 1;
    for (int i=1; i<=n; i++)
    {
       res[i] = 0;
       for (int j=1; j<=m && j<=i; j++)
         res[i] += res[i-j];
    }
    return res[n];
}

// Driver program to test above functions
int main ()
{
    int s = 8, m = 3;  //The problem in the book is for m=3.
    printf("Number of ways = %d", countWays(s, m));
    return 0;
}
