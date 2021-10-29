// Count number of bits to be flipped
// to convert A into B
//idea is to count number of set bits in XOR of given 2 numbers means bits at those position are different that leads their XOR to be set
//eg.  29:   1 1 1 0 1
//     15:   0 1 1 1 1
//  29^15:   1 0 0 1 0
// so number of set bits in (29^15) is equal to number of different bit in 29 & 15 that needed to be flipped.
#include <iostream>
using namespace std;
 
// Function that count set bits
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= (n-1);
    }
    return count;
}
 
// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
    // Return count of set bits in
    // a XOR b
    return countSetBits(a^b);
}
 
// Driver code
int main()
{
    int a = 29;
    int b = 15;
    cout << FlippedCount(a, b)<<endl;
    return 0;
}
