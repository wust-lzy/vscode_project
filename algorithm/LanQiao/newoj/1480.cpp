#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="0100110001010001";
    set<string>v;
    int sum=0;
    for(int i=1;i<=s.length();i++)//��ȡ���ַ�������
        {
            for(int j=0;j<s.length()-i+1;j++)//��ȡ��һ���ַ���λ��
    {
        v.insert(s.substr(j,i));
    }
        sum+=v.size();
        v.clear();
        }
        cout<<sum<<endl;
    return 0;
}




