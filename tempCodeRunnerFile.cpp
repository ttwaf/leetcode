#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> w,v;
    for (int i=0;i<n;i++) cin>>w[i]>>v[i];
    vector<int> dp(m+1);

    for (int i=0;i<n;i++) {//把一个个物品放入背包
        for (int j=w[i];j<=m;j++) {//腾出空间看放不放的下
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m];

    return 0;
}