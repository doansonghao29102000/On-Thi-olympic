#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

void DocTep(int a[], int &n)
{
	ifstream file;
	file.open("C:\\Users\\Admin\\Desktop\\Primes.inp", ios_base::in);
	file >> n;
	for(int i=0;i<n;i++) file >> a[i];
	file.close();
}
bool KiemTraSNT(int &x)
{
	if(x < 2) return false;
	else
	{
		if(x == 2) return true;
		else{
			if(x%2 == 0) return false;
			else{
				for(int i=2;i<=int(sqrt(x));i++){
					if(x%i == 0){
						return false;
						break;
					}
				}
			}
		}
	}
	return true;
}
long TinhTong(int a[], int &n)
{
	long sum = 0;
	for(int i=0;i<n;i++){
		if(KiemTraSNT(a[i]) == true) sum = sum + a[i];
	}
	return sum;
}
void GhiTep(long s)
{
	ofstream file;
	file.open("C:\\Users\\Admin\\Desktop\\Primes.out", ios_base::out);
	file << s <<endl;
	file.close();
}
int main()
{
	int a[1000], n;
	DocTep(a,n);
	long s = TinhTong(a,n);
	GhiTep(s);
	system("PAUSE");
	return 0;
}