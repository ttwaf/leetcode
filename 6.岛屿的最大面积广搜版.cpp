#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
			0,1,
			-1,0,
			0,-1};

void bfs(vector<vector<int>>& g,vector<vector<bool>>& vst,int x,int y,int &num) {
	queue<pair<int,int>> que;
	que.push({x,y});
	while (!que.empty()) {
		pair<int,int> cur=que.front();
		que.pop();
		int cx=cur.first;
		int cy=cur.second;
		
		for (int i=0;i<4;i++) {
			int nx=cx+d[i][0];
			int ny=cy+d[i][1];
			if (nx<0 || nx>=g.size() || ny<0 || ny>g[0].size()) continue;
			if (!vst[nx][ny] && g[nx][ny]==1) {
				vst[nx][ny]=true;
				num++;
				que.push({nx,ny});
			}
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
	
	vector<vector<bool>> vst(n+1,vector<bool>(m+1,false));
	int res=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			int num=0;//每块岛屿都重新计数 
			if (!vst[i][j] && g[i][j]==1) {//对每块岛屿 
				vst[i][j]=true;
				num++;
				bfs(g,vst,i,j,num);//把所有相连陆地搜出来
				res=max(res,num);
				//检查一下 
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

