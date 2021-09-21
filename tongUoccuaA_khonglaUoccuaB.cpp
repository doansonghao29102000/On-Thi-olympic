#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	long long A,B;
	cin>>A>>B;
	long long sum=A;
	if(B==1){
		for(long long i=2;i<sqrt(A);i++){
			if(A%i==0) sum=sum+i+A/i;
		}
		if((long long)sqrt(A)*(long long)sqrt(A)==A) 
		cout<<sum+(long long)sqrt(A)<<endl;
	      else cout<<sum<<endl;
	}
	else{ 
	      long long sum=0;
		if(A==1 || A==B || A%B==0) cout<<0<<endl;
		else{ 
	            for(long long i=2;i<=sqrt(A);i++){
                           if(A%i==0){
			                if(B%i==0){
	                                   if(B%(A/i)!=0) sum=sum+A/i;
		                      }
			                else{
				                 if(B%(A/i)!=0) sum=sum+i+A/i;
				                 else sum=sum+i;
			                }
                          }

                  }
                  cout<<sum+A;					
		}
	}
	return 0;
}
