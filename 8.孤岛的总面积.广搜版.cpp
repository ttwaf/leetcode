#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};
			
//����Ҫ���������ѳ���������Ҫ½�ر亣�����Բ���vst���� 
void bfs(vector<vector<int>>& g,int x,int y) {
	g[x][y]=0;
	queue<pair<int,int>> que;
	que.push({x,y});
	g[x][y]=0;//½�ر亣��ͬʱ��������½�ض���ɺ��� 
	while (!que.empty()) {
		pair<int,int> cur=que.front();
		que.pop();
		int cx=cur.first;
		int cy=cur.second;
		for (int i=0;i<4;i++) {
			int nx=cx+d[i][0];
			int ny=cy+d[i][1];
			if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
			if (g[nx][ny]==0) continue;
			g[nx][ny]=0;
			que.push({nx,ny}); //½�ر亣�󼴿ɡ�����ֱ�������������� 
		}
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
		if (g[i][0]==1) bfs(g,i,0);//���������յ� 
		if (g[i][m-1]==1) bfs(g,i,m-1);
	}
	for (int j=0;j<m;j++) {
		if (g[0][j]==1) bfs(g,0,j);
		if (g[n-1][j]==1) bfs(g,n-1,j);
	}
	//ֱ���������ӡ����������� 
	int res=0;
	for (int i=1;i<=n-1;i++) {
		for (int j=1;j<=m-1;j++) {
			if (g[i][j]==1) res++; 
		}
	} 
	cout<<res<<endl;
	return 0;
}

