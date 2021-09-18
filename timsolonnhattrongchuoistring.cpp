#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
long long chuyensangso(string s){
	long long sum=0;
	for(int i=0;i<s.length();i++){
		sum=sum*10+(int(s[i])-48);
	}
	return sum;
}
int main(){
	string s;
	getline(cin,s);
	int a[s.length()];
	vector<int> v1;
	vector<int> v2;
	for(int i=0;i<=s.length();i++) a[i]=0;
	for(int i=0;i<s.length();i++){
		if((s[i]>47 && s[i]<58) || s[i]==45) a[i]=1;	
	}
	for(int i=0;i<s.length();i++){
		if(a[i]==1 && a[i+1]==0) v1.push_back(i);
		 
	}
	if(a[0]==1){
		v2.push_back(0);
		for(int i=v1[0]+1;i<s.length();i++){
			if(a[i]==0 && a[i+1]==1) v2.push_back(i+1);
		}
	}
	else{
		for(int i=1;i<s.length();i++){
			if(a[i]==0 && a[i+1]==1) v2.push_back(i+1);
		}
	}
	long long max=chuyensangso(s.substr(v2[0],v1[0]-v2[0]+1));
	for(int i=1;i<v1.size();i++){
		if(max<chuyensangso(s.substr(v2[i],v1[i]-v2[i]+1))){
			max=chuyensangso(s.substr(v2[i],v1[i]-v2[i]+1));
		}
	}
	cout<<max;
	return 0;
}