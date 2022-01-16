//在二叉树类binaryTree中增加一个功能：统计度数为2的结点个数。
#include <iostream>
#include"binaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    tree.createTree('@');
    cout<<"度数为2的结点个数："<<tree.countN2();
    return 0;
}
