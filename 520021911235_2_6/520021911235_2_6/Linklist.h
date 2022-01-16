#include <iostream>
#ifndef _Linklist_h
#define _Linklist_h
using namespace std;

template<class T>
class list
{
public:
    virtual void clear()=0;
    virtual void insert(int i,const T&x)=0;
    virtual void inverse()=0;
    virtual T visit(int i)const=0;
    virtual void tranverse()const=0;
    virtual ~list() {}
};

template<class T>
class sLinklist:public list<T>
{
private:
    struct node
    {
        T data;
        node *next;
        node(const T&x,node *n=NULL)
            {data=x;next=n;}
        node():next(NULL){}
        ~node(){}
    };

    node *head;
    int currentLength;
    node *move(int i)const;
public:
    sLinklist();
    ~sLinklist(){clear(); delete head;}

    void clear();
    void insert(int i,const T&x);
    void inverse();//��������ĺ���
    T visit(int i)const;
    void tranverse()const;
};

template<class T>
void sLinklist<T>::inverse()//��������
{
    node *p=head->next,*q,*m=head;//��������ָ��
    if(head->next==NULL||head->next->next==NULL)
        return;//Ϊ�ջ�ֻ��һ��Ԫ�أ�����ִ�����ò���
    while(p->next!=NULL)
    {
        q=p->next;
        p->next=m;//����
        m=p;
        p=q;
    }
    p->next=m;//�������һ��
    head->next->next=NULL;//�Ͽ���ͷ���֮�������
    head->next=q;//��ͷ�ڵ���ĩβ����
}
template<class T>
sLinklist<T>::sLinklist()
{
    head=new node;
    currentLength=0;
}
template<class T>
typename sLinklist<T>::node*sLinklist<T>::move(int i)const
{
    node*p=head;
    while(i-->=0)p=p->next;
    return p;
}
template<class T>
void sLinklist<T>::clear()
{
    node *p=head->next,*q;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    currentLength=0;
}
template<class T>
void sLinklist<T>::insert(int i,const T&x)
{
    node *p=move(i-1);
    p->next=new node(x,p->next);
    ++currentLength;
}
template<class T>
T sLinklist<T>::visit(int i)const
{
    return move(i)->data;
}
template<class T>
void sLinklist<T>::tranverse()const
{
    node *p=head->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

#endif
