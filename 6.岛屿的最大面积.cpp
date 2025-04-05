#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};

void dfs(vector<vector<int>>& g,vector<vector<bool>>& vst,int x,int y,int &num) {
	
	for (int i=0;i<4;i++) {
		int nx=x+d[i][0];
		int ny=y+d[i][1];
		if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
		if (!vst[nx][ny] && g[nx][ny]==1) {
			vst[nx][ny]=true;
			num++;
			dfs(g,vst,nx,ny,num);
		}
	}
	return ;
}

void check() {
	
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
	
	vector<vector<bool>> vst(n+1,vector<bool>(m+1,false));
	int res=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			int num=0;//ÿ�鵺�춼���¼��� 
			if (!vst[i][j] && g[i][j]==1) {//��ÿ�鵺�� 
				vst[i][j]=true;
				num++;
				dfs(g,vst,i,j,num);//����������½���ѳ���
				res=max(res,num);
				//���һ�� 
//				cout<<res<<endl;
//				for (int i=0;i<n;i++) {
//					for (int j=0;j<m;j++) {
//						cout<<vst[i][j]<<" ";
//					}
//					cout<<endl;
//				}
//				cout<<endl;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}

