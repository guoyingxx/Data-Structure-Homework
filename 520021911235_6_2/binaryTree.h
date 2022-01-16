#include <iostream>
#ifndef _BinaryTree_h
#define _BinaryTree_h
using namespace std;

template<class T>
class linkStack;
template <class T>
class linkQueue;

template<class T>
class BinaryTree//������������ʵ��
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
    int countN2(Node*n)const;//˽�е�ͳ�ƶ�Ϊ2�Ľ���������
public:
    BinaryTree():root(NULL){}
    BinaryTree(const T&x){root=new Node(x);}
    ~BinaryTree(){clear(root);}
    bool isEmpty()const{return root==NULL;}
    void createTree(T flag);

    int countN2()const{return countN2(root);}//���е�ͳ�ƶ�Ϊ2�Ľ���������


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
    cout<<"���������㣺";
    cin>>x;
    root=new Node(x);
    que.enQueue(root);

    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<"\n����"<<tmp->data<<"����������("<<flag<<"��ʾ�ս��)";
        cin>>ldata>>rdata;
        if(ldata!=flag)
            que.enQueue(tmp->left=new Node(ldata));
        if(rdata!=flag)
            que.enQueue(tmp->right=new Node(rdata));
    }
    cout<<"create completed!\n";
}
template<class T>
int BinaryTree<T>::countN2(Node*n)const//ͳ�ƶ�Ϊ2�Ľ�����
{
    int num=0;//����n0=n2+1ͳ��n0�������n2����
    linkStack<Node*>s;//����ջ���зǵݹ�ʵ��
    Node *current;

    if(isEmpty())return 0;//Ϊ��ʱ������Ϊ0
    s.push(root);
    while(!s.isEmpty())
    {
        current=s.pop();
        if(current->right!=NULL)s.push(current->right);
        if(current->left!=NULL)s.push(current->left);
        if(current->left==NULL&&current->right==NULL) num++;//�����Һ��Ӿ�Ϊ�ս����ý��ΪҶ�ӽ��
    }
    return num-1;//����n2=n0-1
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
