#include <iostream>
#include<cmath>
#ifndef _CloseHashTable_H
#define _CloseHashTable_H
using namespace std;

template <class T>
class closeHashTable//��ɢ�б���Ķ���
{
private:
    struct node
    {
        T data;
        int state;
        node(){state=0;}
        ~node(){}
    };
    node*array;
    int size;
    int activeNum;//�Ԫ��
    int delNum;//��־"��ɾ����"Ԫ�ظ���
    int maxDelNum;//���ɾ��Ԫ�ظ���

    int(*key)(const T&x);
    static int defaultKey(const int&k){return k;}
    void doublespace();//��������ռ�
public:
    closeHashTable(int length=3,int(*f)(const T&x)=defaultKey,int max=3);
    ~closeHashTable(){delete []array;}
    node* find(const T&x);
    bool insert(const T&x);
    bool remove(const T&x);
    void rehash();//����ɢ��
    void tranverse()
    {
        for(int i=0;i<size;i++)
        {
            if(array[i].state==1)cout<<array[i].data<<" ";
            if(array[i].state==2)cout<<"@ ";//@Ϊ��ɾ��Ԫ��
        }
    }
};

template<class T>
closeHashTable<T>::closeHashTable(int length,int(*f)(const T&x),int max)
{
    activeNum=0;
    delNum=0;
    size=length;
    array=new node[size];
    key=f;
    maxDelNum=max;//�趨���ɾ��Ԫ�ظ���
}
template<class T>
typename closeHashTable<T>::node* closeHashTable<T>::find(const T&x)
{
    int initPos,pos;
    initPos=pos=key(x)%size;
    do
    {
        if(array[pos].state==0)return false;
        if(array[pos].state==1&&array[pos].data==x)return array[pos];
        pos=(pos+1)%size;
    } while (pos!=initPos);
    return false;
}
template<class T>
bool closeHashTable<T>::insert(const T&x)
{
    int initPos,pos;
    initPos=pos=key(x)%size;
    if(activeNum>=size/2) doublespace();//�ڲ���ǰ�ж����еĻԪ�س�������Ԫ�ص�һ��,�Զ���������ռ�
    do
    {
        if(array[pos].state!=1)
        {
            array[pos].data=x;
            array[pos].state=1;
            activeNum++;
            return true;
        }
        pos=(pos+1)%size;
    } while (pos!=initPos);
    return false;
}
template<class T>
bool closeHashTable<T>::remove(const T&x)
{
    int initPos,pos;
    initPos=pos=key(x)%size;
    do
    {
        if(array[pos].state==0)return false;
        if(array[pos].state==1&&array[pos].data==x)
        {
            array[pos].state=2;
            delNum++;
            activeNum--;
            if(delNum>=maxDelNum) rehash();//ɾ�����ж������б�־"��ɾ����"Ԫ�ظ�������ָ����ֵ�����Զ�����ɢ��
            return true;
        }
        pos=(pos+1)%size;
    } while (pos!=initPos);
    return false;
}
template<class T>
void closeHashTable<T>::rehash()
{
    node*tmp=array;
    array=new node[size];
    int a=activeNum;
    for(int i=0;i<size;i++)
    {
        if(tmp[i].state==1)
            insert(tmp[i].data);//��Ԫ��ͨ����������±���
            activeNum=a;//ʵ�ʻԪ��û�з����ı䣬���ڴ˴����¸�ֵ
    }
    delete []tmp;
    delNum=0;//��ɾ��Ԫ����0
}
template<class T>
void closeHashTable<T>::doublespace()
{
    node*tmp=array;
    int s=size;
    int a=activeNum;
    size=size*2+1;
    bool flag;
    do{
        flag=false;
        for(int i=3;i<=sqrt(size);i++)
            if(size%i==0){flag=true;size+=2;break;}
    }while(flag);//�ҵ�����size*2����С����
    array=new node[size];
    for(int i=0;i<s;i++)
    {
        if(tmp[i].state==1)
            insert(tmp[i].data);//��Ԫ��ͨ����������±���
            activeNum=a;//ʵ�ʻԪ��û�з����ı䣬���ڴ˴����¸�ֵ
    }
    delete []tmp;
    delNum=0;

}
#endif
