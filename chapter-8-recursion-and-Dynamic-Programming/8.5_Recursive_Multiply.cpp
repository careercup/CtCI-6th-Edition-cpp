#include <iostream>

/*The first method is rather simple and only add operation is used.*/
int recursive_multiply(int a, int b, int adder)
{
    if (b == 1) return a;
    a += adder;
    b--;
    return recursive_multiply(a, b, adder);
}

int multiply1(int a, int b)
{
    if (a ==0 || b == 0) return 0;
    return recursive_multiply(a, b, a);
}

/*The second method is the Solution 3 discussed in the book, where division operation is used.*/
int multiply2(int a, int b){
    if (b==1) return a;
    int b_half = b >> 1; //divide by 2
    int half_result = multiply2(a, b_half);
    if (b % 2 == 0){
        return half_result + half_result;
    }
    else {
        return half_result + half_result + a;
    }
}

int main(){
    int a = 7, b = 9;
    printf("The result from method 1 is %i \n", multiply1(a, b));
    printf("The result from method 2 is %i", multiply2(a, b));
    return 0;
}
