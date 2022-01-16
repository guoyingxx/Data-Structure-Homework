//在二叉树类binaryTree中增加一个功能：判断二叉树是否是完全二叉树。
#include <iostream>
#include"binaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    tree.createTree('@');
    if(tree.isCompleteTree())cout<<"输入的二叉树是完全二叉树";
    else cout<<"输入的二叉树不是完全二叉树";
    return 0;
}
