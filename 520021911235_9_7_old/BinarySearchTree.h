#include <iostream>
#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
using namespace std;

template <class T>
class linkQueue;

template<class T>
class BinarySearchTree
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
    T findIth(int i,BinaryNode *t);//找出集合中第i大的元素
    bool find(const T&x,BinaryNode *t)const;
    int size(BinaryNode *t)const;//统计以结点为根的树的大小

public:
    BinarySearchTree(BinaryNode*t=NULL){root=t;}
    ~BinarySearchTree(){makeEmpty(root);}
    void insert(const T&x){return insert(x,root);}
    void remove(const T&x){return remove(x,root);}
    bool find(const T&x)const{return find(x,root);}
    void levelOrder()const;
    T findIth(int i){return findIth(i,root);}//找出集合中第i大的元素

};
template<class T>
int BinarySearchTree<T>::size(BinaryNode *t)const//统计以结点为根的树的大小
{
    if(t==NULL)return 0;
    else return size(t->left)+size(t->right)+1;//递归进行计算
}

template<class T>
T BinarySearchTree<T>::findIth(int i,BinaryNode *t)
{
    if(t==NULL)return false;//未找到
    if(size(t->right)==i-1)//找到t为第i大的元素
        return t->data;
    if(size(t->right)>=i)//第i大的元素在t右子树上
        return findIth(i,t->right);//直接在右子树上找即可
    else //在左子树上
        return findIth(i-1-size(t->right),t->left);//将根结点和其右子树都计算在内后再在左子树上查找
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
#endif

