#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};
//深搜改标记 
void dfs(vector<vector<int>>& g,int x,int y) {
	g[x][y]=2;//进来之后先改了。后面可以用这个标记避免重复搜索 
	for (int i=0;i<4;i++) {
		int nx=x+d[i][0];
		int ny=y+d[i][1];
		if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
		if (g[nx][ny]==0 || g[nx][ny]==2) continue;
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
	//把不是孤岛的都改标记
	for (int i=0;i<n;i++) {
		if (g[i][0]==1) dfs(g,i,0);
		if (g[i][m-1]==1) dfs(g,i,m-1);
	}
	for (int j=0;j<m;j++) {
		if (g[0][j]==1) dfs(g,0,j);
		if (g[n-1][j]==1) dfs(g,n-1,j);
	}
	//以下两步互不影响的。可以放到同一个循环里 
	//把孤岛变成海 
	for (int i=1;i<=n-1;i++) {
		for (int j=1;j<=m-1;j++) {
			if (g[i][j]==1) g[i][j]=0;
		}
	} 
	
	//把不是孤岛的改回来。
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (g[i][j]==2) g[i][j]=1;
		}
	} 
	
	//输出
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}

