#include <iostream>
#ifndef SET_H
#define SET_H
using namespace std;
template<class T>//类的声明
class set;
//重载+
template<class T>
set<T>operator+(const set<T> &x1,const set<T> &x2)
{
    set<T> x3(x1);//利用复制构造函数直接将x1赋给x3
    for(int i=0;i<x2.currentSize;i++)
        x3.insert(x2.data[i]);//利用insert函数插入，可以检查是否已存在
    return x3;
}
//重载*
template<class T>
set<T>operator*(const set<T> &x1,const set<T> &x2)
{
    set<T>x3;
    for(int i=0;i<x2.currentSize;i++)
        if(x1.search(x2.data[i])!=-1)//判断该x2的值是否能在x1中找到
            x3.insert(x2.data[i]);
    return x3;
}
//重载-
template<class T>
set<T>operator-(const set<T> &x1,const set<T> &x2)
{
    set<T>x3;
    for(int i=0;i<x1.currentSize;i++)
        if(x2.search(x1.data[i])==-1)//判断该x2的值是否不能在x1中找到
            x3.insert(x1.data[i]);
    return x3;
}
//重载<<,便于输出
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
friend set operator+<>(const set &x1,const set &x2);//设为set的友元函数
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
    set(const set<T>&x);//复制构造函数
    ~set(){delete []data;}
    int search(const T&x)const;//查找函数，设为const以便于在之后const set&x做参数时仍能够调用
    void insert(const T&x);//插入
    void remove(const T&x);//删除
    set &operator=(const set<T>&x);//重载=

};

template<class T>
set<T>::set(int initialSize)//构造一个空的集合
{
    maxSize=initialSize;
    data=new T[maxSize];
    currentSize=0;
}
template<class T>
set<T>::set(const set<T>&x)//复制构造函数
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
int set<T>::search(const T&x)const//查找
{
    for(int i=0;i<currentSize;++i)
        if(data[i]==x)return i;//找到返回下标值
    return -1;//没找到返回-1
}
template<class T>
void set<T>::insert(const T&x)//插入
{
    if(search(x)!=-1)return;//找到则不用插入
    if(currentSize>=maxSize)doublespace();//判断容量是否足够
    data[currentSize++]=x;//因为集合无序则直接加在最后一个即可
}
template<class T>
void set<T>::remove(const T&x)//删除
{
    //因为集合无序则直接将最后一个移到删除的位置
    if(search(x)!=-1)data[search(x)]=data[--currentSize];
}
template<class T>
set<T>&set<T>::operator=(const set<T>&x)//重载=
{
    if(this==&x)return *this;//判断是否自己给自己赋值
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
