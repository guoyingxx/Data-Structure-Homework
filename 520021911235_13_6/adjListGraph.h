#include <iostream>
#ifndef _adjListGraph_H
#define _adjListGraph_H

using namespace std;
template <class T>
class linkQueue;
template <class TypeOfVer,class TypeOfEdge>
class adjListGraph//邻接表图类的定义
{
private:
    struct edgeNode
    {
        int end;
        edgeNode* next;
        edgeNode(int x,edgeNode* n=NULL):end(x),next(n){}
        ~edgeNode(){}
    };
    struct versNode
    {
        edgeNode* head;
        TypeOfVer ver;
        versNode(edgeNode*h=NULL):head(h){}
    };
    versNode *verList;
    int Vers,Edges;

public:
    adjListGraph(int vSize,const TypeOfVer d[]);
    ~adjListGraph();
    bool insert(int u,int v);
    bool remove(int u,int v);
    void topSort()const;//安排课程计划
};

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
    node *p=front;
    T value=front->data;

    front=front->next;
    if(front==NULL)rear=NULL;
    delete p;
    return value;
}
#endif
