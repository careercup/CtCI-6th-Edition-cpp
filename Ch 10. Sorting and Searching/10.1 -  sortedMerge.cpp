//=======================================================================================================================================
// Name        : sortedMerge.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Given two sorted arrays, A and B, where A has a large enough bufer at the end to hold B, merge B into A in sorted order.
//=======================================================================================================================================
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> A, vector<int> B, int lastA, int lastB)
{
	int indexA = lastA;
	int indexB = lastB;
	int mergedIndex = lastA + lastB +1;

	while(indexB >= 0)
	{
		if(indexA >= 0 && A[indexA] > B[indexB])
		{
			A[mergedIndex] = A[indexA];
			indexA--;
		}
		else
		{	
			A[mergedIndex] = B[indexB];
			indexB--;
		}
		mergedIndex--;
	}
	return A;
}

int main()
{
	vector<int> b;
	b.push_back(5);
	b.push_back(7);
	b.push_back(11);
	b.push_back(20);
	b.push_back(25);

	vector<int> a(13);
	a[0] = 10;
	a[1] = 12;
	a[2] = 14;
	a[3] = 22;
	a[4] = 23;
	a[5] = 26;
	a[6] = 28;
	a[7] = 30;

	a = merge(a,b,7,4);

	for(int i=0;i<a.size();i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}