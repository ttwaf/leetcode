#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int cnt=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]>='0' && s[i]<='9') cnt++;
	}
	
	int idx1=s.size()-1;//旧长度的序号 
	//扩容。 
	s.resize(s.size()+cnt*5);//每个数字翻6倍的长度，就是每个数字加5个长度
	int idx2=s.size()-1;//新长度的序号 
	
	//新旧长度一起开始移动 
	while (idx1>=0) {//从后向前填充，避免数组的移动 
		//遇到数字的话 
		if (s[idx1]>='0' && s[idx1]<='9') {
			s[idx2--]='r';
			s[idx2--]='e';
			s[idx2--]='b';
			s[idx2--]='m';
			s[idx2--]='u';
			s[idx2--]='n';
		} else {//遇到字母的话照常复制 
			s[idx2--]=s[idx1];
		}
		idx1--;
	} 
	cout<<s<<endl;
	return 0;
}

