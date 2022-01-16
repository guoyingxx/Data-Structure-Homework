#include<iostream>
#include<cstdlib>
#include<ctime>
#ifndef _simulator_h
#define _simulator_h
using namespace std;

template <class T>
class linkQueue//���е�����ʵ��
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
            else cout<<"����Ϊ��";
            }
        T getTail(){
            if(!isEmpty())return rear->data;
            else cout<<"����Ϊ��";
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
    if(front==NULL)cout<<"����Ϊ��";
    node *p=front;
    T value=front->data;

    front=front->next;
    if(front==NULL)rear=NULL;
    delete p;
    return value;
}

class simulator//ģ����Ķ���
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
simulator::simulator()//���캯��
{
    cout<<"��������Ҫģ�����ʱ��/min";
    cin>>totalTime;
    cout<<"������ͳ�����ʱ���������½�";
    cin>>busArrLow>>busArrHigh;
    cout<<"�������������ʱ���������½�";
    cin>>vanArrLow>>vanArrHigh;

    srand(time(NULL));//��ʼ�������������
}
void simulator::avgWaitTime()//�������
{
    int systemTime=0,num;
    linkQueue<int>busQueue,vanQueue;//�ͳ��ͻ������ŶӶ���
    busNum=0;busWaitTime=0;
    vanNum=0;vanWaitTime=0;

    for(int i=1;i<totalTime/10;i++)
    {
        while(systemTime<=i*10)//���ɸôζ��ֵ������м����ŶӵĿͳ�
        {
            systemTime+=busArrLow+(busArrHigh-busArrLow+1)*rand()/(RAND_MAX+1);
            busQueue.enQueue(systemTime);
        }
        if(vanQueue.isEmpty())systemTime=(i-1)*10;//����ϵͳʱ��
        else systemTime=vanQueue.getTail();//����������β����ʱ��
        while(systemTime<=i*10)//���ɸôζ��ֵ������м����ŶӵĻ���
        {
            systemTime+=vanArrLow+(vanArrHigh-vanArrLow+1)*rand()/(RAND_MAX+1);
            vanQueue.enQueue(systemTime);
        }

        for(num=0;num<8&&!busQueue.isEmpty();num++)//���ÿͳ��϶���
        {
            if(busQueue.getHead()>i*10)break;//����ڸôμ��δ�Ŷӵ������ڶ�����
            busWaitTime+=i*10-busQueue.deQueue();//���Ӳ�ͳ�ƿͳ��ȴ�ʱ��
            busNum++;//ͳ���϶��ֵĿͳ���
        }
        for(;num<10&&!vanQueue.isEmpty();num++)//���û����϶���
        {
            if(vanQueue.getHead()>i*10)break;//����ڸôμ��δ�Ŷӵ������ڶ�����
            vanWaitTime+=i*10-vanQueue.deQueue();//���Ӳ�ͳ�ƻ����ȴ�ʱ��
            vanNum++;//ͳ���ϻ��ֵĿͳ���
        }
        for(;num<10&&!busQueue.isEmpty();num++)//�����п��������ÿͳ��϶���
        {
            if(busQueue.getHead()>i*10)break;//����ڸôμ��δ�Ŷӵ������ڶ�����
            busWaitTime+=i*10-busQueue.deQueue();//���Ӳ�ͳ�ƿͳ��ȴ�ʱ��
            busNum++;//ͳ���϶��ֵĿͳ���
        }
        if(busQueue.isEmpty())systemTime=i*10;//��ϵͳʱ�䲦���´μ����ʼ��
        else systemTime=busQueue.getTail();//�����ͳ���β����ʱ��
    }
}

#endif
