#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> path;



void dfs(vector<vector<int>>& g,int s,int n) {//邻接矩阵。起点为s，终点为n

    if (s==n) {
        res.push_back(path);
        return ;
    }
    // 邻接矩阵
    for (int i=1;i<=n;i++) {
        if (g[s][i]==1) {
            path.push_back(i);
            dfs(g,i,n);
            path.pop_back(i);
        }
    }

    return ;
}


int main()
{
    邻接矩阵
    int n,m,s,t;
    cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>(n+1,0));//邻接图
    while (m--) {//输入起点、终点
        cin>>s>>t;
        g[s][t]=1;
    }


    
    path.push_back(1);
    dfs(g,1,n);//起点为1，终点为n

    if (res.size()==0) cout<<-1<<endl;
    for (vector<int> pa:res) {
        for (int i=0;i<pa.size()-1;i++) {
            cout<<pa[i]<<" ";
        }
        cout<<pa[pa.size()-1]<<endl;
    }

    return 0;
}