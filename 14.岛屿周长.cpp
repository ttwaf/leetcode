#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};

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
	int res=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (g[i][j]==1) {//如果是陆地的话 
				for (int k=0;k<4;k++) {//下右上左四个方向。 
					int nx=i+d[k][0];
					int ny=j+d[k][1];
					if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()
					|| g[nx][ny]==0)//到边界或者水域的话说明是边长了 
					 res++;
				}
			}
		} 
	}
	cout<<res<<endl;
	return 0;
}

