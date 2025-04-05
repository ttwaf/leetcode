#include<bits/stdc++.h>
using namespace std;

void dfs(vector<list<int>>& g,int s,vector<bool>& vst) {

//	list<int> t=g[s];//ȡ�����������ڵ� 
//	for (int i:t)
	for (int i:g[s]) {//��list���ÿ���ڵ� 
		if (vst[i]==false) {//���û�����Ļ� 
			vst[i]=true;
			dfs(g,i,vst);
		}
	}
}

int main()
{
	int n,m,s,t;
	cin>>n>>m;
	vector<list<int>> g(n+1);//�ڽӱ� 
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

