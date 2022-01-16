#include <iostream>
#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
using namespace std;

template <class T>
class linkQueue;
template<class T>
class linkStack;

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
    void insert(const T&x,BinaryNode *&t);//����
    void remove(const T&x,BinaryNode *&t);//ɾ��
    bool find(const T&x,BinaryNode *t)const;//����


public:
    BinarySearchTree(BinaryNode*t=NULL){root=t;}
    ~BinarySearchTree(){makeEmpty(root);}
    void insert(const T&x){return insert(x,root);}//����
    void remove(const T&x){return remove(x,root);}//ɾ��
    bool find(const T&x)const{return find(x,root);}//����
    void levelOrder()const;

};

template<class T>
bool BinarySearchTree<T>::find(const T&x,BinaryNode *t)const//���ҵķǵݹ�ʵ��
{
    BinaryNode* tmp=t;
    while(tmp!=NULL&&tmp->data!=x)//�ҵ����ߵ��ս��
    {
        if(tmp->data>x)tmp=tmp->left;//���ݽ��ֵ��С�ƶ�ָ���λ��
        else tmp=tmp->right;
    }
    if(tmp==NULL)return false;//�ս�����δ�ҵ�
    else return true;
}
template<class T>
void BinarySearchTree<T>::insert(const T&x,BinaryNode *&t)//����ķǵݹ�ʵ��
{
    if(t==NULL)//����������
    {
        t=new BinaryNode(x);
        return;
    }

    BinaryNode* tmp=t;
    bool flag=true;//�ж��Ƿ���ɲ���
    while(flag)
    {
        if(tmp->data>x)//���ݽ��ֵ��С�ж�����������������������
        {
            if(tmp->left)tmp=tmp->left;//�ƶ�ָ�뵽�ʺϵĿս��
            else{tmp->left=new BinaryNode(x);flag=false;}//����
        }
        if(tmp->data<x)
        {
            if(tmp->right)tmp=tmp->right;
            else{tmp->right=new BinaryNode(x);flag=false;}
        }
    }
}
template<class T>
void BinarySearchTree<T>::remove(const T&x,BinaryNode *&t)//ɾ���ķǵݹ�ʵ��
{
    BinaryNode* tmp=t,*p,*s;//p������¼����㣬����ɾ��������
    while(tmp!=NULL&&tmp->data!=x)//����ֵΪx�Ľ���λ��
    {
        if(tmp->data>x)
        {p=tmp;tmp=tmp->left;}
        else
        {p=tmp;tmp=tmp->right;}
    }
    if(tmp==NULL)return;//δ�ҵ�
    if(tmp->left!=NULL&&tmp->right!=NULL)//�����������ӵĽ��ת��Ϊһ�������
    {
       s=tmp->right;//�����������ҵ���С��Ԫ�أ���û�����ӵĽ��
       p=tmp;
       while(s->left!=NULL){p=s;s=s->left;}
       tmp->data=s->data;
       tmp=s;//����λ��
    }
    if(p->right==tmp)p->right=(tmp->left!=NULL)?tmp->left:tmp->right;//Ϊp���Һ�����ı�pָ���Һ��ӵ�ָ��ʹ��ָ��tmp�ĺ��ӣ��޺�����ָ��NULL��
    else p->left=(tmp->left!=NULL)?tmp->left:tmp->right;//Ϊp������ͬ��
    delete tmp;//ɾ��
    tmp=NULL;
}
template<class T>
void BinarySearchTree<T>::makeEmpty(BinaryNode *&t)
{
    if(t==NULL)return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t=NULL;
}
template<class T>
void BinarySearchTree<T>::levelOrder()const
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
template<class T>
class linkStack//ջ������ʵ��
{
private:
    struct node
    {
        T data;
        node*next;
        node():next(NULL){}
        node(T const&x,node*N=NULL):data(x),next(N){}
    };
    node*top_p;
public:
    linkStack():top_p(NULL){}
    ~linkStack()
    {
        node*tmp;
        while(top_p!=NULL)
        {
            tmp=top_p;
            top_p=top_p->next;
            delete tmp;
        }
    }
    bool isEmpty(){return top_p==NULL;}
    void push(const T&x){top_p=new node(x,top_p);}
    T top(){return top_p->data;}
    T pop()
    {
        node*tmp=top_p;
        T x=top_p->data;
        top_p=top_p->next;
        delete tmp;
        return x;
    }
};
#endif

