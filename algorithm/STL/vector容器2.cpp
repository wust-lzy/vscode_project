#include<iostream>
#include<vector>
using namespace std;
//���캯��
/*vector<T> v;//Ĭ�Ϲ��캯��
vector (v.begin(),v.end());
vector(n,elem);//n��elem��ֵ������
vector(const vector &vec);//���ƹ��캯��
//��ֵ����
vector&operator=(const vector &vec);
assign (beg,end); //��[beg,end)�����е����ݿ�����ֵ������
assign(n,elem);//��n��elem��ֵ������
//�����ʹ�С
empty(); //�ж������Ƿ�Ϊ��
capacity();//����������
size();//����������Ԫ�صĸ���
resize(int num);//����ָ������Ϊnum�����䳤������Ĭ��ֵ�����λ�ã�����̣��򳬳����Ȳ��ֱ�ɾ��
resize(int num,elem);//��elem�����λ��
//�����ɾ��
push_back(ele) //β������ele
pop_back();    //ɾ�����һ��Ԫ��
insert(const_iterator pos,ele);  //������ָ��λ��pos����Ԫ��ele
insert(const_iterator pos,int count,ele)  //������ָ��λ��pos����count��Ԫ��ele
erase(const_iterator pos); //ɾ��������ָ���Ԫ��
erase(const_iterator start,const_iterator end);//ɾ����������start��end��Ԫ��
clear();  //ɾ�����������е�Ԫ��
*/
//���ݴ�ȡ
/*at(int idx)//����idx��ָ������
operator[idx];//
front();  //���ص�һ������Ԫ��
back();//�������������һ������Ԫ��*/
//��������
/*
swap(vec)
vector<int>(v).swap(v);  ����v���ڴ�  */
//vector Ԥ���ռ�
/*
����vector�ڶ�̬��չ����ʱ����չ����
reserve(int len);����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/
int main()
{
    vector<int> v;
    int num=0,*p=NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}
