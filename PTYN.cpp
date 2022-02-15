#include <iostream>
#include <fstream>
using namespace std;
int m, n;
int a[200][200];
int main()
{
	//freopen("Yenngua.inp","r",stdin);
	//freopen("Yenngua.out","w",stdout);
	cin >> m >> n;
	int res = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int ok = 0;
			for(int k=1;k<=n;k++) if(a[i][k] < a[i][j]) ok = 1;
			for(int k=1;k<=m;k++) if(a[k][j] > a[i][j]) ok = 1;
			if(ok == 0){
				res++;
				cout<<"("<<i<<","<<j<<")"<<endl;
			}
				
		}
	}
	if(res == 0) cout<<"Khong co phan tu yen ngua"<<endl;
	return 0;
}