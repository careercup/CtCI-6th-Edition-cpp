using namespace std;

#include <iostream>

int main(int argc, char const *argv[])
{
	
	/*This approach involves doing bitwise xor between two numbers and counting bit followed*/
	int n=28,m=37;
	int res=n^m;
	int count;
	while(res>0){
		if(res&1)
			count++;
		res=res>>1;
	}
	cout<<count;

	return 0;
}