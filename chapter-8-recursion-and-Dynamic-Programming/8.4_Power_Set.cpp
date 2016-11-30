//We use the solution 2 described in the book.
//Namely, for a set with length n, we simply iterate over all binary numbers with n bits.
//For each number, the corresponding set is constrcted as follows:
//if ith position is 1, then we put ith element into the set.
//otherwise, we do not select ith element.
//Each number corresponds exactly to one set.
#include <stdio.h>
#include <math.h>
#include <iostream>


void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is 2**n, empty set included*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then print jth element from set */
          if(counter & (1<<j))             //shift 1 to the jth position,
                                           //counter & (1<<j) extracts the jth element of this binary number
            printf("%c", set[j]);
       }
       printf("\n");
    }
}

/*Driver program to test printPowerSet*/
int main()
{
    char set[] = {'a','b','c','d'};
    printPowerSet(set, 4);
    return 0;
}
