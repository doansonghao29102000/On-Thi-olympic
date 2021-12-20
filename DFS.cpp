#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;
int n, m;//s luong dinh va canh
vector<int> adj[1001]; //lua ds ke
bool visited[1001];
void Input()
{
     cin >> n >> m;
     for(int i=0;i<m;i++){
     	   int x,y ; cin>>x>>y;
     	   adj[x].push_back(y);
     	   adj[y].push_back(x);
     }
     memset(visited, false, sizeof(visited));	
}
void DFS(int u)
{
	cout << u << " ";
	// danh dau u da duoc tham
	visited[u] = true;
	for(int v = 0; v < adj[u].size(); v++){
		if(visited[adj[u][v]] == false){
			DFS(adj[u][v]);
		}
	}
	
}
int main(){
	freopen("C:\\Users\\Admin\\Desktop\\DFS.inp","r",stdin);
	freopen("C:\\Users\\Admin\\Desktop\\DFS.out","w",stdout);
	Input();
	DFS(5);
	return 0;
}