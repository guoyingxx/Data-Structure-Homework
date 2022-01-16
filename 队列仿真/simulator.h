#include<iostream>
#include<cstdlib>
#include<ctime>
#ifndef _simulator_h
#define _simulator_h
using namespace std;

template <class T>
class linkQueue//队列的链接实现
{
    private:
        struct node{
            T data;
            node *next;
            node(const T&x,node *n=NULL)
            {data=x;next=n;}
            node():next(NULL){}
            ~node(){}
        };
        node *front,*rear;
    public:
        linkQueue(){front=rear=NULL;}
        ~linkQueue();
        bool isEmpty(){return front==NULL;}
        void enQueue(const T&x);
        T deQueue();
        T getHead(){
            if(!isEmpty())return front->data;
            else cout<<"队列为空";
            }
        T getTail(){
            if(!isEmpty())return rear->data;
            else cout<<"队列为空";
            }
};
template<class T>
linkQueue<T>::~linkQueue()
{
    node *tmp;
    while(front!=NULL)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
}
template<class T>
void linkQueue<T>::enQueue(const T&x)
{
    if(rear==NULL)
        front=rear=new node(x);
    else
    {
        rear->next=new node(x);
        rear=rear->next;
    }
}
template<class T>
T linkQueue<T>::deQueue()
{
    if(front==NULL)cout<<"队列为空";
    node *p=front;
    T value=front->data;

    front=front->next;
    if(front==NULL)rear=NULL;
    delete p;
    return value;
}

class simulator//模拟类的定义
{
private:
    int customNum;
    int arrivelLow,arrivelHigh;
    int serviceTimeLow,serviceTimeHigh;
public:
    simulator();
    double avgWaitTime()const;

};
simulator::simulator()//构造函数
{
    cout<<"请输入需要模拟顾客数";
    cin>>customNum;
    cout<<"请输入到达时间间隔的上下界";
    cin>>arrivelLow>>arrivelHigh;
    cout<<"请输入服务时间的上下界";
    cin>>serviceTimeLow>>serviceTimeHigh;

    srand(time(NULL));//初始化随机数发生器
}
double simulator::avgWaitTime()const//仿真过程
{
    int totalWaitTime=0,nextDepartTime=0,futureArrivelTime=0;
    linkQueue<int>customQueue;//排队队列
    int currentNum=1;

    while(currentNum<customNum)
    {
        nextDepartTime+=serviceTimeLow+(serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);//生成对应离开时间

        while(futureArrivelTime<nextDepartTime)//下一个到达时间小于离开时间
        {
            if(futureArrivelTime!=0)customQueue.enQueue(futureArrivelTime);
            futureArrivelTime+=arrivelLow+(arrivelHigh-arrivelLow+1)*rand()/(RAND_MAX+1);
        }

        currentNum++;//计数
        if(!customQueue.isEmpty())//如果队列非空，即存在排队等待
        {
            totalWaitTime+=nextDepartTime-customQueue.deQueue();//加上当前进入服务的等候的时间
        }

        else
        {
            nextDepartTime=futureArrivelTime;//如果不存在等待的情况，将时间拨至当前进入服务的到达的时间
            futureArrivelTime+=arrivelLow+(arrivelHigh-arrivelLow+1)*rand()/(RAND_MAX+1);//并生成下一到达时间
        }
    }
    return double(totalWaitTime)/customNum;//返回平均等待时间
}


#endif

