#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n+1,0),b(n+1,0);
	for (int i=0;i<n;i++) {
		cin>>a[i];
		if (i==0) b[i]=a[i]; 
		else b[i]=a[i]+b[i-1];
	}
	
	int x,y,sum;
	while (cin>>x>>y) {
		if (x==0) sum=b[y];
		else sum=b[y]-b[x-1];
		cout<<sum<<endl;
	}
	
	
	return 0;
}

