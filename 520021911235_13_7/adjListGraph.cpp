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

template <class TypeOfVer,class TypeOfEdge>//公有
void adjListGraph<TypeOfVer,TypeOfEdge>::find(TypeOfVer start,int M)
{
    int *visited=new int[Vers];//用于存放路径上的下一结点并判断是否已被访问
    int i;
    for(i=0;i<Vers;i++)visited[i]=Vers;//标记未被访问
    cout<<"长度为"<<M<<"的所有简单路径为："<<endl;
    for(i=0;i<Vers;i++)
    {
        if(verList[i].ver==start)
            find(i,M,visited,i);//找到对应结点
    }
}

template <class TypeOfVer,class TypeOfEdge>//私有
void adjListGraph<TypeOfVer,TypeOfEdge>::find(int current,int M,int *visited,int s)
{
    edgeNode*p=verList[current].head;
    int i=s;

    if(M==0)//路径长度已达到M
    {
        while(true)//输出该路径
        {
            cout<<verList[i].ver<<"-";//输出当前结点
            if(visited[visited[i]]==Vers||visited[i]==s)//判断下一结点是否为最后一个结点
            {
                cout<<verList[visited[i]].ver<<'\n';
                break;
            }
            else i=visited[i];//访问路径上下一结点
        }
    }
    if(M>0)//路径长度未达到M
    {
        while(p!=NULL)
        {
            if(visited[p->end]==Vers||(p->end==s&&M-p->weight==0))//判断该结点能否被访问
            {
                visited[current]=p->end;//记录其下一访问结点
                find(p->end,M-p->weight,visited,s);//递归，深度优先
                visited[current]=Vers;//递归返回时删除当前结点的访问记录，以免影响其他路径的生成
            }
            p=p->next;//访问下一结点
        }
    }
}
