//试写出Ackerman函数的递归算法和非递归算法。
#include <iostream>
using namespace std;

int Ackerman(int m,int n)//Ackerman函数的递归算法
{
    if(m==0)return n+1;
    else if(n==0)return Ackerman(m-1,1);
    else return Ackerman(m-1,Ackerman(m,n-1));
}


template<class T>//顺序栈的定义
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
int Ackerman2(int m,int n)//Ackerman函数的非递归算法
{
    seqStack<int> s;
    s.push(m);
    s.push(n);
    int tmp1,tmp2;
    while(!s.isEmpty())
    {
        tmp1=s.pop();//栈顶的Ackerman函数中的n
        if(s.isEmpty())break;//栈为空时跳出循环
        tmp2=s.pop();//栈顶的Ackerman函数中的m
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
     return tmp1;//返回计算得出的函数值
}
int main()
{
    int m=3,n=3;
    cout<<"Ackerman(3,3)"<<endl;
    cout<<"递归实现结果："<<Ackerman(m,n)<<endl;
    cout<<"非递归实现结果："<<Ackerman2(m,n);
    return 0;
}
