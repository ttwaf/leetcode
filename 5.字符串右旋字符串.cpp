#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	string s;
	cin>>k>>s;
	//�ÿ⺯��reverse���õ�������ת 
	reverse(s.begin(),s.end());//��������ת
	cout<<s<<endl;
	reverse(s.begin(),s.begin()+k);//����ҿ�����βΪ ��ͷ+���� 
	cout<<s<<endl;
	reverse(s.begin()+k,s.end());
	cout<<s<<endl;
	return 0;
}

