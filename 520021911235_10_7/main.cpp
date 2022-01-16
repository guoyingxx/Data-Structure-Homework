//试设计一个函数，在一个规模为N的无序数组中找出第k个大的元素
//(1)要求时间复杂度为O(N+klogN)
//(2)要求时间复杂度为O(Nlogk)
#include <iostream>

using namespace std;

template<class T>
T findKth1(T a[],int size,int k);
template<class T>
T findKth2(T a[],int size,int k);
template<class T>
void precolateDown(T a[],int size,int hole);
template<class T>
void precolateDown2(T a[],int size,int hole);

int main()
{
    int a[]={3,5,6,7,1,7,8,1,2,7};
    cout<<"数组为：";
    for(int i=0;i<10;i++)cout<<a[i]<<" ";
    cout<<'\n';
    cout<<"第8大的元素为(O(N+klogN))："<<findKth1<int>(a,10,5)<<endl;
    int b[]={3,5,6,7,1,7,8,1,2,7};
    cout<<"第8大的元素为(O(Nlogk))："<<findKth2<int>(b,10,8);
    return 0;
}

template<class T>
T findKth1(T a[],int size,int k)//时间复杂度为O(N+klogN)
{
    T tmp;
    for(int i=(size-1)/2;i>=0;i--)//建立最大堆
    precolateDown(a,size,i);//从第一个非叶子结点开始向下过滤

    for(int i=size-1;i>size-k;i--)//进行k次出队后即可得到第k大的元素
    {
        tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        precolateDown(a,i,0);
    }
    return a[0];
}
template<class T>
void precolateDown(T a[],int size,int hole)//最大堆的向下过滤
{
    T tmp=a[hole];
    int child;

    for(;hole*2+1<size;hole=child)
    {
        child=hole*2+1;
        if(child!=size-1&&a[child+1]>a[child])child++;
        if(a[child]>tmp)a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

template<class T>
T findKth2(T a[],int size,int k)//时间复杂度为O(Nlogk)
{
    for(int i=(k-1)/2;i>=0;i--)
    precolateDown2(a,k,i);//建立规模为k的最小堆

    for(int i=k;i<size;i++)
    {
        if(a[i]>a[0])//后面元素与最小堆的根结点比较
        {
            a[0]=a[i];//取较大值，使最终堆中留下的是最大的k个元素，根结点又是其中最小的即第k大的元素
            precolateDown2(a,k,0);
        }
    }
    return a[0];
}

template<class T>
void precolateDown2(T a[],int size,int hole)//最小堆的向下过滤
{
    T tmp=a[hole];
    int child;

    for(;hole*2+1<size;hole=child)
    {
        child=hole*2+1;
        if(child!=size-1&&a[child+1]<a[child])child++;
        if(a[child]<tmp)a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}
