#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>//��׼�㷨ͷ�ļ�
/*string ();                    //����һ���յ��ַ���
string(const char *s);        //ʹ���ַ�����ʼ��
string (const string &str);   //ʹ��str�����ʼ��
string (int n,char c);   //ʹ��n���ַ�c��ʼ��

string &operator=(const string &s);//��ֵ
string &operator=(char c);  //���ַ�c��ֵ
string &assign(const char *s,int n);  //�ַ���sǰn���ַ���ֵ
string &assign(const string &s);
string &assign(int n,char c);

string &operator+=(const string &s);
string &operator+=(const char c);
string &operator+=(const string &str);
string &append(const char *s);
string &append(const char *s,int n);
string &append(const string &s);
string &append(const string &s,int pos,int n);//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�������*/
//1.����
void test1()
{
    string str1="111abcdefg";
    int pos=str1.find("de");
    if(pos==-1)
        cout<<"δ�ҵ�"<<endl;
    else
    cout<<"pos="<<pos<<endl;

    //rfind
    pos=str1.rfind("de");
    cout<<"pos="<<pos<<endl;
    //rfind��find����
    //rfind�����������  find�������Ҳ���
}
//2.�滻
void test2()
{
    string str1="111abcdefg";
    str1.replace(1,3,"1111");
    cout<<"str1="<<str1<<endl;
}
//3.�Ƚ�
/*
int compare(const string &s)const;
int compare(const char *s) const; С�ڷ��ظ��������ڷ���0�����ڷ�������
*/
//4.�ַ���ȡ
/*
char &operator[](int n);
char &at(int n);
*/
//5.�����ɾ��
string &insert(int pos,const char *s);
string &insert(int pos,const string &str);
string &insert(int pos,int n, char c);
//string &erase(int pos,int n=npos);
//6.�Ӵ�
//string substr(int pos=0,int n=npos)const;//������pos��ʼ��n���ַ���ɵ��ַ���
void test3()
{
    string email="zhangsan@sina.com";
    //�������ַ�л�ȡ�û���
    int pos=email.find("@");
    string usrName=email.substr(0,pos);
    cout<<usrName<<endl;
}
int main()
{


    //test2();
    //string s="afaf";
    //s.erase(1);
    //cout<<s;
    test3();
    system("pause");
    return 0;
}
