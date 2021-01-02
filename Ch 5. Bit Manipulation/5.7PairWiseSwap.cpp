using namespace std;

#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter Number\n";
	cin>>n;

	/*Calculated the mask*/
	int buf_odd=n;
	int buf_even=n;
	int mask_odd=1<<1;
	int mask_even=1;
	while(buf_odd>0){
		mask_odd = mask_odd |(mask_odd<<2);
		buf_odd>>=2;
	}
	while(buf_even>0){
		mask_even = mask_even | (mask_even<<2);
		buf_even>>=2;
	}
	
	/*AND operation with mask and number and shifting one right shift to 
	get odd index digitis and shift left for even index digits */
	int result= (mask_odd&n)>>1 | (mask_even&n)<<1;
	
	/* Directly providing the mask for 32 bit*/
	int new_result=((n&0xaaaaaaaa)>>1) | ((n&0x55555555)<<1);
	cout<<new_result<<"\n";
	cout<<result;
	return 0;
}