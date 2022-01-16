#include <iostream>
#ifndef _BinaryTree_h
#define _BinaryTree_h
using namespace std;

template <class T>
class linkQueue;

template<class T>
class BinaryTree
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
public:
    BinaryTree():root(NULL){}
    BinaryTree(const T&x){root=new Node(x);}
    ~BinaryTree(){clear(root);}
    bool isEmpty()const{return root==NULL;}
    void createTree(T flag);
    bool isCompleteTree()const;//判断二叉树是否是完全二叉树
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
    cout<<"输入根结点：";
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
bool BinaryTree<T>::isCompleteTree()const
{
    linkQueue<Node*>que;//利用队列进行非递归实现
    Node *tmp;
    que.enQueue(root);//根结点入队

    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        if(!tmp->left&&tmp->right) return false;//有右子树而无左子树一定不是完全二叉树
        if(tmp->right)//如果还有右子树则一定左右均有，将它们入队
        {
            que.enQueue(tmp->left);
            que.enQueue(tmp->right);
        }
        else//否则存在空缺
        {
            if(tmp->left)que.enQueue(tmp->left);//有左子树但空缺右子树将左子树入队
            break;//离开循环
        }
    }
    while(!que.isEmpty())//需要空缺项后均为空节点才为完全二叉树
    {
        tmp=que.deQueue();
        if(tmp->left||tmp->right)return false;
    }
    return true;
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

