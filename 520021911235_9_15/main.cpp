/*在本章所示的闭散列表类中增加一个自动重散列的功能。这个重散列包括以下功能:
    1.当数组中的活动元素超过数组元素的一半，即负载因子达到0.5，自动扩大数组空间；
    2.当数组中标志"被删除的"元素个数超过用户指定的值时(由构造函数设定)，重新散列；
*/
#include <iostream>
#include"closeHashTable.h"
using namespace std;

int main()
{
    closeHashTable <int>t;
    for(int i=1;i<21;i++)
        t.insert(i);
    cout<<"原散列表为(此处插入的活动元素超过数组空间一半，通过自动重散列扩大数组空间)："<<'\n';
    t.tranverse();
    cout<<'\n';
    for(int i=1;i<6;i++)
        t.remove(i);
    cout<<"删除前5个元素后为(此处删除元素超过设定值3，已进行自动重散列)："<<'\n';
    t.tranverse();

    return 0;
}
