//We count the number of unique paths from top left corner to the bottom right corner.
//Dynamical Programming approach

#include <iostream>
int cntways(int m, int n)
{
    int ways[m][n];                                         //m is the number of rows and n is the number of columns of this grid
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(i == 0 && j == 0)                            //base case, the number of path to origin is 1
                ways[i][j] = 1;
            else if(i == 0)
                ways[i][j] = ways[i][j-1];                  //if row number is zero, then the path to here can only from left
            else if(j == 0)
                ways[i][j] = ways[i-1][j];                  //if column number is zero, then the path to here can only from top
            else
                ways[i][j] = ways[i-1][j] + ways[i][j-1];   //for a general grid point, the path to here can from left or top
        }
    }

    return ways[m-1][n-1];
}
// Driver program to test above functions
int main ()
{
    int m = 8, n = 3;  //The problem in the book is for m=3.
    printf("Number of paths = %d", cntways(m, n));
    return 0;
}
