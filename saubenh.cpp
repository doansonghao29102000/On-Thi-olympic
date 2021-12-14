#include <iostream>	
#include <fstream>
using namespace std;
const int MAX = 250;
const char TepVao[] = "C:\\Users\\Admin\\Desktop\\SauBenh.inp";
const char TepRa[]  = "C:\\Users\\Admin\\Desktop\\SauBenh.out";
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int m, n;
int d[MAX];

int a[MAX][MAX], b[MAX][MAX];
void  DocTep(){
 ifstream fi;
 fi.open(TepVao,ios::in);
 fi>>m>>n;
 for(int i=1; i<=m; i++)
	 for(int j=1; j<=n; j++)
		 fi>>a[i][j];
 fi.close();
}

void DFS(int x, int y, int step, int &num){
	b[x][y] = step;
	num = num+1;
	for(int i=0; i<4; i++)
		if ((x+dx[i]>0)&&(x+dx[i]<=m)&&(y+dy[i]>0)&&(y+dy[i]<=n))
			
			if ((b[x+dx[i]][y+dy[i]]==0)&&(a[x+dx[i]][y+dy[i]]==1))
				DFS(x+dx[i],y+dy[i], step,num);
} 

void KhoiTao(){
for(int i=1; i<=m; i++)
	for(int j=1; j<=n; j++)
		b[i][j] = 0;
}

void GhiTep(int step, int tong){
	ofstream fo;
	fo.open(TepRa,ios::out);
	fo<<tong<<endl;
	for(int t=1; t<=step; t++){
		fo<<d[t]<<" ";
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				if (b[i][j] ==t)
					fo<<"["<<i<<","<<j<<"]"<<", ";
				fo<<endl;
	}
}
int main(){
	int step =0; int num, tong=0;
	DocTep();
	KhoiTao();
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++)
			if ((b[i][j] ==0)&&(a[i][j]==1)){
			step = step+1; 
			num=0;  
			DFS(i,j,step, num);
			d[step] = num; 
			tong = tong+num; 
			}
			
			GhiTep(step, tong);
	}
	system("pause");
	return 0;
}