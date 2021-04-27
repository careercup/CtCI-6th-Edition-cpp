// C++ Program for Iterative Tower of Hanoi
#include <math.h>
#include <stack>
#include <limits.h>
#include <iostream>
using namespace std;

//Function to show the movement of disks
void moveDisk(const char *fromPeg, const char *toPeg, int disk)
{
    printf("Move the disk %d from \'%s\' to \'%s\'\n",
           disk, fromPeg, toPeg);
}

// Function to implement legal movement between
// two poles
void moveDisksBetweenTwoPoles(stack<int> &start, stack<int> &dest, const char *s, const char *d)
{
    int pole1TopDisk, pole2TopDisk;
    if (!start.empty())
    {
        pole1TopDisk = start.top();
        start.pop();
    } else {
        pole1TopDisk = INT_MIN;
    }

    if (!dest.empty())
    {
        pole2TopDisk = dest.top();
        dest.pop();
    } else {
        pole2TopDisk = INT_MIN;
    }


    // When pole 1 is already empty [Condition pole1TopDisk == INT_MIN is different than stack.empty(),
    // which checks whether the stack is empty AFTER pop an element!
    if (pole1TopDisk == INT_MIN)
    {
        start.push(pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }

    // When pole2 pole is already empty
    else if (pole2TopDisk == INT_MIN)
    {
        dest.push(pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }

    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk > pole2TopDisk)
    {
        start.push(pole1TopDisk);
        start.push(pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }

    // When top disk of pole1 < top disk of pole2
    else
    {
        dest.push(pole2TopDisk);
        dest.push(pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}



//Function to implement TOH puzzle
void tohIterative(int num_of_disks, stack<int> &start, stack<int> &aux, stack<int> &dest)
{
    int i, total_num_of_moves;
    const char* s = "Starting", *d = "Destination", *a = "Auxiliary";

    //If number of disks is even, then interchange
    //destination pole and auxiliary pole
    if (num_of_disks % 2 == 0)
    {
        const char *temp = d;
        d = a;
        a  = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;

    //Larger disks will be pushed first
    for (i = num_of_disks; i >= 1; i--)
        start.push(i);

    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
          moveDisksBetweenTwoPoles(start, dest, s, d);

        else if (i % 3 == 2)
          moveDisksBetweenTwoPoles(start, aux, s, a);

        else if (i % 3 == 0)
          moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

// Driver Program
int main()
{
    // Input: number of disks
    unsigned num_of_disks = 3;

    stack<int> start, dest, aux;

    tohIterative(num_of_disks, start, aux, dest);
    return 0;
}
