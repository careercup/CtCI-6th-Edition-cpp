#include <iostream>
using namespace std;

int partition(int *arr,int low,int high);

void quick(int *arr,int low,int high){
if(high>low){
int cnst=partition(arr,low,high);
quick(arr,low,cnst-1);
quick(arr,cnst+1,high);
}
}

int partition(int *arr,int low,int high){
int pivot=arr[low];
int i=low,j=high+1;

while(i<j){

do{
i++;
}
while(arr[i]<=pivot);

do{
j--;
}
while(arr[j]>pivot);

if(i<j){
int tmp=arr[i];
arr[i]=arr[j];
arr[j]=tmp;
}

}

int tmp=arr[low];
arr[low]=arr[j];
arr[j]=tmp;

/*for(int i=low;i<=high;i++)
cout<<arr[i]<<" ";
cout<<endl;*/

return j;
}

int main(){

int n;
cout<<"Enter array size "<<endl;
cin>>n;

int arr[n];
cout<<"Enter array elements "<<endl;

for(int i=0;i<n;i++)
cin>>arr[i];

quick(arr,0,n-1);
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<endl;

}
