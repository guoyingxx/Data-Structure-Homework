//6.在本章实现的单链表类中增加一个功能，逆置当前的单链表，要求时间复杂度是O(N).
#include <iostream>
#include"Linklist.h"
using namespace std;

int main()
{
    sLinklist<int> list1;
    cout<<"测试时第一行为原始单链表数据，第二行为逆置后单链表数据"<<endl;
    for(int i=0;i<=20;i++)
    list1.insert(i,i);
    list1.tranverse();
    list1.inverse();//逆置
    list1.tranverse();

    return 0;
}
