//�ڶ�������binaryTree������һ�����ܣ�ͳ�ƶ���Ϊ2�Ľ�������
#include <iostream>
#include"binaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    tree.createTree('@');
    cout<<"����Ϊ2�Ľ�������"<<tree.countN2();
    return 0;
}
