#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const int MAX = 20;
int A[MAX], C[MAX], Bang[MAX][MAX], n, M;
int KyLuc()
{
	int GTLN = 0;
	for(int i=0;i<=M;i++){
		if(GTLN < Bang[n][i]) GTLN = Bang[n][i];
	}
	return GTLN;
}
int main()
{
	freopen("C:\\Users\\Admin\\Desktop\\dynamic.inp","r",stdin);
	freopen("C:\\Users\\Admin\\Desktop\\dynamic.out","w",stdout);
	cin >> n >> M;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) cin>>C[i];
	Bang[n+1][M+1];
	for(int i=0;i<=M;i++) Bang[0][i] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=M;j++){
			if(A[i] > j){
				Bang[i][j] = Bang[i-1][j]; 
			}
			else{
				Bang[i][j] = max(Bang[i-1][j],Bang[i-1][j-A[i]]+C[i]);
			}
			
		}
	}
	cout<<KyLuc()<<endl;
	return 0;
}