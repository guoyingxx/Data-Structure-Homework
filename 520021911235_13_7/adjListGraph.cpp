#include"adjListGraph.h"

template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph (int vSize,const TypeOfVer d[])
{
    Vers=vSize;
    Edges=0;
    verList=new versNode[Vers];
    for(int i=0;i<Vers;i++)
        verList[i].ver=d[i];
}
template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::~adjListGraph()
{
    edgeNode* p;
    for(int i=0;i<Vers;i++)
    {
        while((p=verList[i].head)!=NULL)
        {
            verList[i].head=p->next;
            delete p;
        }
    }
    delete []verList;
}
template <class TypeOfVer,class TypeOfEdge>
bool adjListGraph<TypeOfVer,TypeOfEdge>::insert(int u,int v,TypeOfEdge w)
{
    verList[u].head=new edgeNode(v,w,verList[u].head);
    ++Edges;
    return true;
}
template <class TypeOfVer,class TypeOfEdge>
bool adjListGraph<TypeOfVer,TypeOfEdge>::remove(int u,int v)
{
    edgeNode* p=verList[u].head,*q;
    if(p==NULL)return false;
    if(p->end==v)
    {
        verList[u].head=p->next;
        delete q;
        --Edges;
        return true;
    }
    while(p->next!=NULL&&p->next.end!=v)
    {
        p=p->next;
    }
    if(p==NULL)return false;
    q=p->next;
    p->next=q->next;
    delete q;
    --Edges;
    return true;
}

template <class TypeOfVer,class TypeOfEdge>//����
void adjListGraph<TypeOfVer,TypeOfEdge>::find(TypeOfVer start,int M)
{
    int *visited=new int[Vers];//���ڴ��·���ϵ���һ��㲢�ж��Ƿ��ѱ�����
    int i;
    for(i=0;i<Vers;i++)visited[i]=Vers;//���δ������
    cout<<"����Ϊ"<<M<<"�����м�·��Ϊ��"<<endl;
    for(i=0;i<Vers;i++)
    {
        if(verList[i].ver==start)
            find(i,M,visited,i);//�ҵ���Ӧ���
    }
}

template <class TypeOfVer,class TypeOfEdge>//˽��
void adjListGraph<TypeOfVer,TypeOfEdge>::find(int current,int M,int *visited,int s)
{
    edgeNode*p=verList[current].head;
    int i=s;

    if(M==0)//·�������ѴﵽM
    {
        while(true)//�����·��
        {
            cout<<verList[i].ver<<"-";//�����ǰ���
            if(visited[visited[i]]==Vers||visited[i]==s)//�ж���һ����Ƿ�Ϊ���һ�����
            {
                cout<<verList[visited[i]].ver<<'\n';
                break;
            }
            else i=visited[i];//����·������һ���
        }
    }
    if(M>0)//·������δ�ﵽM
    {
        while(p!=NULL)
        {
            if(visited[p->end]==Vers||(p->end==s&&M-p->weight==0))//�жϸý���ܷ񱻷���
            {
                visited[current]=p->end;//��¼����һ���ʽ��
                find(p->end,M-p->weight,visited,s);//�ݹ飬�������
                visited[current]=Vers;//�ݹ鷵��ʱɾ����ǰ���ķ��ʼ�¼������Ӱ������·��������
            }
            p=p->next;//������һ���
        }
    }
}
