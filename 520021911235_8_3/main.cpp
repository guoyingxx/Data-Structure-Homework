//�輯��Ԫ�ش洢��һ�������С������һ�������࣬ʹ�û��ܹ�ͨ�������+ * -ִ�м��ϵĽ��������㡣�輯��Ԫ��������洢�ġ�
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
    cout<<"ͨ��a+bʵ�ֽ����㣺"<<a+b<<endl;
    cout<<"ͨ��a*bʵ�ֲ����㣺"<<a*b<<endl;
    cout<<"ͨ��a-bʵ�ֲ����㣺"<<a-b<<endl;

    return 0;
}
