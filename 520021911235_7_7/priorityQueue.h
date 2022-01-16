#include <iostream>
#ifndef _priorityQueue_h
#define _priorityQueue_h
using namespace std;

template<class T>
class priorityQueue//优先级队列类的定义
{
private:
    int maxSize;
    int currentSize;
    T *array;

    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
public:
    priorityQueue(int capacity=100)
    {
        array=new T[capacity];
        maxSize=capacity;
        currentSize=0;
    }
    priorityQueue(const T data[],int capacity);
    ~priorityQueue(){delete []array;}
    bool isEmpty()const{return currentSize==0;}
    void enQueue(const T&x);
    T deQueue();
    T getHead(){return array[1];}

    int findMin(const T&x);//题目要求实现的findMin
    void decreaseKey(int i,const T&value);//题目要求实现的decreaseKey
    void levelOrder()
    {
        for(int i=1;i<=currentSize;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};

template<class T>
void priorityQueue<T>::doubleSpace()
{
    T *tmp=array;
    maxSize=maxSize*2;
    array=new T[maxSize];
    for(int i=0;i<maxSize;i++)
    {
        array[i]=tmp[i];
    }
    delete []tmp;
}
template<class T>
void priorityQueue<T>::buildHeap()
{
    for(int i=currentSize/2;i>0;i--)
    {
        percolateDown(i);
    }
}
template<class T>
void priorityQueue<T>::percolateDown(int hole)
{
    T tmp=array[hole];
    int child;
    for(;hole*2<currentSize;hole=child)
    {
        child=hole*2;
        if(hole+1<currentSize)
        child=array[hole*2]<array[hole*2+1]?hole*2:hole*2+1;
        if(tmp>array[child])array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}
template<class T>
priorityQueue<T>::priorityQueue(const T data[],int size):maxSize(size+10),currentSize(size)
{
    array=new T[maxSize];
    for(int i=0;i<size;i++)
    {
        array[i+1]=data[i];
    }
    buildHeap();
}
template<class T>
void priorityQueue<T>::enQueue(const T&x)
{
    if(currentSize==maxSize-1)doubleSpace();
    int hole=++currentSize;
    for(;hole/2>0;hole/=2)
    {
        if(x<array[hole/2])
        array[hole]=array[hole/2];
        else break;
    }
    array[hole]=x;
}
template<class T>
T priorityQueue<T>::deQueue()
{
    T tmp=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return tmp;
}
template<class T>
int priorityQueue<T>::findMin(const T&x)
{
    int num=-1;
    T tmp;//保存当前找到的最小值
    for(int i=currentSize;i>0;i--)//对优先级队列进行遍历
    {
        if(array[i]>x&&(array[i]<tmp||num==-1))//如果该元素满足大于x且为第一个找到或比当前的最小值小
        {
            tmp=array[i];//设定该元素为最小值
            num=i;
        }
    }
    return num;
}
template<class T>
void priorityQueue<T>::decreaseKey(int i,const T&value)
{
    T x=array[i]-value;//保存优先级值减小之后的结果
    int hole=i;
    for(;hole/2>0;hole/=2)//进行向上过滤
    {
        if(x<array[hole/2])
        array[hole]=array[hole/2];
        else break;//过滤到合适的位置跳出循环
    }
    array[hole]=x;//对该元素新移动到的位置进行赋值
}
#endif
