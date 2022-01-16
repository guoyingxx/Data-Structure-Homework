//在本章实现的顺序表类中增加连接两个线性表的功能。
//顺序表类的用户可以使用表达式C=A+B将线性表A和B归并后存入线性表C。
#include <iostream>
#include"seqList.h"
using namespace std;


int main()
{
    cout<<"测试时第一二行分别为线性表A和B，第三行为归并后的线性表C"<<endl;
    seqList<int> A(5),B(5);
    for(int i=0;i<5;i++)
        A.insert(i,i);
    cout<<"A:";
    A.tranverse();
    for(int i=0;i<5;i++)
        B.insert(i,i+5);
    cout<<"B:";
    B.tranverse();

    seqList<int> C;
    C=A+B;//使用表达式C=A+B将线性表A和B归并后存入线性表C
    cout<<"C:";
    C.tranverse();
    return 0;
}
