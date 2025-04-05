#include<bits/stdc++.h>
#include<vector>
using namespace std;

int d[4][2]={1,0,
             -1,0,
			 0,1,
			 0,-1}; 
             
void dfs(vector<vector<int>>& g,vector<vector<bool>>& vst,int x,int y) {
    for (int i=0;i<4;i++) {//用四个方向当相连边 
        int nx=x+d[i][0];
        int ny=y+d[i][1];
        if (nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size()) continue;
        if (!vst[nx][ny] && g[nx][ny]==1) {
            vst[nx][ny]=true;//把所有相连的陆地都标记上 
            dfs(g,vst,nx,ny);
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
                dfs(g,vst,i,j);//把所有相连的陆地搜出来 
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
