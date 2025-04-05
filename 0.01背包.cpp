#include<bits/stdc++.h>
using namespace std;
//滚动数组版
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> w(n+1,0),v(n+1,0);
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) cin>>v[i];
    
    vector<int> dp(m+1,0);

    //滚动数组不用初始化
    //二维数组需要初始化，因为需要从上一层继承。那么第一层初始化才能让第二层去用
    // for (int j=w[1];j<=m;j++) dp[j]=v[1];

    for (int i=1;i<=n;i++) {
        for (int j=m;j>=w[i];j--) {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    cout<<dp[m];
    return 0;
}
//下标从1开始版
int main() 
{
    int n,m;
    cin>>n>>m;
    vector<int> w(n+1,0),v(n+1,0);
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) cin>>v[i];

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    //老是忘记？大不了写完递推再回来初始化
    //初始化。从第一样东西开始，价值是第一样东西的价值
    for (int j=w[1];j<=m;j++) dp[1][j]=v[1];

    for (int i=2;i<=n;i++) {
        for (int j=0;j<=m;j++) {
        // for (int j=0;j<=m;j++) {//从第一个空间开始也行。
            if (j<w[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][m];

    return 0;
}
//下标从0开始版
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> w(n,0),v(n,0);
    for (int i=0;i<n;i++) cin>>w[i];
    for (int i=0;i<n;i++) cin>>v[i];
    
    vector<vector<int>> dp(n,vector<int>(m+1));
    
    for (int j=w[0];j<=m;j++) dp[0][j]=v[0];//从放第一样东西开始初始化。
    
    for (int i=1;i<n;i++) {
        for (int j=0;j<=m;j++) {
            if (j<w[i]) dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n-1][m]<<endl;
    return 0;
}
