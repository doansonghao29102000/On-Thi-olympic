#include<iostream>
#include<iomanip>
using namespace std;
int binarySearch(int a[] , int &n , int &x ){
	int left=0;
	int right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(a[mid]==x){
			return mid;
		}
		else{
			if(a[mid]<x) right=mid-1;
			else left=mid+1;
		}
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<binarySearch(a,n,x);
	return 0;
}