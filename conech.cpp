#include <iostream>
#include <fstream>
using namespace std;
void DocTep(long &a, long &b, long &k)
{
	ifstream file;
	file.open("C:\\Users\\Admin\\Desktop\\INPUT.TXT", ios_base::in);
	file >> a >> b >> k;
	file.close();
}
void GhiTep(long x)
{
	ofstream file;
	file.open("C:\\Users\\Admin\\Desktop\\OUTPUT.TXT", ios_base::out);
	file << x;
	file.close();
}
long Buoc_Nhay(long &a, long &b, long &k)
{
	long x;
	x = (k/2)*(a-b);
	if(k%2 == 1){
		x = x + a;
	}
	return x;
}
int main(){
	long a, b, k, x;
	DocTep(a,b,k);
	x = Buoc_Nhay(a,b,k);
	GhiTep(x);
	return 0;
}