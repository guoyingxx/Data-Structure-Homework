#include <iostream>
#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
using namespace std;

template <class T>
class linkQueue;

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
    void insert(const T&x,BinaryNode *&t);
    void remove(const T&x,BinaryNode *&t);
    bool find(const T&x,BinaryNode *t)const;
    void deleteLess(const T&x,BinaryNode *&t);//删除小于某个指定值的所有元素
    void deleteGreater(const T&x,BinaryNode *&t);//删除大于某个指定值的所有元素
    void deleteRange(const T&x1,const T&x2,BinaryNode *&t);//删除某一指定范围中的所有元素

public:
    BinarySearchTree(BinaryNode*t=NULL){root=t;}
    ~BinarySearchTree(){makeEmpty(root);}
    void insert(const T&x){return insert(x,root);}
    void remove(const T&x){return remove(x,root);}
    bool find(const T&x)const{return find(x,root);}
    void deleteLess(const T&x){return deleteLess(x,root);}//删除小于某个指定值的所有元素
    void deleteGreater(const T&x){return deleteGreater(x,root);}//删除大于某个指定值的所有元素
    void deleteRange(const T&x1,const T&x2){return deleteRange(x1,x2,root);}//删除某一指定范围中的所有元素
    void levelOrder()const;//通过层次遍历展示结果

};
template<class T>
void BinarySearchTree<T>::makeEmpty(BinaryNode *&t)
{
    if(t==NULL)return;//递归删除一棵树
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
void BinarySearchTree<T>::deleteLess(const T&x,BinaryNode *&t)//删除小于某个指定值的所有元素
{
    if(t==NULL)return;
    if(t->data<x)//如果该结点小于x
    {
        makeEmpty(t->left);//该结点的左子树上的结点均小于x，直接清空左子树
        remove(t->data,t);//并删除该结点
         deleteLess(x,t);//继续递归删除原右子树上小于x的元素
    }
    else deleteLess(x,t->left);//如果该结点大于x，则小于x的结点一定在其左子树上
}
template<class T>
void BinarySearchTree<T>::deleteGreater(const T&x,BinaryNode *&t)//删除大于某个指定值的所有元素
{
    if(t==NULL)return;
    if(t->data>x)//该结点大于x
    {
        makeEmpty(t->right);//该结点的右子树上的结点均大于x，直接清空右子树
        remove(t->data,t);//并删除该结点
        deleteGreater(x,t);//继续递归删除原左子树上大于x的元素
    }
    else deleteGreater(x,t->right);//如果该结点小于x，则小于x的结点一定在其右子树上
}
template<class T>
void BinarySearchTree<T>::deleteRange(const T&x1,const T&x2,BinaryNode *&t)//删除某一指定范围中的所有元素
{
    if(t==NULL)return;
    if(x1<t->data&&x2>t->data)//如果该结点在删除范围(x1,x2)内
    {
        deleteGreater(x1,t->left);//在其左子树上删除大于x1的元素
        deleteLess(x2,t->right);//在其右子树上删除小于x2的元素
        remove(t->data,t);//删除该结点
    }
    else if(t->data<=x1)deleteRange(x1,x2,t->right);//若该结点在x1左侧，则该范围在其右子树上，在右子树上删除
    else if(t->data>=x2)deleteRange(x1,x2,t->left);//同理在左子树上删除
}
template<class T>
void BinarySearchTree<T>::levelOrder()const//层次遍历
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
