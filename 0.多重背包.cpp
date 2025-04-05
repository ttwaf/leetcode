#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> w(n+1,0),v(n+1,0),u(n+1,0);
    for (int i=0;i<n;i++) cin>>w[i];
    for (int i=0;i<n;i++) cin>>v[i];
    for (int i=0;i<n;i++) cin>>u[i];

    vector<int> dp(m+1,0);
    //不用初始化
    for (int i=0;i<n;i++) {//矿石一种一种放
        for (int j=m;j>=w[i];j--) {//空间的限制.还是当01背包。每种考虑一次
            for (int k=1;k<=u[i] && k*w[i]<=j;k++) {//数量的限制与空间的限制
                dp[j]=max(dp[j],dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}