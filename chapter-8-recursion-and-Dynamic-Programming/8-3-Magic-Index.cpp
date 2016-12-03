#include <vector>
#include <iostream>
using namespace std;

int findMagicUtil(vector<int> v, int start, int end){
	
	int n = v.size();

	if (start<0  || end>=v.size()){		// index out of bounds
		return -1;
	}
	
	if (start>end){
		return -1;	
	}

	int mid = start + (end-start)/2;	// to avoid overflow. effectively, equals (start+end)/2
	if (mid==v[mid]){
	 	return mid;
	} 
	else{
		if (findMagicUtil(v,start,min(v[mid],mid))!=-1){
			return findMagicUtil(v,start,min(v[mid],mid));
		}
		
		return (findMagicUtil(v,max(v[mid],mid),end));
	}
}

int findMagic(vector<int> v){

	int n = v.size();
	if(n==0){
		return -1;
	}

	return findMagicUtil(v,0,n-1);
}

int main(int argc, char const *argv[])
{
	// Follow Up covered: Not Distinct
	vector<int> v; 
	v.push_back(-10);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(8);
	v.push_back(9);
	v.push_back(12);
	v.push_back(13);

	cout<<findMagic(v)<<endl;
	return 0;
}
