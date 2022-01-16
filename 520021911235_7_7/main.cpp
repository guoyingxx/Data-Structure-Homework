//7.设计并实现一个基于最小化堆的整型的优先级队列，即队列元素为整型，数值越小，优先级越高。
//这个类除了实现队列的基本操作外，还需要实现下列功能。
//(1)int findMin(x):找出优先级值大于指定元素x的最小元素，并返回它的下标。
//(2)decreaseKey(i,value):将第i个结点的优先级值减少value。
#include <iostream>
#include"priorityQueue.h"
using namespace std;

int main()
{
    int data[16]={3,6,7,12,8,21,14,15,37,18,24,23,33,18,17,26};
    priorityQueue<int>que(data,16);
    cout<<"优先级队列为："<<endl;
    que.levelOrder();
    cout<<"优先级值大于指定元素9的最小元素的下标:"<<endl;
    cout<<que.findMin(9)<<endl;
    que.decreaseKey(4,7);
    cout<<"将第4个结点的优先级值减小7后优先级队列为："<<endl;
    que.levelOrder();

    return 0;
}
