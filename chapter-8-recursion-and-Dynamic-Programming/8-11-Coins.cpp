#include <iostream>
#include <vector>
using namespace std;

int ways(int amount, vector<int> denom){

	if (!amount){
		return 1;
	}
	
	int n = denom.size();
	if(n==1){
		if(amount%denom[0])
			return 0;
		else
			return 1;
	}
	int curr = denom[n-1]; 
	int sum = 0;
	denom.pop_back();
	sum += ways(amount,denom);
	while(amount>=curr){
		sum += ways(amount-curr,denom);
		amount = amount-curr;
	}
	return sum;
} 

int main(){	
	int amount = 8;
	vector<int> denom;
	denom.push_back(2);
	denom.push_back(3);

	cout<<ways(amount,denom)<<endl;
}
