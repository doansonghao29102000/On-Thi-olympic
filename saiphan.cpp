#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int MAX = 1001;
long a[MAX], d[MAX];
int n;
void ReadFile()
{
	ifstream fi;
	fi.open("C:\\Users\\Admin\\Desktop\\Code.inp", ios_base::in);
	fi >> n;
	for(int i=0;i<n;i++) fi >> a[i];
	fi.close();
}
void SaiPhan()
{
	d[0] = a[0];
	for(int i=1;i<n;i++){
		d[i] = a[i] - a[i-1];
	}
}
long MaxSP()
{
	long max = d[0];
	for(int i=1;i<n;i++){
		if(max < d[i]) max = d[i];
	}
	return max;
}
long MinSP()
{
	long min = d[0];
	for(int i=1;i<n;i++){
		if(min > d[i]) min = d[i];
	}
	return min;
}
void WriteFile()
{
	ofstream fo;
	fo.open("C:\\Users\\Admin\\Desktop\\Code.out", ios_base::out);
	long x = MaxSP();
	long y = MinSP();
	double kq = log(x-y+1)/log(2);
	fo << ceil(kq)*n << endl;
	fo.close();
}
int main(){
	ReadFile();
	SaiPhan();
	WriteFile();
	system("PAUSE");
	return 0;
}