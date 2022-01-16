#include <iostream>
#ifndef _priorityQueue_h
#define _priorityQueue_h
using namespace std;

template<class T>
class priorityQueue//���ȼ�������Ķ���
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

    int findMin(const T&x);//��ĿҪ��ʵ�ֵ�findMin
    void decreaseKey(int i,const T&value);//��ĿҪ��ʵ�ֵ�decreaseKey
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
    T tmp;//���浱ǰ�ҵ�����Сֵ
    for(int i=currentSize;i>0;i--)//�����ȼ����н��б���
    {
        if(array[i]>x&&(array[i]<tmp||num==-1))//�����Ԫ���������x��Ϊ��һ���ҵ���ȵ�ǰ����СֵС
        {
            tmp=array[i];//�趨��Ԫ��Ϊ��Сֵ
            num=i;
        }
    }
    return num;
}
template<class T>
void priorityQueue<T>::decreaseKey(int i,const T&value)
{
    T x=array[i]-value;//�������ȼ�ֵ��С֮��Ľ��
    int hole=i;
    for(;hole/2>0;hole/=2)//�������Ϲ���
    {
        if(x<array[hole/2])
        array[hole]=array[hole/2];
        else break;//���˵����ʵ�λ������ѭ��
    }
    array[hole]=x;//�Ը�Ԫ�����ƶ�����λ�ý��и�ֵ
}
#endif
