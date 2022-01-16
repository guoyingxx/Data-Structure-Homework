//�����һ����������һ����ģΪN�������������ҳ���k�����Ԫ��
//(1)Ҫ��ʱ�临�Ӷ�ΪO(N+klogN)
//(2)Ҫ��ʱ�临�Ӷ�ΪO(Nlogk)
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
    cout<<"����Ϊ��";
    for(int i=0;i<10;i++)cout<<a[i]<<" ";
    cout<<'\n';
    cout<<"��8���Ԫ��Ϊ(O(N+klogN))��"<<findKth1<int>(a,10,5)<<endl;
    int b[]={3,5,6,7,1,7,8,1,2,7};
    cout<<"��8���Ԫ��Ϊ(O(Nlogk))��"<<findKth2<int>(b,10,8);
    return 0;
}

template<class T>
T findKth1(T a[],int size,int k)//ʱ�临�Ӷ�ΪO(N+klogN)
{
    T tmp;
    for(int i=(size-1)/2;i>=0;i--)//��������
    precolateDown(a,size,i);//�ӵ�һ����Ҷ�ӽ�㿪ʼ���¹���

    for(int i=size-1;i>size-k;i--)//����k�γ��Ӻ󼴿ɵõ���k���Ԫ��
    {
        tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        precolateDown(a,i,0);
    }
    return a[0];
}
template<class T>
void precolateDown(T a[],int size,int hole)//���ѵ����¹���
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
T findKth2(T a[],int size,int k)//ʱ�临�Ӷ�ΪO(Nlogk)
{
    for(int i=(k-1)/2;i>=0;i--)
    precolateDown2(a,k,i);//������ģΪk����С��

    for(int i=k;i<size;i++)
    {
        if(a[i]>a[0])//����Ԫ������С�ѵĸ����Ƚ�
        {
            a[0]=a[i];//ȡ�ϴ�ֵ��ʹ���ն������µ�������k��Ԫ�أ����������������С�ļ���k���Ԫ��
            precolateDown2(a,k,0);
        }
    }
    return a[0];
}

template<class T>
void precolateDown2(T a[],int size,int hole)//��С�ѵ����¹���
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
