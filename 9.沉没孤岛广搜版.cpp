#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};
			
void bfs(vector<vector<int>> &g,int x,int y) {
	queue<pair<int,int>> que;
	g[x][y]=2;
	que.push({x,y});
	while (!que.empty()) {
		pair<int,int> cur=que.front();
		que.pop();
		int cx=cur.first;
		int cy=cur.second;
		for (int i=0;i<4;i++) {
			int nx=cx+d[i][0];
			int ny=cy+d[i][1];
			if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
			if (g[nx][ny]==2 || g[nx][ny]==0) continue;
			g[nx][ny]=2;
			que.push({nx,ny});
		}
	}
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
	
	//把不是孤岛的都改标记为2 
	for (int i=0;i<n;i++) {
		if (g[i][0]==1) bfs(g,i,0);
		if (g[i][m-1]==1) bfs(g,i,m-1);
	}
	for (int j=0;j<m;j++) {
		if (g[0][j]==1) bfs(g,0,j);
		if (g[n-1][j]==1) bfs(g,n-1,j);
	}
	//
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (g[i][j]==1) g[i][j]=0;//孤岛变海洋 
			if (g[i][j]==2) g[i][j]=1;//标记改回来 
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

