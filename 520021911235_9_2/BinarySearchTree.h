#include <iostream>
#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
using namespace std;

template <class T>
class linkQueue;

template<class T>
class BinarySearchTree//�����������Ķ���
{
private:
    struct BinaryNode
    {
        T data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode():left(NULL),right(NULL){}
        BinaryNode(const T&x,BinaryNode*l=NULL,BinaryNode*r=NULL):data(x),left(l),right(r){}
        ~BinaryNode(){}
    };
    BinaryNode *root;

    void makeEmpty(BinaryNode *&t);
    void insert(const T&x,BinaryNode *&t);
    void remove(const T&x,BinaryNode *&t);
    bool find(const T&x,BinaryNode *t)const;
    void deleteLess(const T&x,BinaryNode *&t);//ɾ��С��ĳ��ָ��ֵ������Ԫ��
    void deleteGreater(const T&x,BinaryNode *&t);//ɾ������ĳ��ָ��ֵ������Ԫ��
    void deleteRange(const T&x1,const T&x2,BinaryNode *&t);//ɾ��ĳһָ����Χ�е�����Ԫ��

public:
    BinarySearchTree(BinaryNode*t=NULL){root=t;}
    ~BinarySearchTree(){makeEmpty(root);}
    void insert(const T&x){return insert(x,root);}
    void remove(const T&x){return remove(x,root);}
    bool find(const T&x)const{return find(x,root);}
    void deleteLess(const T&x){return deleteLess(x,root);}//ɾ��С��ĳ��ָ��ֵ������Ԫ��
    void deleteGreater(const T&x){return deleteGreater(x,root);}//ɾ������ĳ��ָ��ֵ������Ԫ��
    void deleteRange(const T&x1,const T&x2){return deleteRange(x1,x2,root);}//ɾ��ĳһָ����Χ�е�����Ԫ��
    void levelOrder()const;//ͨ����α���չʾ���

};
template<class T>
void BinarySearchTree<T>::makeEmpty(BinaryNode *&t)
{
    if(t==NULL)return;//�ݹ�ɾ��һ����
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t=NULL;
}
template<class T>
bool BinarySearchTree<T>::find(const T&x,BinaryNode *t)const
{
    if(t==NULL)return false;
    if(t->data==x)return true;
    else if(t->data>x)find(x,t->left);
    else if(t->data<x)find(x,t->right);
}
template<class T>
void BinarySearchTree<T>::insert(const T&x,BinaryNode *&t)
{
    if(t==NULL)t=new BinaryNode(x);
    else if(x<t->data)insert(x,t->left);
    else if(x>t->data)insert(x,t->right);
}
template<class T>
void BinarySearchTree<T>::remove(const T&x,BinaryNode *&t)
{
    if(t==NULL)return;
    if(x<t->data)remove(x,t->left);
    else if(x>t->data)remove(x,t->right);
    else if(t->left!=NULL&&t->right!=NULL)
    {
        BinaryNode *tmp=t->right;
        while(tmp->left!=NULL)tmp=tmp->left;
        t->data=tmp->data;
        remove(tmp->data,t->right);
    }
    else
    {
        BinaryNode *tmp=t;
        t=(t->left!=NULL)?t=t->left:t=t->right;
        delete tmp;
    }
}
template<class T>
void BinarySearchTree<T>::deleteLess(const T&x,BinaryNode *&t)//ɾ��С��ĳ��ָ��ֵ������Ԫ��
{
    if(t==NULL)return;
    if(t->data<x)//����ý��С��x
    {
        makeEmpty(t->left);//�ý����������ϵĽ���С��x��ֱ�����������
        remove(t->data,t);//��ɾ���ý��
         deleteLess(x,t);//�����ݹ�ɾ��ԭ��������С��x��Ԫ��
    }
    else deleteLess(x,t->left);//����ý�����x����С��x�Ľ��һ��������������
}
template<class T>
void BinarySearchTree<T>::deleteGreater(const T&x,BinaryNode *&t)//ɾ������ĳ��ָ��ֵ������Ԫ��
{
    if(t==NULL)return;
    if(t->data>x)//�ý�����x
    {
        makeEmpty(t->right);//�ý����������ϵĽ�������x��ֱ�����������
        remove(t->data,t);//��ɾ���ý��
        deleteGreater(x,t);//�����ݹ�ɾ��ԭ�������ϴ���x��Ԫ��
    }
    else deleteGreater(x,t->right);//����ý��С��x����С��x�Ľ��һ��������������
}
template<class T>
void BinarySearchTree<T>::deleteRange(const T&x1,const T&x2,BinaryNode *&t)//ɾ��ĳһָ����Χ�е�����Ԫ��
{
    if(t==NULL)return;
    if(x1<t->data&&x2>t->data)//����ý����ɾ����Χ(x1,x2)��
    {
        deleteGreater(x1,t->left);//������������ɾ������x1��Ԫ��
        deleteLess(x2,t->right);//������������ɾ��С��x2��Ԫ��
        remove(t->data,t);//ɾ���ý��
    }
    else if(t->data<=x1)deleteRange(x1,x2,t->right);//���ý����x1��࣬��÷�Χ�����������ϣ�����������ɾ��
    else if(t->data>=x2)deleteRange(x1,x2,t->left);//ͬ������������ɾ��
}
template<class T>
void BinarySearchTree<T>::levelOrder()const//��α���
{
    linkQueue<BinaryNode*>que;
    BinaryNode* tmp;
    que.enQueue(root);

    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<tmp->data<<" ";
        if(tmp->left)que.enQueue(tmp->left);
        if(tmp->right)que.enQueue(tmp->right);
    }
}

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
    node *p=front;
    T value=front->data;

    front=front->next;
    if(front==NULL)rear=NULL;
    delete p;
    return value;
}
#endif
