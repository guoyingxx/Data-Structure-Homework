//设计一个方法，删除一个有N个元素的数组A中所有的重复元素，返回仍留在数组A中的元素个数。
//函数的时间复杂度必须为O(NlogN)(用快速排序作为一个预处理步骤)。
#include <iostream>

using namespace std;

template <class T>
int delRepet(T a[],int N);
template <class T>
void quickSort(T a[],int low,int high);
template <class T>
int devide(T a[],int low,int high);


int main()
{
    int a[]={3,5,6,7,1,7,8,1,2,7};
    cout<<"数组A为：";
    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    cout<<'\n';
    int N=delRepet<int>(a,10);//调用函数，其返回值是仍留在数组A中的元素个数
    cout<<"删除重复元素数组A为：";
    for(int i=0;i<N;i++)
    cout<<a[i]<<" ";
    cout<<'\n';
    cout<<"仍留在A中的元素个数为：";
    cout<<N;
    return 0;
}
template <class T>
int delRepet(T a[],int N)
{
    quickSort(a,0,N-1);//利用快排作为预处理步骤
    int i,j=0;
    for(i=0;i<N;i++)//逐一检查重复
    {
        a[i-j]=a[i];//将a[i]向前移动，补全
        if(a[i]==a[i+1]) j++;//记录重复数目
    }
    return N-j;
}
template <class T>
void quickSort(T a[],int low,int high)//快速排序
{
    int mid;
    if(low>=high)return;
    mid=devide(a,low,high);

    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
template <class T>
int devide(T a[],int low,int high)//划分
{
    T k=a[low];
    while(high!=low)
    {
        while(a[high]>=k&&high>low)high--;
        if(high>low)a[low++]=a[high];
        while(a[low]<=k&&low<high)low++;
        if(low<high)a[high--]=a[low];
    }
    a[low]=k;
    return low;
}
