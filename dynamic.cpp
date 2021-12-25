// Bai 1_Doan Song Hao
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const int MAX = 20;
int A[MAX], C[MAX], BangPa[MAX][MAX], BangCnt[MAX][MAX] ,n, M;
void TruyVet()
{
	int j=M; 
	for(int i=n;i>0;i--){
		if(BangCnt[i][j]!=0){
			cout<<"Mon hang thu "<<i<<" Co Khoi Luong va Gia Tri la ";
			cout<<A[i]<<" va "<<C[i]<<" lay "<<BangCnt[i][j]<<" lan!!!"<<endl;
			j=j-BangCnt[i][j]*A[i];
		}
	}
}
int KyLuc()
{
	int GTLN = 0;
	for(int i=0;i<=M;i++){
		if(GTLN < BangPa[n][i]) GTLN = BangPa[n][i];
	}
	return GTLN;
}
int main()
{
	/*
      freopen("C:\\Users\\Admin\\Desktop\\dynamic.inp","r",stdin);
	freopen("C:\\Users\\Admin\\Desktop\\dynamic.out","w",stdout);*/
	cin >> n >> M;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) cin>>C[i];
	BangPa[n+1][M+1];
	BangCnt[n+1][M+1];
	for(int i=0;i<=M;i++) BangPa[0][i] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=M;j++){
			BangPa[i][j] = BangPa[i-1][j];
			BangCnt[i][j] = 0;
			if(j >= A[i]){
				for(int k=1;k<=j/A[i];k++){
					if(BangPa[i][j] < BangPa[i-1][j-A[i]*k]+C[i]*k){
						BangPa[i][j] = BangPa[i-1][j - A[i] *k] + C[i] *k;
						BangCnt[i][j] = k;

					}
				} 
			}
			
		}
	}
	cout<<"\nBang Phuong An"<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=M;j++){
			cout<<BangPa[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"\nBang Dem So Lan Cac Mon Hang Co The Lay"<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=M;j++){
			cout<<BangCnt[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"\nGia tri lon nhat co the lay duoc la : "<<KyLuc()<<endl;
	cout<<"\nCach lay cac mon hang la:"<<endl;
	TruyVet();
	return 0;
}