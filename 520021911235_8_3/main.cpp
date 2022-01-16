//设集合元素存储在一个数组中。试设计一个集合类，使用户能够通过运算符+ * -执行集合的交并差运算。设集合元素是无序存储的。
#include <iostream>
#include"set.h"
using namespace std;

int main()
{
    set<int> a,b;
    for(int i=1;i<10;i++)
    {
        a.insert(i);
        b.insert(i+5);
    }
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
    cout<<endl;
    cout<<"通过a+b实现交运算："<<a+b<<endl;
    cout<<"通过a*b实现并运算："<<a*b<<endl;
    cout<<"通过a-b实现补运算："<<a-b<<endl;

    return 0;
}
