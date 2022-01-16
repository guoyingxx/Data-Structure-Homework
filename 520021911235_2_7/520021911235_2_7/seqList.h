#include <iostream>
#ifndef _seqlist_h
#define _seqList_h
using namespace std;

template<class T>
class seqList;
template<class T>
seqList<T>operator+(const seqList<T> &x1,const seqList<T> &x2);

template<class T>
class list
{
public:
    virtual void insert(int i,const T&x)=0;
    virtual T visit(int i)const=0;
    virtual void tranverse()const=0;
    virtual ~list() {}
};

template<class T>
class seqList:public list<T>
{
friend seqList operator+<>(const seqList &x1,const seqList &x2);//用友元函数重载+
private:
    T *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqList(int initsize=5);
    seqList(const seqList&x);//复制构造函数
    ~seqList(){delete []data;}
    void tranverse()const;
    T visit(int i)const{if(i>=0&&i<=currentLength-1) return data[i];}
    void insert(int i,const T &x);
    seqList &operator=(const seqList&x);//重载=
};

template<class T>
seqList<T>::seqList(int initSize)
{
    data=new T[initSize];
    maxSize=initSize;
    currentLength=0;
}

//复制构造函数
template<class T>
seqList<T>::seqList(const seqList<T>&x)
{
    maxSize=x.maxSize;
    currentLength=x.currentLength;
    data=new T[maxSize];//使其有自己存放线性表元素的空间
    for(int i=0;i<currentLength;i++)
    data[i]=x.data[i];//存入线性表数据
}
//用友元函数重载+
template<class T>
seqList<T> operator+(const seqList<T> &x1,const seqList<T> &x2)
{

    seqList<T> tmp(x1);//利用复制构造函数，将x1赋给tmp
    for(int j=0;j<x2.currentLength;j++)
    tmp.insert(tmp.currentLength,x2.data[j]);//利用插入操作，将x2的值赋给tmp同时扩容
    return tmp;
}
//重载=
template<class T>
seqList<T>& seqList<T>::operator=(const seqList<T>&x)
{
    if(this==&x)//判断是否自己给自己赋值
        return *this;
    delete []data;//释放被赋值对象空间
    currentLength=x.currentLength;
    maxSize=x.maxSize;
    data=new T[x.maxSize];//根据数组大小重新申请空间
    for(int i=0;i<currentLength;i++)
        data[i]=x.data[i];//放入数据
    return *this;
}
template<class T>
void seqList<T>::doubleSpace()
{
    T *tmp=data;
    maxSize=maxSize*2;
    data=new T[maxSize];
    for(int i=0;i<currentLength;i++)
    data[i]=tmp[i];
    delete []tmp;
}
template<class T>
void seqList<T>::tranverse()const
{
    for(int i=0;i<currentLength;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
template<class T>
void seqList<T>::insert(int i,const T&x)
{
    if(currentLength>=maxSize)
        doubleSpace();
    for(int j=currentLength;j>i;j--)
        data[j]=data[j-1];
    data[i]=x;
    currentLength++;
}

#endif
