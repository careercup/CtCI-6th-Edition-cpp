#include <vector>
#include <iostream>
using namespace std;

int multiply(int a, int b, vector<int>& dp)
{
	int bigger = a < b ? b:a;
	int smaller = a <b ? a:b;

	if (smaller==0)
		return 0;

	if (smaller==1)
		return bigger;

	if (dp[smaller]!=-1)
		return dp[smaller];

	int s = smaller >> 1; //divide by 2

	int side1 = multiply(s,bigger,dp);
	int side2 = 0;
	if (smaller%2)
		side2 = side1+bigger;
	else
	    side2 = side1;
	
	dp[smaller] = side2 +side1;
	return side1+side2;
}

int main()
{	
	int m = 7, n = 6;
	int smaller = m>n?n:m;
	int bigger = m>n?m:n;
	std::vector<int> dp(smaller+1,-1);
	cout<<multiply(smaller,bigger,dp)<<endl;
	return 0;
}
