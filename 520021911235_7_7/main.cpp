//7.��Ʋ�ʵ��һ��������С���ѵ����͵����ȼ����У�������Ԫ��Ϊ���ͣ���ֵԽС�����ȼ�Խ�ߡ�
//��������ʵ�ֶ��еĻ��������⣬����Ҫʵ�����й��ܡ�
//(1)int findMin(x):�ҳ����ȼ�ֵ����ָ��Ԫ��x����СԪ�أ������������±ꡣ
//(2)decreaseKey(i,value):����i���������ȼ�ֵ����value��
#include <iostream>
#include"priorityQueue.h"
using namespace std;

int main()
{
    int data[16]={3,6,7,12,8,21,14,15,37,18,24,23,33,18,17,26};
    priorityQueue<int>que(data,16);
    cout<<"���ȼ�����Ϊ��"<<endl;
    que.levelOrder();
    cout<<"���ȼ�ֵ����ָ��Ԫ��9����СԪ�ص��±�:"<<endl;
    cout<<que.findMin(9)<<endl;
    que.decreaseKey(4,7);
    cout<<"����4���������ȼ�ֵ��С7�����ȼ�����Ϊ��"<<endl;
    que.levelOrder();

    return 0;
}
