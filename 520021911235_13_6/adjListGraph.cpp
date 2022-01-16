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
bool adjListGraph<TypeOfVer,TypeOfEdge>::insert(int u,int v)
{
    verList[u].head=new edgeNode(v,verList[u].head);
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

template <class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::topSort()const//利用拓扑排序进行课程计划安排
{
    linkQueue<int>q;
    edgeNode*p;
    int current,*inDegree=new int[Vers],num=1;
    for(int i=0;i<Vers;i++) inDegree[i]=0;
    for(int i=0;i<Vers;i++)//计算入度
    {
        p=verList[i].head;
        while(p!=NULL)
        {
            ++inDegree[p->end];
            p=p->next;
        }
    }
    for(int i=0;i<Vers;i++)//度为0的结点入队
    {
        if(inDegree[i]==0)
            q.enQueue(i);
    }
    q.enQueue(Vers);//标记每个学期终止
    cout<<"第"<<num<<"学期的计划课程为:";
    while(!q.isEmpty())
    {
        current=q.deQueue();
        if(current==Vers)
        {
            if(!q.isEmpty())q.enQueue(Vers);//标记下个学期终止
            else break;//全部学习完成
            num++;//学期数
            cout<<endl;
            cout<<"第"<<num<<"学期的计划课程为:";
        }
        else
        {
            cout<<verList[current].ver<<'\t';
            p=verList[current].head;
            while(p!=NULL)
            {
                if(--inDegree[p->end]==0)q.enQueue(p->end);//将所有达到条件的课程入队，安排至下一学期
                p=p->next;
            }
        }
    }
}

