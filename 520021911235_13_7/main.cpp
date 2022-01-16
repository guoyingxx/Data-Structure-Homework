//设计一个算法，按照深度优先遍历的思想找出从指定结点出发，长度为M的所有简单路径。
//并将此算法用于邻接表类，在邻接表类中提供一个公有的成员函数find(start,M)。
#include <iostream>
#include"adjListGraph.h"
#include"adjListGraph.cpp"
using namespace std;

int main()
{
    int a[]={0,1,2,3,4};
    adjListGraph<int,int>graph2(3,a);//比较简单的图
    graph2.insert(0,1,1);
    graph2.insert(2,0,1);
    graph2.insert(1,0,1);
    graph2.insert(2,1,1);
    graph2.insert(1,2,1);
    graph2.insert(0,2,1);
    cout<<"图一："<<endl;
    graph2.find(0,3);

    adjListGraph<int,int>graph(5,a);//复杂一点的图
    graph.insert(0,1,1);//插入边，最后一个参数为权值
    graph.insert(2,0,1);
    graph.insert(1,3,1);
    graph.insert(2,3,1);
    graph.insert(2,4,1);
    graph.insert(3,2,1);
    graph.insert(3,4,2);//此处权值设为2
    graph.insert(3,0,1);
    graph.insert(4,2,1);
    cout<<"图二:(3,4间权值为2)"<<endl;
    graph.find(0,4);
    graph.find(0,6);

    return 0;
}
