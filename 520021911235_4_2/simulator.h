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
    int totalTime;
    int busArrLow,busArrHigh;
    int vanArrLow,vanArrHigh;
    int busNum,busWaitTime;
    int vanNum,vanWaitTime;
public:
    simulator();
    void avgWaitTime();
    double getBusWaitTime(){return double(busWaitTime)/busNum;}
    double getVanWaitTime(){return double(vanWaitTime)/vanNum;}
};
simulator::simulator()//构造函数
{
    cout<<"请输入需要模拟的总时间/min";
    cin>>totalTime;
    cout<<"请输入客车到达时间间隔的上下界";
    cin>>busArrLow>>busArrHigh;
    cout<<"请输入货车到达时间间隔的上下界";
    cin>>vanArrLow>>vanArrHigh;

    srand(time(NULL));//初始化随机数发生器
}
void simulator::avgWaitTime()//仿真过程
{
    int systemTime=0,num;
    linkQueue<int>busQueue,vanQueue;//客车和货车的排队队列
    busNum=0;busWaitTime=0;
    vanNum=0;vanWaitTime=0;

    for(int i=1;i<totalTime/10;i++)
    {
        while(systemTime<=i*10)//生成该次渡轮到达间隔中加入排队的客车
        {
            systemTime+=busArrLow+(busArrHigh-busArrLow+1)*rand()/(RAND_MAX+1);
            busQueue.enQueue(systemTime);
        }
        if(vanQueue.isEmpty())systemTime=(i-1)*10;//拨回系统时间
        else systemTime=vanQueue.getTail();//或拨至货车队尾到达时间
        while(systemTime<=i*10)//生成该次渡轮到达间隔中加入排队的货车
        {
            systemTime+=vanArrLow+(vanArrHigh-vanArrLow+1)*rand()/(RAND_MAX+1);
            vanQueue.enQueue(systemTime);
        }

        for(num=0;num<8&&!busQueue.isEmpty();num++)//先让客车上渡轮
        {
            if(busQueue.getHead()>i*10)break;//如果在该次间隔未排队的则仍在队列中
            busWaitTime+=i*10-busQueue.deQueue();//出队并统计客车等待时间
            busNum++;//统计上渡轮的客车数
        }
        for(;num<10&&!vanQueue.isEmpty();num++)//再让货车上渡轮
        {
            if(vanQueue.getHead()>i*10)break;//如果在该次间隔未排队的则仍在队列中
            vanWaitTime+=i*10-vanQueue.deQueue();//出队并统计货车等待时间
            vanNum++;//统计上货轮的客车数
        }
        for(;num<10&&!busQueue.isEmpty();num++)//如仍有空余则再让客车上渡轮
        {
            if(busQueue.getHead()>i*10)break;//如果在该次间隔未排队的则仍在队列中
            busWaitTime+=i*10-busQueue.deQueue();//出队并统计客车等待时间
            busNum++;//统计上渡轮的客车数
        }
        if(busQueue.isEmpty())systemTime=i*10;//将系统时间拨至下次间隔起始处
        else systemTime=busQueue.getTail();//或拨至客车队尾到达时间
    }
}

#endif
