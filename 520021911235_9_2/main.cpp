//�ڶ����������������3����Ա������
//ɾ��С��ĳ��ָ��ֵ������Ԫ�أ�ɾ������ĳ��ָ��ֵ������Ԫ�أ�ɾ��ĳһָ����Χ�е�����Ԫ��
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;
    int a[12]={3,2,8,1,6,12,4,16,7,5,9,10};//һ�ñȽ�ƽ�����
    for(int i=0;i<12;i++)tree.insert(a[i]);
    cout<<"�����Ķ��������Ϊ(��α���)��";
    tree.levelOrder();
    cout<<endl;
    tree.deleteLess(3);
    cout<<"ɾ��С��3������Ԫ�غ�Ϊ��";
    tree.levelOrder();
    cout<<endl;
    tree.deleteGreater(8);
    cout<<"ɾ������8������Ԫ�غ�Ϊ��";
    tree.levelOrder();
    cout<<endl;
    cout<<"ɾ��(3,7)��Χ������Ԫ�غ�Ϊ��";
    tree.deleteRange(3,7);
    tree.levelOrder();
    cout<<endl;
    return 0;
}
