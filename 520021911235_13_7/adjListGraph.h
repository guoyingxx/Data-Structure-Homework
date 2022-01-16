#include <iostream>
#ifndef _adjListGraph_H
#define _adjListGraph_H

using namespace std;
template <class T>
class linkQueue;
template <class TypeOfVer,class TypeOfEdge>
class adjListGraph//�ڽӱ�ͼ��Ķ���
{
private:
    struct edgeNode
    {
        int end;
        TypeOfEdge weight;
        edgeNode* next;
        edgeNode(int x,TypeOfEdge w,edgeNode* n=NULL):end(x),weight(w),next(n){}
        ~edgeNode(){}
    };
    struct versNode
    {
        edgeNode* head;
        TypeOfVer ver;
        versNode(edgeNode*h=NULL):head(h){}
    };
    versNode *verList;
    int Vers,Edges;
    void find(int current,int M,int *visited,int start);//�����м�·��

public:
    adjListGraph(int vSize,const TypeOfVer d[]);
    ~adjListGraph();
    bool insert(int u,int v,TypeOfEdge w);
    bool remove(int u,int v);
    void find(TypeOfVer start,int M);//�����м�·��
};


#endif
