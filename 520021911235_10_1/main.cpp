//���һ��������ɾ��һ����N��Ԫ�ص�����A�����е��ظ�Ԫ�أ���������������A�е�Ԫ�ظ�����
//������ʱ�临�Ӷȱ���ΪO(NlogN)(�ÿ���������Ϊһ��Ԥ������)��
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
    cout<<"����AΪ��";
    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    cout<<'\n';
    int N=delRepet<int>(a,10);//���ú������䷵��ֵ������������A�е�Ԫ�ظ���
    cout<<"ɾ���ظ�Ԫ������AΪ��";
    for(int i=0;i<N;i++)
    cout<<a[i]<<" ";
    cout<<'\n';
    cout<<"������A�е�Ԫ�ظ���Ϊ��";
    cout<<N;
    return 0;
}
template <class T>
int delRepet(T a[],int N)
{
    quickSort(a,0,N-1);//���ÿ�����ΪԤ������
    int i,j=0;
    for(i=0;i<N;i++)//��һ����ظ�
    {
        a[i-j]=a[i];//��a[i]��ǰ�ƶ�����ȫ
        if(a[i]==a[i+1]) j++;//��¼�ظ���Ŀ
    }
    return N-j;
}
template <class T>
void quickSort(T a[],int low,int high)//��������
{
    int mid;
    if(low>=high)return;
    mid=devide(a,low,high);

    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
template <class T>
int devide(T a[],int low,int high)//����
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
