#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int,int> mp;
	int b[n];
	int c[n];
	int d[n];
	int a[n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i][0]==a[j][0]){
				if(a[i][1]>a[j][1]) swap(a[i][1],a[j][1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		mp[a[i][0]]=a[i][1];
	}
	for(int i=0;i<n;i++){
		b[i]=a[i][0];
	}
	sort(b,b+n);
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	for(int i=0;i<n;i++){
		c[i]=b[i];
		d[i]=mp[b[i]];
		
	}
	for(int i=1;i<n;i++){
		if(c[i]<d[i-1]){
			if(d[i]<=d[i-1]) {
				swap(c[i],c[i-1]);
				swap(d[i],d[i-1]);
			}
			else  swap(c[i],c[i-1]);
		}
	}
	int MAX=0;
	for(int i=0;i<n;i++){
		c[i]=d[i]-c[i];
		if(MAX<c[i]) MAX=c[i];
	}
	cout<<MAX<<endl;
	return 0;
}