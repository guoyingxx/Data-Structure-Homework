#include <iostream>
#ifndef _ChildSiblingLinkedList_h
#define _ChildSiblingLinkedList_h
using namespace std;
template <class T>
class linkQueue;

template <class T>
class ChildSiblingLinkedList//孩子兄弟链类
{
private:
    struct node
    {
        T data;
        node *firstSon,*nextSibling;//两个指针指向结点的兄弟和第一个儿子

        node():firstSon(NULL),nextSibling(NULL){}
        node(const T&x,node*F=NULL,node* N=NULL):data(x),firstSon(F),nextSibling(N){}
        ~node(){}
    };
    node *root;
    void clear(node*&t);
    void preOrder(node*t)const;//前序遍历
    void postOrder(node*t)const;//后序遍历

public:
    ChildSiblingLinkedList():root(NULL){}
    ChildSiblingLinkedList(const T&x){root=new node(x);}
    ~ChildSiblingLinkedList(){clear(root);}
    bool isEmpty()const{return root==NULL;}
    void createTree(T flag);

    void preOrder()const{cout<<"\n前序遍历：";preOrder(root);}
    void postOrder()const{cout<<"\n后序遍历：";postOrder(root);}
    void levelOrder()const;//层次遍历
};

template <class T>
void ChildSiblingLinkedList<T>::clear(ChildSiblingLinkedList<T>::node *&t)
{
    if(t==NULL)return;
    clear(t->firstSon);
    clear(t->nextSibling);
    delete t;
    t=NULL;
}
template <class T>
void ChildSiblingLinkedList<T>::createTree(T flag)//建树
{
    linkQueue<node*>que;//利用队列的特性,依据层次遍历的思想进行建树
    node *tmp;
    T x,son,brother;
    cout<<"请输入根结点：";
    cin>>x;
    root=new node(x);
    que.enQueue(root);
    cout<<"("<<flag<<"表示空结点)"<<endl;

    while(!que.isEmpty())
    {
        tmp=que.deQueue();//出队的所有节点都为第一个孩子或根结点
        cout<<"请输入"<<tmp->data<<"的第一个儿子";
        cin>>son;
        if(son!=flag)
        {
            que.enQueue(tmp->firstSon=new node(son));
        }
        while(tmp!=root)//如果结点不是根结点则生成其所有兄弟
        {
            cout<<"请输入"<<tmp->data<<"的兄弟";
            cin>>brother;
            if(brother!=flag)
            {
                tmp->nextSibling=new node(brother);
                tmp=tmp->nextSibling;
                cout<<"请输入"<<tmp->data<<"的第一个儿子";//并生成兄弟存在的第一个孩子
                cin>>son;
                if(son!=flag)
                {
                    que.enQueue(tmp->firstSon=new node(son));//将第一个孩子入队
                }
            }
            else break;
        }
    }
    cout<<"create completed!\n";
}

template <class T>
void ChildSiblingLinkedList<T>::preOrder(ChildSiblingLinkedList<T>::node *t)const//前序遍历
{
    if(t==NULL)return;//递归终止条件
    cout<<t->data;//先输出该节点的值
    preOrder(t->firstSon);//对节点的第一个儿子进行前序遍历
    preOrder(t->nextSibling);//对节点的下一个兄弟进行前序遍历
}
template <class T>
void ChildSiblingLinkedList<T>::postOrder(ChildSiblingLinkedList<T>::node *t)const//后序遍历
{
    if(t==NULL)return;//递归终止条件
    postOrder(t->firstSon);//对以该结点为根结点的结点进行遍历
    cout<<t->data;//该结点的孩子已全部遍历故可以输出该结点
    postOrder(t->nextSibling);//遍历该结点的兄弟结点
}
template <class T>
void ChildSiblingLinkedList<T>::levelOrder()const//层次遍历
{
    linkQueue<node*> que;//利用队列的性质
    node*tmp;
    que.enQueue(root);//现将根结点入队

    cout<<"\n层次遍历：";
    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<tmp->data;
        if(tmp->firstSon!=NULL)que.enQueue(tmp->firstSon);//将其存在的第一个孩子结点入队
        while(tmp->nextSibling!=NULL)
        {
            tmp=tmp->nextSibling;
            cout<<tmp->data;//遍历其兄弟结点
            if(tmp->firstSon!=NULL)que.enQueue(tmp->firstSon);//并将兄弟结点的存在的第一个孩子结点入队
        }

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
