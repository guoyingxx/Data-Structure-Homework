//���һ���㷨������������ȱ�����˼���ҳ���ָ��������������ΪM�����м�·����
//�������㷨�����ڽӱ��࣬���ڽӱ������ṩһ�����еĳ�Ա����find(start,M)��
#include <iostream>
#include"adjListGraph.h"
#include"adjListGraph.cpp"
using namespace std;

int main()
{
    int a[]={0,1,2,3,4};
    adjListGraph<int,int>graph2(3,a);//�Ƚϼ򵥵�ͼ
    graph2.insert(0,1,1);
    graph2.insert(2,0,1);
    graph2.insert(1,0,1);
    graph2.insert(2,1,1);
    graph2.insert(1,2,1);
    graph2.insert(0,2,1);
    cout<<"ͼһ��"<<endl;
    graph2.find(0,3);

    adjListGraph<int,int>graph(5,a);//����һ���ͼ
    graph.insert(0,1,1);//����ߣ����һ������ΪȨֵ
    graph.insert(2,0,1);
    graph.insert(1,3,1);
    graph.insert(2,3,1);
    graph.insert(2,4,1);
    graph.insert(3,2,1);
    graph.insert(3,4,2);//�˴�Ȩֵ��Ϊ2
    graph.insert(3,0,1);
    graph.insert(4,2,1);
    cout<<"ͼ��:(3,4��ȨֵΪ2)"<<endl;
    graph.find(0,4);
    graph.find(0,6);

    return 0;
}
