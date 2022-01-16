#include <iostream>
#ifndef SET_H
#define SET_H
using namespace std;
template<class T>//�������
class set;
//����+
template<class T>
set<T>operator+(const set<T> &x1,const set<T> &x2)
{
    set<T> x3(x1);//���ø��ƹ��캯��ֱ�ӽ�x1����x3
    for(int i=0;i<x2.currentSize;i++)
        x3.insert(x2.data[i]);//����insert�������룬���Լ���Ƿ��Ѵ���
    return x3;
}
//����*
template<class T>
set<T>operator*(const set<T> &x1,const set<T> &x2)
{
    set<T>x3;
    for(int i=0;i<x2.currentSize;i++)
        if(x1.search(x2.data[i])!=-1)//�жϸ�x2��ֵ�Ƿ�����x1���ҵ�
            x3.insert(x2.data[i]);
    return x3;
}
//����-
template<class T>
set<T>operator-(const set<T> &x1,const set<T> &x2)
{
    set<T>x3;
    for(int i=0;i<x1.currentSize;i++)
        if(x2.search(x1.data[i])==-1)//�жϸ�x2��ֵ�Ƿ�����x1���ҵ�
            x3.insert(x1.data[i]);
    return x3;
}
//����<<,�������
template<class T>
ostream&operator<<(ostream&os,const set<T>&obj)
{
    for(int i=0;i<obj.currentSize;i++)
    {
        os<<obj.data[i]<<" ";
    }
    return os;
}
template<class T>
class set
{
friend set operator+<>(const set &x1,const set &x2);//��Ϊset����Ԫ����
friend set operator*<>(const set &x1,const set &x2);
friend set operator-<>(const set &x1,const set &x2);
friend ostream&operator<<<>(ostream&os,const set&obj);

private:
    T*data;
    int currentSize;
    int maxSize;
    void doublespace()
    {
        maxSize*=2;
        T*tmp=data;
        data=new T[maxSize];
        for(int i=0;i<currentSize;++i)
            data[i]=tmp[i];
        delete tmp;
    }
public:
    set(int initialSize=5);
    set(const set<T>&x);//���ƹ��캯��
    ~set(){delete []data;}
    int search(const T&x)const;//���Һ�������Ϊconst�Ա�����֮��const set&x������ʱ���ܹ�����
    void insert(const T&x);//����
    void remove(const T&x);//ɾ��
    set &operator=(const set<T>&x);//����=

};

template<class T>
set<T>::set(int initialSize)//����һ���յļ���
{
    maxSize=initialSize;
    data=new T[maxSize];
    currentSize=0;
}
template<class T>
set<T>::set(const set<T>&x)//���ƹ��캯��
{
    currentSize=x.currentSize;
    maxSize=x.maxSize;
    data=new T[maxSize];
    for(int i=0;i<currentSize;i++)
    {
        data[i]=x.data[i];
    }
}
template<class T>
int set<T>::search(const T&x)const//����
{
    for(int i=0;i<currentSize;++i)
        if(data[i]==x)return i;//�ҵ������±�ֵ
    return -1;//û�ҵ�����-1
}
template<class T>
void set<T>::insert(const T&x)//����
{
    if(search(x)!=-1)return;//�ҵ����ò���
    if(currentSize>=maxSize)doublespace();//�ж������Ƿ��㹻
    data[currentSize++]=x;//��Ϊ����������ֱ�Ӽ������һ������
}
template<class T>
void set<T>::remove(const T&x)//ɾ��
{
    //��Ϊ����������ֱ�ӽ����һ���Ƶ�ɾ����λ��
    if(search(x)!=-1)data[search(x)]=data[--currentSize];
}
template<class T>
set<T>&set<T>::operator=(const set<T>&x)//����=
{
    if(this==&x)return *this;//�ж��Ƿ��Լ����Լ���ֵ
    delete []data;
    currentSize=x.currentSize;
    maxSize=x.maxSize;
    data=new T[maxSize];
    for(int i=0;i<currentSize;i++)
    {
        data[i]=x.data[i];
    }
    return *this;
}
#endif
