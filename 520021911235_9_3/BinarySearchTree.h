#include <iostream>
#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
using namespace std;

template <class T>
class linkQueue;
template<class T>
class linkStack;

template<class T>
class BinarySearchTree//二叉查找树类的定义
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
    void insert(const T&x,BinaryNode *&t);//插入
    void remove(const T&x,BinaryNode *&t);//删除
    bool find(const T&x,BinaryNode *t)const;//查找


public:
    BinarySearchTree(BinaryNode*t=NULL){root=t;}
    ~BinarySearchTree(){makeEmpty(root);}
    void insert(const T&x){return insert(x,root);}//插入
    void remove(const T&x){return remove(x,root);}//删除
    bool find(const T&x)const{return find(x,root);}//查找
    void levelOrder()const;

};

template<class T>
bool BinarySearchTree<T>::find(const T&x,BinaryNode *t)const//查找的非递归实现
{
    BinaryNode* tmp=t;
    while(tmp!=NULL&&tmp->data!=x)//找到或者到空结点
    {
        if(tmp->data>x)tmp=tmp->left;//根据结点值大小移动指针的位置
        else tmp=tmp->right;
    }
    if(tmp==NULL)return false;//空结点代表未找到
    else return true;
}
template<class T>
void BinarySearchTree<T>::insert(const T&x,BinaryNode *&t)//插入的非递归实现
{
    if(t==NULL)//在树根插入
    {
        t=new BinaryNode(x);
        return;
    }

    BinaryNode* tmp=t;
    bool flag=true;//判断是否完成插入
    while(flag)
    {
        if(tmp->data>x)//根据结点值大小判断在左子树还是右子树插入
        {
            if(tmp->left)tmp=tmp->left;//移动指针到适合的空结点
            else{tmp->left=new BinaryNode(x);flag=false;}//插入
        }
        if(tmp->data<x)
        {
            if(tmp->right)tmp=tmp->right;
            else{tmp->right=new BinaryNode(x);flag=false;}
        }
    }
}
template<class T>
void BinarySearchTree<T>::remove(const T&x,BinaryNode *&t)//删除的非递归实现
{
    BinaryNode* tmp=t,*p,*s;//p用来记录父结点，便于删除后连接
    while(tmp!=NULL&&tmp->data!=x)//查找值为x的结点的位置
    {
        if(tmp->data>x)
        {p=tmp;tmp=tmp->left;}
        else
        {p=tmp;tmp=tmp->right;}
    }
    if(tmp==NULL)return;//未找到
    if(tmp->left!=NULL&&tmp->right!=NULL)//将有两个孩子的结点转化为一个的情况
    {
       s=tmp->right;//在右子树上找到最小的元素，即没有左孩子的结点
       p=tmp;
       while(s->left!=NULL){p=s;s=s->left;}
       tmp->data=s->data;
       tmp=s;//交换位置
    }
    if(p->right==tmp)p->right=(tmp->left!=NULL)?tmp->left:tmp->right;//为p的右孩子则改变p指向右孩子的指针使其指向tmp的孩子（无孩子则指向NULL）
    else p->left=(tmp->left!=NULL)?tmp->left:tmp->right;//为p的左孩子同理
    delete tmp;//删除
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
template<class T>
class linkStack//栈的链接实现
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

