#include<bits/stdc++.h>
using namespace std;

int d[4][2]={1,0,
             -1,0,
			 0,1,
			 0,-1}; 
             
void bfs(vector<vector<int>>& g,vector<vector<bool>>& vst,int x,int y) {
	queue<pair<int,int>> que;
	que.push({x,y});
	vst[x][y]=true;
	while (!que.empty()) {
		pair<int,int> cur=que.front();
		que.pop();
		int cx=cur.first;
		int cy=cur.second;
		for (int i=0;i<4;i++) {
			int nx=cx+d[i][0];
			int ny=cy+d[i][1];
			if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
			if (!vst[nx][ny] && g[nx][ny]==1) {
				vst[nx][ny]=true;
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
    //标记数组防止又搜回到自己。 
    vector<vector<bool>> vst(n+1,vector<bool>(m+1,false));
    int res=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vst[i][j] && g[i][j]==1) {
            	vst[i][j]=true;
                res++;
                bfs(g,vst,i,j);//把所有相连的陆地搜出来 
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
