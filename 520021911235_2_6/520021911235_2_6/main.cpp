//6.�ڱ���ʵ�ֵĵ�������������һ�����ܣ����õ�ǰ�ĵ�����Ҫ��ʱ�临�Ӷ���O(N).
#include <iostream>
#include"Linklist.h"
using namespace std;

int main()
{
    sLinklist<int> list1;
    cout<<"����ʱ��һ��Ϊԭʼ���������ݣ��ڶ���Ϊ���ú���������"<<endl;
    for(int i=0;i<=20;i++)
    list1.insert(i,i);
    list1.tranverse();
    list1.inverse();//����
    list1.tranverse();

    return 0;
}
