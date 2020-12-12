//  Created on: 02/12/2020 (dd/mm/yyyy)
// 
//  Question 10.1
//  Sorted Merge
//  
//  Explanation:
//  To merge the two arrays, we keep an index of the current element in arrays A and B, and compare the values
//  each time to determine which element will be chosen. To avoid creating a third array that holds each value
//  temporarily, we start from the end where A has empty space, so that we can use A without overwriting any
//  elements.
#include <iostream>

void merge(int A[], int N, int B[], int M)
{
    int i = N-1; // current index for array A
    int j = M-1; // current index for array B
    int k = N+M-1; // current index for merged array

    while (i >= 0 && j >= 0) {
        if (i < 0) {
            // if we are done with A, just copy the rest of B to the merged array
            // if we are done with B, then no need to do anything
            while (j >= 0) {
                A[k] = B[j];
                j--;
                k--;
            }
            break;
        }
        if (A[i] <= B[j]) {
            A[k] = B[j];
            j--;
        }
        else {
            A[k] = A[i];
            i--;
        }
        k--;
    }

    return;
}

int main()
{
    // As an example, we can use:
    int A[5] = {1, 3, 5, 7, 9};
    int B[4] = {2, 4, 6, 8};
    
    // print arrays before
    std::cout << "\nArray A before: ";
        for (int a = 0; a < 5; a++) {
        std::cout << A[a] << " ";
    }
    std::cout << "\nArray B before: ";
    for (int a = 0; a < 4; a++) {
        std::cout << B[a] << " ";
    }

    merge(A, 5, B, 4);

    // print merged array
    int total_size = 4+5;
    std::cout << "\nMerged Array: ";
    for (int a = 0; a < total_size; a++) {
        std::cout << A[a] << " ";
    }

    return 0;
}