#include <iostream>
#include <fstream>
using namespace std;
int n, m, s, t;
int a[1000][1000] = {0};
bool visited[1000] = { false };
int p[1000], p_min[1000];
int cp_min = 9000;
void DocTep()
{
	ifstream f;
	int u, v, w;
	f.open("Timduong.inp");
	f >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		f >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	f.close();
}

// hàm tìm duong
void TimDuong(int u, int cp)
{
	for(int v =1; v<=n; v++)
		if ((visited[v]==false) && (a[u][v] != 0))
		{
			visited[v] = true;
		//	p[v] = u;
			cp = cp + a[u][v];
			if (v == t) {
				if (cp < cp_min) 
				{
					cp_min = cp;
					//for (int i = 1; i <= n; i++)
					//	p_min[i] = p[i];
				}
			}
			else
				TimDuong(v, cp);

			visited[v] = false;
			cp = cp - a[u][v];			 
		}	 
}

void GhiTep()
{
	ofstream f;
	f.open("Timduong.out");
	if (cp_min == 9000)
		f << "Khong ton tai duong di tu " << s << " den " << t << endl;
	else
	f << cp_min;
	f.close();
}
int main()
{
	DocTep();
	visited[s] = true;
	TimDuong(s, 0);
	GhiTep();
	system("PAUSE");
    return 0;
}
