//�ڶ�������binaryTree������һ�����ܣ��ж϶������Ƿ�����ȫ��������
#include <iostream>
#include"binaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    tree.createTree('@');
    if(tree.isCompleteTree())cout<<"����Ķ���������ȫ������";
    else cout<<"����Ķ�����������ȫ������";
    return 0;
}
