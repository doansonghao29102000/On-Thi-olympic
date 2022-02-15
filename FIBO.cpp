#include <iostream>
#include <string>
#include <sstream>
using namespace std;
long long f[100];
long long n;
int main()
{
      //freopen("Fibo.inp","r",stdin);
	//freopen("Fibo.out","w",stdout);
	cin>>n;
	long long a = n;
	f[1] = 1;
	f[2] = 1;
	for(int i=3;i<=47;i++){
		f[i] = f[i-1] + f[i-2];
	};
      ostringstream convert;
	convert << a;
	string res = convert.str() + " = ";
	int i=46;
      while(i>0){
		if(f[i] <= n){
			n=n-f[i];
			ostringstream convert;
			convert << f[i];
			res = res + convert.str() + " + ";
		}
		i--;
	}
	if(n != 0) cout<<"Khong bien doi duoc"<<endl;
	else{
		cout<<res.substr(0,res.size()-3)<<endl;
	}
      cout<<f[47]<<endl;
	return 0; 
}