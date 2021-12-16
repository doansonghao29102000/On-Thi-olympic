#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
long UCLN(long m, long n)
{
	long a = m;
	long b = n;
	if(b == 0) return a;
	else return UCLN(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("BAI1.inp","r",stdin);
	freopen("BAI1.out","w",stdout);
	long a, b , c;
	cin >> a >> b >> c;
	if(c/a > c/b){
		for(long long int y=1;y<=c/b;y++){
		       if((c-b*y)%a == 0 && (c-b*y)/a>0){
       			if(UCLN((c-b*y)/a,y) == 1) cout<<(c-b*y)/a<<" "<<y<<endl;
       		}
		}
	}
	else{
		for(long x=1;x<=c/a;x++){
		       if((c-a*x)%b == 0 && (c-a*x)/b>0) {
       			if(UCLN(x,(c-a*x)/b) == 1) cout<<x<<" "<<(c-a*x)/b<<endl;
       		}
		}
	}
	return 0;
}