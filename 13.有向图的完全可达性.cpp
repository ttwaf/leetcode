#include<bits/stdc++.h>
using namespace std;

void dfs(vector<list<int>>& g,int s,vector<bool>& vst) {

//	list<int> t=g[s];//取出它的所有邻点 
//	for (int i:t)
	for (int i:g[s]) {//对list里的每个邻点 
		if (vst[i]==false) {//如果没见过的话 
			vst[i]=true;
			dfs(g,i,vst);
		}
	}
}

int main()
{
	int n,m,s,t;
	cin>>n>>m;
	vector<list<int>> g(n+1);//邻接表 
	while (m--) {
		cin>>s>>t;
		g[s].push_back(t);
	}
	vector<bool> vst(n+1,false);
	vst[1]=true;
	dfs(g,1,vst);
	
	for (int i=1;i<=n;i++) {
		if (vst[i]==false) {
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	return 0;
}

