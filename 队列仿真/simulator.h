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
    int customNum;
    int arrivelLow,arrivelHigh;
    int serviceTimeLow,serviceTimeHigh;
public:
    simulator();
    double avgWaitTime()const;

};
simulator::simulator()//���캯��
{
    cout<<"��������Ҫģ��˿���";
    cin>>customNum;
    cout<<"�����뵽��ʱ���������½�";
    cin>>arrivelLow>>arrivelHigh;
    cout<<"���������ʱ������½�";
    cin>>serviceTimeLow>>serviceTimeHigh;

    srand(time(NULL));//��ʼ�������������
}
double simulator::avgWaitTime()const//�������
{
    int totalWaitTime=0,nextDepartTime=0,futureArrivelTime=0;
    linkQueue<int>customQueue;//�ŶӶ���
    int currentNum=1;

    while(currentNum<customNum)
    {
        nextDepartTime+=serviceTimeLow+(serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);//���ɶ�Ӧ�뿪ʱ��

        while(futureArrivelTime<nextDepartTime)//��һ������ʱ��С���뿪ʱ��
        {
            if(futureArrivelTime!=0)customQueue.enQueue(futureArrivelTime);
            futureArrivelTime+=arrivelLow+(arrivelHigh-arrivelLow+1)*rand()/(RAND_MAX+1);
        }

        currentNum++;//����
        if(!customQueue.isEmpty())//������зǿգ��������Ŷӵȴ�
        {
            totalWaitTime+=nextDepartTime-customQueue.deQueue();//���ϵ�ǰ�������ĵȺ��ʱ��
        }

        else
        {
            nextDepartTime=futureArrivelTime;//��������ڵȴ����������ʱ�䲦����ǰ�������ĵ����ʱ��
            futureArrivelTime+=arrivelLow+(arrivelHigh-arrivelLow+1)*rand()/(RAND_MAX+1);//��������һ����ʱ��
        }
    }
    return double(totalWaitTime)/customNum;//����ƽ���ȴ�ʱ��
}


#endif

