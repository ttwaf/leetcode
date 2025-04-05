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
			if (g[i][j]==1) {//�����½�صĻ� 
				for (int k=0;k<4;k++) {//���������ĸ����� 
					int nx=i+d[k][0];
					int ny=j+d[k][1];
					if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()
					|| g[nx][ny]==0)//���߽����ˮ��Ļ�˵���Ǳ߳��� 
					 res++;
				}
			}
		} 
	}
	cout<<res<<endl;
	return 0;
}

