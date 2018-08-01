/*
* Author: Madhur Chauhan
* A simple log(min(a,b)) solution, but does not take more than 96 instructions
* Similar to binary exponentiation by exploiting bit pattern of multiplicand
*/
#include <vector>
#include <iostream>
using namespace std;

auto multiply=[](int a, int b){
  int big=a>b?a:b, small=a<b?a:b, res=0;
  while(small){
    if(small&1) res+=big;
    big<<=1, small>>=1;
  }
  return res;
};

int main()
{	
	int m = 7, n = 6;
	int smaller = m>n?n:m;
	int bigger = m>n?m:n;
	
	cout<<multiply(smaller,bigger,dp)<<endl;
	return 0;
}
