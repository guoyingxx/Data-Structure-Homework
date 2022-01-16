//��д��Ackerman�����ĵݹ��㷨�ͷǵݹ��㷨��
#include <iostream>
using namespace std;

int Ackerman(int m,int n)//Ackerman�����ĵݹ��㷨
{
    if(m==0)return n+1;
    else if(n==0)return Ackerman(m-1,1);
    else return Ackerman(m-1,Ackerman(m,n-1));
}


template<class T>//˳��ջ�Ķ���
class seqStack
{
private:
    T*elem;
    int top_p;
    int maxSize;
    void doublespace()
    {
        T*tmp=elem;
        elem=new T[maxSize*2];
        for(int i=0; i<maxSize; ++i)elem[i]=tmp[i];
        maxSize*=2;
        delete []tmp;
    }
public:
    seqStack(int intiSize=10)
    {
        elem=new T[intiSize];
        maxSize=intiSize;
        top_p=-1;
    }
    ~seqStack()
    {
        delete []elem;
    }
    bool isEmpty()const
    {
        return top_p==-1;
    }
    void push(const T&x)
    {
        if(top_p==maxSize-1)doublespace();
        elem[++top_p]=x;
    }
    T pop()
    {
        return elem[top_p--];
    }
    T top()
    {
        return elem[top_p];
    }
};
int Ackerman2(int m,int n)//Ackerman�����ķǵݹ��㷨
{
    seqStack<int> s;
    s.push(m);
    s.push(n);
    int tmp1,tmp2;
    while(!s.isEmpty())
    {
        tmp1=s.pop();//ջ����Ackerman�����е�n
        if(s.isEmpty())break;//ջΪ��ʱ����ѭ��
        tmp2=s.pop();//ջ����Ackerman�����е�m
        if(tmp2==0)
            s.push(tmp1+1);
        else if(tmp1==0)
        {
            s.push(tmp2-1);
            s.push(1);
        }
        else
        {
            s.push(tmp2-1);
            s.push(tmp2);
            s.push(tmp1-1);
        }
    }
     return tmp1;//���ؼ���ó��ĺ���ֵ
}
int main()
{
    int m=3,n=3;
    cout<<"Ackerman(3,3)"<<endl;
    cout<<"�ݹ�ʵ�ֽ����"<<Ackerman(m,n)<<endl;
    cout<<"�ǵݹ�ʵ�ֽ����"<<Ackerman2(m,n);
    return 0;
}
