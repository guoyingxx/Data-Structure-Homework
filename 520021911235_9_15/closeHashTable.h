#include <iostream>
#include<cmath>
#ifndef _CloseHashTable_H
#define _CloseHashTable_H
using namespace std;

template <class T>
class closeHashTable//闭散列表类的定义
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
    int activeNum;//活动元素
    int delNum;//标志"被删除的"元素个数
    int maxDelNum;//最大被删除元素个数

    int(*key)(const T&x);
    static int defaultKey(const int&k){return k;}
    void doublespace();//扩大数组空间
public:
    closeHashTable(int length=3,int(*f)(const T&x)=defaultKey,int max=3);
    ~closeHashTable(){delete []array;}
    node* find(const T&x);
    bool insert(const T&x);
    bool remove(const T&x);
    void rehash();//重新散列
    void tranverse()
    {
        for(int i=0;i<size;i++)
        {
            if(array[i].state==1)cout<<array[i].data<<" ";
            if(array[i].state==2)cout<<"@ ";//@为已删除元素
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
    maxDelNum=max;//设定最大被删除元素个数
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
    if(activeNum>=size/2) doublespace();//在插入前判断组中的活动元素超过数组元素的一半,自动扩大数组空间
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
            if(delNum>=maxDelNum) rehash();//删除后判断数组中标志"被删除的"元素个数超过指定的值，则自动重新散列
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
            insert(tmp[i].data);//将元素通过插入放入新表中
            activeNum=a;//实际活动元素没有发生改变，故在此处重新赋值
    }
    delete []tmp;
    delNum=0;//已删除元素置0
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
    }while(flag);//找到大于size*2的最小素数
    array=new node[size];
    for(int i=0;i<s;i++)
    {
        if(tmp[i].state==1)
            insert(tmp[i].data);//将元素通过插入放入新表中
            activeNum=a;//实际活动元素没有发生改变，故在此处重新赋值
    }
    delete []tmp;
    delNum=0;

}
#endif
