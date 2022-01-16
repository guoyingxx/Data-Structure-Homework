#include <iostream>
#ifndef _BinaryTree_h
#define _BinaryTree_h
using namespace std;

template<class T>
class linkStack;
template <class T>
class linkQueue;

template<class T>
class BinaryTree//二叉树的链接实现
{
private:
    struct Node
    {
        T data;
        Node *left,*right;
        Node():left(NULL),right(NULL){}
        Node(const T&x,Node *L=NULL,Node *R=NULL):data(x),left(L),right(R){}
        ~Node(){}
    };
    Node*root;

    void clear(Node*&t);
    int countN2(Node*n)const;//私有的统计度为2的结点个数函数
public:
    BinaryTree():root(NULL){}
    BinaryTree(const T&x){root=new Node(x);}
    ~BinaryTree(){clear(root);}
    bool isEmpty()const{return root==NULL;}
    void createTree(T flag);

    int countN2()const{return countN2(root);}//公有的统计度为2的结点个数函数


};
template<class T>
void BinaryTree<T>::clear(BinaryTree<T>::Node*&t)
{
    if(t==NULL)return;
    clear(t->left);
    clear(t->right);
    delete t;
    t=NULL;
}
template<class T>
void BinaryTree<T>::createTree(T flag)
{
    linkQueue<Node*>que;
    Node*tmp;
    T x,rdata,ldata;
    cout<<"请输入根结点：";
    cin>>x;
    root=new Node(x);
    que.enQueue(root);

    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<"\n输入"<<tmp->data<<"的两个儿子("<<flag<<"表示空结点)";
        cin>>ldata>>rdata;
        if(ldata!=flag)
            que.enQueue(tmp->left=new Node(ldata));
        if(rdata!=flag)
            que.enQueue(tmp->right=new Node(rdata));
    }
    cout<<"create completed!\n";
}
template<class T>
int BinaryTree<T>::countN2(Node*n)const//统计度为2的结点个数
{
    int num=0;//利用n0=n2+1统计n0个数获得n2个数
    linkStack<Node*>s;//利用栈进行非递归实现
    Node *current;

    if(isEmpty())return 0;//为空时结点个数为0
    s.push(root);
    while(!s.isEmpty())
    {
        current=s.pop();
        if(current->right!=NULL)s.push(current->right);
        if(current->left!=NULL)s.push(current->left);
        if(current->left==NULL&&current->right==NULL) num++;//若左右孩子均为空结点则该结点为叶子结点
    }
    return num-1;//返回n2=n0-1
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
