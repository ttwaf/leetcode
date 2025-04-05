#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	string s;
	cin>>k>>s;
	//用库函数reverse就用迭代器反转 
	reverse(s.begin(),s.end());//整个都反转
	cout<<s<<endl;
	reverse(s.begin(),s.begin()+k);//左闭右开。结尾为 开头+长度 
	cout<<s<<endl;
	reverse(s.begin()+k,s.end());
	cout<<s<<endl;
	return 0;
}

