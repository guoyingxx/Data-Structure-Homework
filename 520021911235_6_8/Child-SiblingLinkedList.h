#include <iostream>
#ifndef _ChildSiblingLinkedList_h
#define _ChildSiblingLinkedList_h
using namespace std;
template <class T>
class linkQueue;

template <class T>
class ChildSiblingLinkedList//�����ֵ�����
{
private:
    struct node
    {
        T data;
        node *firstSon,*nextSibling;//����ָ��ָ������ֵܺ͵�һ������

        node():firstSon(NULL),nextSibling(NULL){}
        node(const T&x,node*F=NULL,node* N=NULL):data(x),firstSon(F),nextSibling(N){}
        ~node(){}
    };
    node *root;
    void clear(node*&t);
    void preOrder(node*t)const;//ǰ�����
    void postOrder(node*t)const;//�������

public:
    ChildSiblingLinkedList():root(NULL){}
    ChildSiblingLinkedList(const T&x){root=new node(x);}
    ~ChildSiblingLinkedList(){clear(root);}
    bool isEmpty()const{return root==NULL;}
    void createTree(T flag);

    void preOrder()const{cout<<"\nǰ�������";preOrder(root);}
    void postOrder()const{cout<<"\n���������";postOrder(root);}
    void levelOrder()const;//��α���
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
void ChildSiblingLinkedList<T>::createTree(T flag)//����
{
    linkQueue<node*>que;//���ö��е�����,���ݲ�α�����˼����н���
    node *tmp;
    T x,son,brother;
    cout<<"���������㣺";
    cin>>x;
    root=new node(x);
    que.enQueue(root);
    cout<<"("<<flag<<"��ʾ�ս��)"<<endl;

    while(!que.isEmpty())
    {
        tmp=que.deQueue();//���ӵ����нڵ㶼Ϊ��һ�����ӻ�����
        cout<<"������"<<tmp->data<<"�ĵ�һ������";
        cin>>son;
        if(son!=flag)
        {
            que.enQueue(tmp->firstSon=new node(son));
        }
        while(tmp!=root)//�����㲻�Ǹ�����������������ֵ�
        {
            cout<<"������"<<tmp->data<<"���ֵ�";
            cin>>brother;
            if(brother!=flag)
            {
                tmp->nextSibling=new node(brother);
                tmp=tmp->nextSibling;
                cout<<"������"<<tmp->data<<"�ĵ�һ������";//�������ֵܴ��ڵĵ�һ������
                cin>>son;
                if(son!=flag)
                {
                    que.enQueue(tmp->firstSon=new node(son));//����һ���������
                }
            }
            else break;
        }
    }
    cout<<"create completed!\n";
}

template <class T>
void ChildSiblingLinkedList<T>::preOrder(ChildSiblingLinkedList<T>::node *t)const//ǰ�����
{
    if(t==NULL)return;//�ݹ���ֹ����
    cout<<t->data;//������ýڵ��ֵ
    preOrder(t->firstSon);//�Խڵ�ĵ�һ�����ӽ���ǰ�����
    preOrder(t->nextSibling);//�Խڵ����һ���ֵܽ���ǰ�����
}
template <class T>
void ChildSiblingLinkedList<T>::postOrder(ChildSiblingLinkedList<T>::node *t)const//�������
{
    if(t==NULL)return;//�ݹ���ֹ����
    postOrder(t->firstSon);//���Ըý��Ϊ�����Ľ����б���
    cout<<t->data;//�ý��ĺ�����ȫ�������ʿ�������ý��
    postOrder(t->nextSibling);//�����ý����ֵܽ��
}
template <class T>
void ChildSiblingLinkedList<T>::levelOrder()const//��α���
{
    linkQueue<node*> que;//���ö��е�����
    node*tmp;
    que.enQueue(root);//�ֽ���������

    cout<<"\n��α�����";
    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<tmp->data;
        if(tmp->firstSon!=NULL)que.enQueue(tmp->firstSon);//������ڵĵ�һ�����ӽ�����
        while(tmp->nextSibling!=NULL)
        {
            tmp=tmp->nextSibling;
            cout<<tmp->data;//�������ֵܽ��
            if(tmp->firstSon!=NULL)que.enQueue(tmp->firstSon);//�����ֵܽ��Ĵ��ڵĵ�һ�����ӽ�����
        }

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
