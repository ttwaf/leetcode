#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> vec(n+1,vector<int>(m+1,0));
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int x;
			cin>>x;
			//��1��ʼ�Ͳ��������ˡ����൱����ͬ��䡣 
			vec[i][j]=vec[i-1][j]+vec[i][j-1]-vec[i-1][j-1]+x;//��άǰ׺�� 
		}
	}
	
	int ans=INT_MAX;
	for (int i=1;i<=n;i++) {
		//��һ���õ���벿�ֵĺ͡��������ľ���ֵ�͵õ�ǰ�������ֵĲ�ֵ 
		int x=abs(vec[n][m]-vec[i][m]-vec[i][m]);
		ans=min(ans,x);//������Сֵ 
	} 
	for (int j=1;j<=m;j++) {//���ű��� 
		int x=abs(vec[n][m]-vec[n][j]-vec[n][j]);//ͬ��
		ans=min(ans,x); 
	}
	cout<<ans<<endl;
	return 0;
}

