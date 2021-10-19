#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	long long sum=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		sum=sum^x;
	}
	cout<<sum<<endl;
	return 0;
}