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
	
	int idx1=s.size()-1;//�ɳ��ȵ���� 
	//���ݡ� 
	s.resize(s.size()+cnt*5);//ÿ�����ַ�6���ĳ��ȣ�����ÿ�����ּ�5������
	int idx2=s.size()-1;//�³��ȵ���� 
	
	//�¾ɳ���һ��ʼ�ƶ� 
	while (idx1>=0) {//�Ӻ���ǰ��䣬����������ƶ� 
		//�������ֵĻ� 
		if (s[idx1]>='0' && s[idx1]<='9') {
			s[idx2--]='r';
			s[idx2--]='e';
			s[idx2--]='b';
			s[idx2--]='m';
			s[idx2--]='u';
			s[idx2--]='n';
		} else {//������ĸ�Ļ��ճ����� 
			s[idx2--]=s[idx1];
		}
		idx1--;
	} 
	cout<<s<<endl;
	return 0;
}

