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
			//从1开始就不用特判了。这相当于是同义句。 
			vec[i][j]=vec[i-1][j]+vec[i][j-1]-vec[i-1][j-1]+x;//二维前缀和 
		}
	}
	
	int ans=INT_MAX;
	for (int i=1;i<=n;i++) {
		//减一个得到后半部分的和。减两个的绝对值就得到前后两部分的差值 
		int x=abs(vec[n][m]-vec[i][m]-vec[i][m]);
		ans=min(ans,x);//保留最小值 
	} 
	for (int j=1;j<=m;j++) {//纵着遍历 
		int x=abs(vec[n][m]-vec[n][j]-vec[n][j]);//同理
		ans=min(ans,x); 
	}
	cout<<ans<<endl;
	return 0;
}

