#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>//��׼�㷨ͷ�ļ�
//vector �������������������
void myPrint(int val)
{
  cout<<val<<endl;
}
void test01()
{
    vector<int> v;//��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    /*vector <int>::iterator itBegin=v.begin();//��ʼ������ ָ�������е�һ��Ԫ��
    vector <int>::iterator itEnd=v.end();//  ����������  ָ�����������һ��Ԫ�ص���һ��λ��
    while(itBegin!=itEnd)//��һ�ֱ���
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)//�ڶ��ֱ���
    {
        cout<<*it<<endl;
    }*/
    for_each(v.begin(),v.end(),myPrint);//�����ֱ���
}
//vector�����д���Զ�����������
class Person
{
public:
    string name;
    int age;
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
};
void test02()
{
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //����
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"������  "<<(*it).name<<"����:   "<<(*it).age<<endl;
    }
}

//����Զ����������� ָ��
void test03()
{
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //��������
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)->name<<"  "<<(*it)->age<<endl;
    }
}
//����Ƕ������
void test04()
{
    vector<vector<int> >v;
    //����С����
    vector <int>v1;
    vector <int>v2;
    vector <int>v3;
    vector <int>v4;
    //��С�������������
    for(int i=0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    //��С�������뵽��������
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    //ͨ�������������������ݱ���һ��
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        //(*it)----����vector<int>
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
            cout<<*vit<<" ";
        cout<<endl;
    }
}
int main()
{
    test04();
    system("pause");
    return 0;
}

