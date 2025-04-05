#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};
//不是要把整个岛搜出来，而是要陆地变海洋。所以不用vst数组 
void dfs(vector<vector<int>>& g,int x,int y) {
	g[x][y]=0;//陆地变海洋。同时把相连的陆地都变成海洋。 
	for (int i=0;i<4;i++) {
		int nx=x+d[i][0];
		int ny=y+d[i][1];
		if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
		if (g[nx][ny]==0) continue; //一味跳过即可。 
		dfs(g,nx,ny);
	}
	return ;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n+1,vector<int>(m+1,0));
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin>>g[i][j];
		}
	}
	
	for (int i=0;i<n;i++) {
		if (g[i][0]==1) dfs(g,i,0);//传入起点和终点 
		if (g[i][m-1]==1) dfs(g,i,m-1);
	}
	for (int j=0;j<m;j++) {
		if (g[0][j]==1) dfs(g,0,j);
		if (g[n-1][j]==1) dfs(g,n-1,j);
	}
	//直接总面积相加。不用搜索了 
	int res=0;
	for (int i=1;i<=n-1;i++) {
		for (int j=1;j<=m-1;j++) {
			if (g[i][j]==1) res++; 
		}
	} 
	cout<<res<<endl;
	return 0;
}

