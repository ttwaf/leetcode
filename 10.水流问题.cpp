#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};

void dfs(vector<vector<int>>& g,vector<vector<bool>>& vst,int x,int y) {
	vst[x][y]=true;
	
	for (int i=0;i<4;i++) {
		int nx=x+d[i][0];
		int ny=y+d[i][1];
		if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
		if (vst[nx][ny] || g[nx][ny]<g[x][y]) continue;//�ų����Լ��Ǹߵص���� 
		//����֮��ֻ���Ǻϸ�ģ����ߵĻ�����ȷ���ȡtrue 
		//�о�д�����д��������vst�Ļ���û���� 
		dfs(g,vst,nx,ny);
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
	vector<vector<bool>> lu(n+1,vector<bool>(m+1,false));//left,up���� 
	vector<vector<bool>> rd(n+1,vector<bool>(m+1,false));//right,down���� 
	
	for (int i=0;i<n;i++) {
		dfs(g,lu,i,0);
		dfs(g,rd,i,m-1);
	}
	for (int j=0;j<m;j++) {
		dfs(g,lu,0,j);
		dfs(g,rd,n-1,j);
	}
	
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (lu[i][j] && rd[i][j]) cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}

