//�ڶ��������������һ����Ա�������ҳ������е�i���Ԫ��
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;//һ�ñȽ�ƽ�����
    int a[9]={3,2,8,1,6,12,4,7,16};
    for(int i=0;i<9;i++)tree.insert(a[i]);
    cout<<"���������Ϊ��";
    tree.levelOrder();
    cout<<endl;
    cout<<"�����е�4���Ԫ��Ϊ��";
    cout<<tree.findIth(4);
    return 0;
}
